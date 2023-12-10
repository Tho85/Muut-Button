#include "usb-mute-device.h"

UsbMuteDevice::UsbMuteDevice () {
  cli();
  usbDeviceDisconnect();
  _delay_ms(250);
  usbDeviceConnect();

  usbInit();

  sei();
}

// Delay with usbPoll
void UsbMuteDevice::delay(long milli) {
  unsigned long last = millis();
  while (milli > 0) {
    unsigned long now = millis();
    milli -= now - last;
    last = now;
    usbPoll();
  }
}

// Setter methods: Set bits and send incoming report (peripheral to host)
// 7 6 5 4 3 2 1 0  Bit
//           | | \- Hook
//           | \--- Mute
//           \----- Drop
void UsbMuteDevice::setHook(bool state) {
  toggleReportBit(0, state);
}

void UsbMuteDevice::setMute(bool state) {
  toggleReportBit(1, state);
}

void UsbMuteDevice::setDrop(bool state) {
  toggleReportBit(2, state);
}

// Getter methods: Get bits from outgoing report (host to peripheral)
// 7 6 5 4 3 2 1 0  Bit
//             | \- Off-Hook LED
//             \--- Mute LED
bool UsbMuteDevice::getOffHookLED() {
  return setReportBuffer[1] & 0x01;
}

bool UsbMuteDevice::getMuteLED() {
  return setReportBuffer[1] & 0x02;
}

// Public method used in usbFunctionSetup to fill receiving buffer (host to
// peripheral)
void UsbMuteDevice::setReport(uchar *data, uchar len) {
  // Ignore reports other than 0x02
  if (data[0] == REPORT_ID_LED && len == 2)
    // memcpy(setReportBuffer, data, len);
    setReportBuffer[1] = data[1];
}

void UsbMuteDevice::toggleReportBit(uchar pos, bool state) {
  if (state)
    reportBuffer[1] |= (1 << pos);
  else
    reportBuffer[1] &= ~(1 << pos);

  sendReport();
}

void UsbMuteDevice::sendReport() {
  while (!usbInterruptIsReady()) {
    usbPoll();
    _delay_ms(5);
  }

  usbSetInterrupt(reportBuffer, sizeof(reportBuffer));
}
