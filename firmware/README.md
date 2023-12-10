# Muut Button firmware

A firmware for ATtiny85 microcontrollers that can mute/unmute and hang up calls in video conferencing sofware.

## Features

The firmware emulates the following usages according to the USB HID specification (see [HID Usage Tables](https://usb.org/sites/default/files/hut1_4.pdf)):

| Page name        | Page ID | Usage name  | Usage ID |
| ---------------- | ------- | ----------- | -------- |
| LED              | `0x08`  | Mute        | `0x09`   |
| LED              | `0x08`  | Off-Hook    | `0x17`   |
| Telephony Device | `0x0B`  | Hook Switch | `0x20`   |
| Telephony Device | `0x0B`  | Drop        | `0x26`   |
| Telephony Device | `0x0B`  | Phone Mute  | `0x2F`   |

## Getting Started

### Prerequisites

Software:

* [PlatformIO](https://platform.io)
* [V-USB](https://github.com/obdev/v-usb)

### Installation

* Install [PlatformIO](https://platform.io)
* Clone this repository, `cd firmware/`
* Configure firmware
  * Generate your own config file: `cp include/config.h.example include/config.h`
  * Edit `include/config.h` to suit your needs (see comments there for further description)
* Flash firmware
  * `pio run -t upload`
  * Plug in the device within 60 seconds

### Usage

* Attach device via USB
* Configure video conferencing software to use the device for call controls:
  * [Google Meet](https://support.google.com/meet/answer/12562325?hl=en)

## License

See [LICENSE.md](LICENSE.md)

## Authors

* [Thomas Hollstegge](https://github.com/Tho85)

## Acknowledgments

* Inspired by [Digispark Keyboard](https://github.com/digistump/DigisparkArduinoIntegration/tree/master/libraries/DigisparkKeyboard)
