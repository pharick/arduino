# arduino

Eight Arduino sketches (C++ `.ino`) from an introductory microcontroller course, written in November 2019. The `mshp` folder is the course label; each sketch is a single self-contained file for an Arduino Uno-class board. The pin assignments are declared as `const byte` constants at the top of every sketch.

## What it covers

| Folder | Topic |
|---|---|
| `mshp/1-led` | two LEDs blinking in antiphase; non-blocking timing with `millis()` |
| `mshp/2-button` | two buttons drive a 0-3 counter shown on three LEDs; edge detection by comparing with the previous reading plus a 200 ms timer debounce |
| `mshp/3-analog` | "breathing" LED: PWM via `analogWrite`, direction flips at the 0/255 bounds |
| `mshp/4-led-speed` | two potentiometers (`analogRead` + `map()`) set the fade period (100-2000 ms) and peak brightness |
| `mshp/5-segments` | two-digit 7-segment display driven directly from 10 pins, multiplexed at 1 ms per digit, counting 0-99 |
| `mshp/6-shift` | one 7-segment digit through a 74HC595 shift register with `shiftOut()`; glyphs stored as a 10-byte bit table |
| `mshp/7-rgb-led` | RGB LED cycling through the hue wheel: a 0-1535 hue value split into six 256-step zones mapped to R/G/B duty cycles |
| `mshp/8-photo` | photoresistor reading smoothed with a 4-sample moving average and printed to Serial |

## Notable exercises

- `mshp/5-segments/5-segments.ino`: two independent `millis()` timers in `loop()` - one advances the counter every second, the other switches the active digit every millisecond - so the display is multiplexed without ever blocking. `segWrite()` is a per-digit `switch` table over the eight segment pins.
- `mshp/6-shift/6-shift.ino`: the same display problem solved with a shift register; the segment patterns become a `byte symbols[10]` table and one `shiftOut()` call, replacing eighty `digitalWrite` lines.
- `mshp/7-rgb-led/7-rgb-led.ino`: `rgbWrite(hue)` implements a hue-to-RGB ramp by zone (`hue / 256`) and offset (`hue % 256`), stepping every 10 ms.
- `mshp/2-button/2-button.ino`: button handling that only counts a rising edge (`prev_state != state`) and ignores repeats within 200 ms.

## Running

There are no build files. Open a sketch in the Arduino IDE, select the board and port, and upload. `3-analog`, `4-led-speed` and `8-photo` print to the serial monitor at 9600 baud.

## Notes

- Every sketch avoids `delay()` and uses `millis()` timers instead, so `loop()` keeps polling inputs while outputs animate.
- Early learning code, kept as a record: 8 files, about 390 lines.
