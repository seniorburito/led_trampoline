# LED trampoline

![Jumping on the tramp](../assets/jumping.gif?raw=true)

Checkout my instructable where I explain everything step-by-step [here](https://www.instructables.com/id/Interactive-Neopixel-Trampoline/)

The trampoline works on a simple circuit shown below. I bought an exercise tramplone from walmart and put Neopixel LEDs on it. Neopixel LEDs are individually addressable so you can add fun patterns here. The trampoline came with a calorimeter. I opened it up and repurposed it to detect jumps and inform the arduino when to change colors. 

![Schematic](../assets/Schematic.png?raw=true)

There two .ino files here:
* check_leds.ino
* led_trampoline.ino

As you wire the LEDs, check that they are working using the check_leds code

Once everything is wired use the led_trampoline.ino code 

# Features to be added:

* More patterns

* Sound

* Calorie count and display