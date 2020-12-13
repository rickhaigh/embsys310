EMBSYS 310 - AU20
ASSIGNMENT 08
Goal
The goals for the assignment this week:
1. Explore the use of PWM on our STM32L475 Discovery board.
Problems:
1. PWM
a. Study the tutorial: https://www.waveshare.com/wiki/STM32CubeMX_Tutorial_Series:_PWM
b. Use the STM32CubeMx similar to what’s described in the tutorial to generate the code that connects one of the PWM channels to one of the user LEDs for our STM32 Discovery Board.
c. Modify the code generated like the tutorial in order to control the LED blinking and brightness.
d. Create a video demonstrating the brightness of the LED changing overtime.
e. Submit your video along with your entire IAR project to your GitHub.
f. Set a break point inside the interrupt and capture a snapshot of the stack once inside the interrupt and LR value. Explain where the values that are stored on the stack are coming from when the Handler is invoked. And what is the value in the LR?
Hint: Refer to the STM32L475 Reference Manual RM0351 for details on TIMERs and PWM.
Also, see the MXCube diagram below for mapping the LEDs to the Timers.

What to turn in and how:
- Check in all your homework in your repo under the folder “assignment08”.
- Your folder should contain the following:
o Turn in your entire project.
o Turn in your video showing the brightness of the LED changing overtime.
- Submit a link to your GitHub repo assignment:
o Ex: “https://github.com/<account_id>/embsys310/assignment08”