#ifndef __usb_mute_device_h__
#define __usb_mute_device_h__

#include <Arduino.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "usbdrv.h"

#include "usb-hid-descriptor.h"

class UsbMuteDevice {
public:
  UsbMuteDevice();

  // Delay with usbPoll
  void delay(long milli);

  // Setter methods: Set bits and send incoming report (peripheral to host)
  void setHook(bool state);
  void setMute(bool state);
  void setDrop(bool state);

  // Getter methods: Get bits from outgoing report (host to peripheral)
  bool getOffHookLED();
  bool getMuteLED();

  // Public method used in usbFunctionSetup to fill receiving buffer (host to
  // peripheral)
  void setReport(uchar *data, uchar len);

private:
  void toggleReportBit(uchar pos, bool state);
  void sendReport();

  // buffer for input HID reports (peripheral => host).
  uchar reportBuffer[2] = { REPORT_ID_TEL, 0x00 };
  // buffer for output HID reports (host => peripheral)
  uchar setReportBuffer[2];
};

#endif // __usb_mute_device_h__
