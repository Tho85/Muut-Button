# Muut Button case and electronics assembly

## Overview

The case consists of three 3D printed parts. From bottom to top:

  * The **base**: This is where the ATtiny85 development board will be mounted
  * The **stand**: This is the middle body which will hold the LED ring and MX switch
  * The **cap**: This is where you press.

## Assembly instructions

### 1. 3D print the case

I did print mine in [white PLA](https://www.dasfilament.de/filament-spulen/pla-1-75-mm/349/pla-filament-1-75-mm-tonweiss-matt?c=11), although any material should do fine.

Printing tips for the **cap**:

* Print the cap **upside down** so that you do not need any support
* Print the cap with **100% infill**, or otherwise the infill pattern might shine through the top when illuminated by the LED ring
* Print at least the middle part with a **reduced speed** so that the connector to the MX switch will be precise

Printing tips for the **stand**:

* Print the stand as it is, with **support** coming in from the bottom. It is more important to have a smooth surface at the top where you will attach the LED ring later.

---

### 2. Prepare and attach NeoPixel LED ring to the stand

* Solder three short wires (~ 5 cm) to the `GND`, `PWR` and `IN` connectors
* Stick the three wires through the small holes in the stand's top
* Fixate the LED ring with some hot glue

---

### 3. Prepare and attach MX switch to the stand

* Solder two short wires (~ 5 cm) to the pins of the switch
* Yes, they are tiny, so don't resign...
* Stick the MX switch through the stand's top

---

### 4. Solder component wires to the ATtiny85 board

* _After_ putting the components into place, solder the wires to the ATtiny85 board

  | Component | Component pin | ATtiny85 board pin  |
  | --------- | ------------- | ------------------- |
  | LED ring  | `GND`         | `GND` *)            |
  | LED ring  | `PWR`         | `VIN` (**not** 5V!) |
  | LED ring  | `IN`          | `PB0`               |
  | MX switch | Pin 1         | `GND` *)            |
  | MX switch | Pin 2         | `PB2`               |

  *) Two wires need to be soldered into the single `GND` hole. If you did not read this before doing so, you might also think about soldering the MX switch pin to a different `PBx` pin and pulling that one to `GND` in software. You might want to try though which of the pins actually works and doesn't interfer with the USB communication.

---

### 5. Prepare and attach ATtiny85 development board to the base

* Melt down the two threaded inserts into the base
* Attach the ATtiny85 development board with two M2x4 screws

---

### 6. Snap-fit everything together

* Click the base into place
* Attach the cap to the switch. Please bear in mind that the cap can only be mounted in two directions (the connector will only rotate by 180° and not by 90°). Choose the orientation according to your taste.
* Attach Micro USB cable through the connector hole

---

### 7. Optional: Foam rubber pad

* Cut out a round shape of thin foam rubber
* Attach with some strong double-faced adhesive tape to the bottom of the base

---

### 8. Done!
