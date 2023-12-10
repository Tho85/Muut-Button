# Muut Button

A hardware button to control the mute state in video conferencing calls

![demo](images/demo.gif)

## Overview

This project consists of the following parts:

* [`firwmare`](firmware/): ATtiny85 firmware that emulates a USB HID Telephony device
* [`case`](case/): 3D printed case

## Features

* Mute/unmute video call on button press
* Show current mute/unmute state via RGB LED ring or builtin LED
* Optional: Push-to-talk
* Optional: Hold to drop call

## Requirements

### Hardware

* Development board: [ATtiny85 Micro USB Development Board](https://www.aliexpress.com/item/3256805913780170.html)
* Switch: e.g. [CHERRY MX Brown](https://www.cherrymx.de/cherry-mx/mx-original/mx-brown.html)
* RGB LED ring (optional): [Adafruit NeoPixel Ring - 12x](https://www.adafruit.com/product/1643)
* Case: (3D printed case)[case/], see (`case/README.md`)[case/README.md]

### Software

* See [`firmware/`](firmware/) folder

## License

* Firmware: See [`firmware/LICENSE.md`](firmware/LICENSE.md)
* Case: See [`case/LICENSE.md`](case/LICENSE.md)

## Authors

* [Thomas Hollstegge](https://github.com/Tho85)
