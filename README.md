![FreaksTimer](http://www.elecfreaks.com/wiki/images/a/a0/Freakstimer.png)

# FreaksTimer

Do you like to build your own pomodoro timer ? ElecFreaks has built a great but cheap programmable Arduino (Leonardo compatible w/ ATmega32U4) device sold here: [FreaksTimer](http://www.elecfreaks.com/estore/freakstimer.html). We at MakeHub Taiwan try to make it more useful and easy to extend by rewriting the whole firmware.

Currently there are two sketches:

- PromodoroTimer -- MakeHub completely rewrote the whole firwmare sketch. The code is shorter, more clear, and easier for further improvements. And we think it's perfect to be used as a pomodoro timer with the [Pomodoro Technique](http://pomodorotechnique.com). It depends only 1 libarary - TimerOne. You could download it from the menu option "Manage Libraries" in Arduino IDE, or just checkout the most recent version here: [TimerOne](https://github.com/PaulStoffregen/TimerOne)

- sketch_dec07a -- The original firmware sketch comes with the device. You must compile it with the specific r11 version of TimerOne library. (could be downloaded here: https://code.google.com/archive/p/arduino-timerone/downloads)

## Features

- Use Timer1 to generate ticks. No delay used except nixie tube display maintenance in the main loop.

- Use an external interrupt handler to deal with the encoder.

- Supports Base-16 to count down up to 255 minutes (enable BASE_16 definition then recompile).

- Remember the last setting of minutes to count down. (Pause in the counting down process WON'T affect it except for encoder events)
