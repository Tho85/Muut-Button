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

Hardware:

* Development board: [ATtiny85 Micro USB Development Board](https://www.aliexpress.com/item/3256805913780170.html)
* Or any other ATtiny85 development board where USB communication is handled by the ATtiny85 itself, and not by some additional USB-to-UART controller (CP2102, CH340, etc.)

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
* Make sure user has read/write access to the raw USB device:
  * Either drop [`udev rules file`](doc/98-muut.rules) to `/etc/udev/rules.d/`, issue a `sudo udevadm control --reload-rules` and re-plug device (recommended)
  * Or try manually: `sudo chmod 0666 /dev/hidrawX`

### Usage

* Attach device via USB
* Configure video conferencing software to use the device for call controls:
  * [Google Meet](https://support.google.com/meet/answer/12562325?hl=en)

### Advanced usage

If your development board does not already come pre-flashed with it, I highly recommend the [micronucleus bootloader](https://github.com/micronucleus/micronucleus). It adds support for firmware flashing without a dedicated programmer.

By default, the bootloader always starts and waits for up to 6 seconds after plugging in the device before starting the actual firmware. You can improve this behavior by flashing an optimized version of micronucleus as provided in the [`doc/micronucleus`](doc/micronucleus/) folder. The modified configuration only starts into bootloader mode if the button is pressed while plugging in the device.

Please check the [micronucleus repository](https://github.com/micronucleus/micronucleus) for more information on how to flash the optimized bootloader. Hint: micronucleus can update itself via their provided CLI tool.

## License

See [LICENSE.md](LICENSE.md)

## Authors

* [Thomas Hollstegge](https://github.com/Tho85)

## Acknowledgments

* Inspired by [Digispark Keyboard](https://github.com/digistump/DigisparkArduinoIntegration/tree/master/libraries/DigisparkKeyboard)
* Powered by the [micronucleus bootloader](https://github.com/micronucleus/micronucleus)
* Only possible thanks to [V-USB](https://github.com/obdev/v-usb)
