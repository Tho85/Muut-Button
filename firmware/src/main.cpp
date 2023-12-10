#include "main.h"

Adafruit_NeoPixel leds(NUM_LEDS, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);
Bounce2::Button muteButton = Bounce2::Button();

bool localMuteState = false;

#ifdef ENABLE_PUSH_TO_TALK
bool pttActive = false;
bool lastPttActive = false;
#endif

bool lastRemoteMuteState = false;
bool remoteMuteState = false;

bool lastRemoteCallState = false;
bool remoteCallState = false;

const PROGMEM uint32_t colorBlack = 0x000000;
const PROGMEM uint32_t colorRed = 0xFF0000;
const PROGMEM uint32_t colorGreen = 0x00FF00;
uint32_t currentColor = colorBlack;

#ifdef ENABLE_HOLD_TO_DROP
bool holdToDrop = false;
#endif

#if defined(ENABLE_IDLE_RAINBOW) || defined(ENABLE_UNMUTED_RAINBOW)
bool enableRainbow = false;
#endif

void setup() {
#ifdef ENABLE_BUILTIN_LED
  pinMode(BUILTIN_LED_PIN, OUTPUT);
  digitalWrite(BUILTIN_LED_PIN, LOW);
#endif

  muteButton.attach(MUTE_BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(MUTE_BUTTON_PIN, HIGH);
  muteButton.interval(20);
  muteButton.setPressedState(LOW);

#if defined(ENABLE_IDLE_RAINBOW) || defined(ENABLE_UNMUTED_RAINBOW)
  enableRainbow = muteButton.read() == LOW;
#endif

  leds.begin();
  leds.clear();
  leds.show();
  leds.setBrightness(RGB_LED_BRIGHTNESS);
}

void toggleMuteState() {
  localMuteState = !localMuteState;
  UsbMute.setMute(localMuteState);
}

void displayRainbow() {
  uint16_t hue = ((millis() * 65535) / RAINBOW_DURATION) % 65535;
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds.setPixelColor(i, leds.ColorHSV(hue + (i * 65535) / NUM_LEDS, 255, 200));
  }
}
void loop() {
  lastRemoteCallState = remoteCallState;
  remoteCallState = UsbMute.getMuteLED();

  lastRemoteMuteState = remoteMuteState;
  remoteMuteState = UsbMute.getOffHookLED();

#ifdef ENABLE_BUILTIN_LED
  digitalWrite(BUILTIN_LED_PIN, remoteMuteState ? HIGH : LOW);
#endif

  if (remoteCallState != lastRemoteCallState || remoteMuteState != lastRemoteMuteState) {
    leds.setBrightness(RGB_LED_BRIGHTNESS);
    if (remoteCallState)
      currentColor = remoteMuteState ? colorRed : colorGreen;
    else
      currentColor = colorBlack;

    leds.fill(currentColor);
  }

#ifdef ENABLE_UNMUTED_RAINBOW
  if (enableRainbow && remoteCallState && !remoteMuteState)
    displayRainbow();
#endif

  muteButton.update();

#ifdef ENABLE_HOLD_TO_DROP
  if (muteButton.released()) {
#else
  if (muteButton.pressed()) {
#endif
    toggleMuteState();
  }

#ifdef ENABLE_HOLD_TO_DROP
  if (muteButton.read() == LOW) {
    unsigned long currentDuration = muteButton.currentDuration();
    int brightness = 255 - ((currentDuration * 255) / HOLD_TO_DROP_DURATION);
    leds.setBrightness(max(min(brightness, 255), 0) * RGB_LED_BRIGHTNESS / 255);

    if (currentDuration > HOLD_TO_DROP_DURATION) {
      holdToDrop = true;
      UsbMute.setDrop(true);
    }
  }

  if (muteButton.released() && holdToDrop) {
    UsbMute.setDrop(false);
    holdToDrop = false;
  }
#endif

#ifdef ENABLE_PUSH_TO_TALK
  if (muteButton.released() && pttActive)
    toggleMuteState();

  pttActive = muteButton.read() == LOW && muteButton.currentDuration() > PTT_TRIGGER_DURATION;

  if (pttActive) {
#ifdef PTT_EFFECT_ROTATING_LIGHT
    leds.clear();
    int idx = (millis() / (PTT_EFFECT_ROTATING_LIGHT_DURATION / NUM_LEDS)) % NUM_LEDS;
    for (int i = idx; i < idx + NUM_LEDS / 4; i++) {
      leds.setPixelColor(i % NUM_LEDS, currentColor);
      leds.setPixelColor((i + NUM_LEDS/2) % NUM_LEDS, currentColor);
    }
#endif

#ifdef PTT_EFFECT_PULSE
    int brightnessTwo = (millis() / (PTT_EFFECT_PULSE_DURATION * 2 / 512)) % 512;
    int brightness = min(brightnessTwo, 511 - brightnessTwo);
    // There is a calculation error in the two lines above, leading to a visible
    // black flash, because brightness is obviously > 255. Manually limit to
    // interval between 0 and 255.
    leds.setBrightness(max(min(brightness, 255), 1));
#endif
  }

  lastPttActive = pttActive;
#endif

#ifdef ENABLE_IDLE_RAINBOW
  if (enableRainbow && !remoteCallState)
    displayRainbow();
#endif

  leds.show();
  UsbMute.delay(20);
}
