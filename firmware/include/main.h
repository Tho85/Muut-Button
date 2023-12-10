#ifndef __main_h__
#define __main_h__

#include "usb-mute-device.h"

#include <Bounce2.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include "config.h"

UsbMuteDevice UsbMute = UsbMuteDevice();

void setup();
void loop();

#ifdef __cplusplus
extern "C"{
#endif
  uchar usbFunctionSetup(uchar data[8]) {
    usbRequest_t *rq = (usbRequest_t *)((void *)data);

    if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS &&
        (rq->bRequest == USBRQ_HID_SET_REPORT))
      return USB_NO_MSG;

    return 0;
  }

  uchar usbFunctionWrite(uchar *data, uchar len) {
    UsbMute.setReport(data, len);
    return 1;
  }
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __main_h__
