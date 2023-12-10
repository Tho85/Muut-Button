#include "usb-hid-descriptor.h"

#include <avr/pgmspace.h>

const PROGMEM char usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH] = { /* USB report descriptor */
  // Use IDs from telephony page
  0x05, 0x0b,      // USAGE_PAGE (Telephony Devices)
  0x09, 0x05,      // USAGE (Headset)
  0xa1, 0x01,      // COLLECTION (Application)

  // Report 1: Switches
  0x85, REPORT_ID_TEL, //   REPORT_ID (1)
  0x25, 0x01,      //   LOGICAL_MAXIMUM (1)
  0x15, 0x00,      //   LOGICAL_MINIMUM (0)
  0x75, 0x01,      //   REPORT_SIZE (1)
  0x09, 0x20,      //   USAGE (Hook Switch)
  0x09, 0x2f,      //   USAGE (Phone Mute)
  0x09, 0x26,      //   USAGE (Drop)
  0x95, 0x02,      //   REPORT_COUNT (2)
  0x81, 0x02,      //   INPUT (Data,Var,Abs) => Real data bits
  0x95, 0x06,      //   REPORT_COUNT (6)
  0x81, 0x03,      //   INPUT (Cnst,Var,Abs) => Stuff with zero bits

  // Report 2: LEDs
  0x85, REPORT_ID_LED, //   REPORT_ID (2)
  0x05, 0x08,      //   USAGE_PAGE (LEDs)
  0x09, 0x09,      //   USAGE (Mute)
  0x09, 0x17,      //   USAGE (Off-Hook)
  0x95, 0x02,      //   REPORT_COUNT (2)
  0x91, 0x02,      //   OUTPUT (Data,Var,Abs) => Real data bits
  0x95, 0x06,      //   REPORT_COUNT (6)
  0x91, 0x03,      //   OUTPUT (Cnst,Var,Abs) => Stuff with zero bits

  0xc0,          // END_COLLECTION
};
