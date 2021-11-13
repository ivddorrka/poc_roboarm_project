# Robot Manipulator (ARM) project

## Done by:
* [Shevchuk Bohdan](https://github.com/shevdan)
 
* [Brovchenko Yaroslav](https://github.com/firstgenius)

* [Kuzmina Daria](https://github.com/ivddorrka)

## Tech Parts

> The project will be made using PSoC microcontroller, as a base board. 

> Currently the work is at the stage of controlling a stepper motor 28byj-48 via PSoC4. The tech side of it can be seen on the next photo: 

![Screenshot](img/system.jpg)

> The stepper motor is being connected to the stepper motor driver:

![Screenshot](img/for_stepper.jpg)

> Via which the stepper is connected to the PSoC. 

## Usage

> The PSoC is being programmed via the PSoC Creator. In order not to make this repo too heavy we've uploaded only the main.c file which is the "logic" for now. 

> A, B, C, D - are digital output pins on the PSoC board which connect IN1, IN2, IN3, IN4 from the stepper motor driver.

> So if you-d like to use this project and try it out - check out the main.c file.

###### IMPORTANT!

> There's a math.h include being used. In order to use it simply follow this steps: 
> In Creator go to Project -> Build Settings -> Linker -> General. Add "m" (without the quotes) into Additional Libraries.

###### About the code 

> Running this code will make motor will move 90 degree outer clockwise (direction = 1) and then after a short delay 90 degree clockwise (direction = -1)

> There's a short video how it looks like 

![caption](img/video_mute.gif)
