# Muut Button

A hardware button to control the mute state in video conferencing calls.

## Overview

This firmware emulates a USB HID Telephony device with buttons and status LEDs. When attaching a hardware button, it can be used to mute/unmute and hang up calls in video conferencing software. The built-in LED (or an optional RGB LED ring) visualizes the current mute/unmute/call state.

The firmware presents itself as a generic HID device to the host PC and can be used in video conferencing software like Google Meet without the need for additional software, extensions etc.

## Features

* Mute/unmute video call on button press
* Also works while video call is in background window
* Show current mute/unmute state via RGB LED ring or builtin LED
* Correctly shows mute state when muted by other participant
* Optional: Push-to-talk
* Optional: Hold to drop call

## Demo

![demo](images/demo.gif)

## Requirements

### Hardware

* Development board: [ATtiny85 Micro USB Development Board](https://www.aliexpress.com/item/3256805913780170.html)
* Switch: e.g. [CHERRY MX Brown](https://www.cherrymx.de/cherry-mx/mx-original/mx-brown.html)
* RGB LED ring (optional): [Adafruit NeoPixel Ring - 12x](https://www.adafruit.com/product/1643)
* Case: [3D printed case](case/), see [`case/`](case/) folder

### Software

* See [`firmware/`](firmware/) folder

## License

* Firmware: See [`firmware/LICENSE.md`](firmware/LICENSE.md)
* Case: See [`case/LICENSE.md`](case/LICENSE.md)

## Authors

* [Thomas Hollstegge](https://github.com/Tho85)
