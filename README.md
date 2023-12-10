# Muut Button

A hardware button to control the mute state in video conferencing calls.

![Muut Button image](images/red.jpg)

## Overview

The device emulates a USB HID Telephony device with buttons and status LEDs. It can be used to mute/unmute and hang up calls in video conferencing software. The built-in LED (or an optional RGB LED ring) visualizes the current mute/unmute/call state. No additional software or browser extensions required.

Successfully tested with Google Meet in Google Chrome. Firefox does not work because it does not implement the WebHID API. Other video conferencing solutions (MS Teams, Skype, ...) might work as well.

## Features

* Mute/unmute video call on button press
* Also works while video call is in background window
* Shows current mute/unmute state via RGB LED ring or builtin LED
* Correctly shows mute state when muted by other participants
* Optional: Push-to-talk
* Optional: Hold to drop call

## Demo

![Muut Button demo](images/demo.gif)

## Requirements

### Hardware

* Development board: [ATtiny85 Micro USB Development Board](https://www.aliexpress.com/item/3256805913780170.html)
* Switch: e.g. [CHERRY MX Brown](https://www.cherrymx.de/cherry-mx/mx-original/mx-brown.html)
* RGB LED ring (optional): [Adafruit NeoPixel Ring - 12x](https://www.adafruit.com/product/1643)
* Case + accessories: [3D printed case](case/), see [`case/`](case/) folder

### Software

* See [`firmware/`](firmware/) folder

## License

* Firmware: See [`firmware/LICENSE.md`](firmware/LICENSE.md)
* Case: See [`case/LICENSE.md`](case/LICENSE.md)

## Authors

* [Thomas Hollstegge](https://github.com/Tho85)
