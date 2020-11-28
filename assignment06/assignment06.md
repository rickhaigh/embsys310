# EMBSYS 310 - AU20

# ASSIGNMENT 06

## Goal
The goals for the assignment this week:
1. Practice the use of the Cortex Microcontroller Software Interface Standard (CMSIS).
2. Gain more practice with the Cortex-M4 assembly language.

## Problems:
1. Use the CMSIS to implement the code to blink the user LED1 (PA5) on the STM32L475 board.
   
    a. Create a new project.

    **-assignment06/blinky_cmsis/**
   
    b. Create a main.c file and add it to the project.

    **-assignment06/blinky_cmsis/main.c**
   
    c. Add the files “stm32l475xx.h” and “system_stm32l4xx.h” to the folder on your drive where “main.c” is saved. You should be able to get these files thru STM32CubeMX, or you could find them under the “Code” folder in our canvas site.

    **-done**
   
    d. Enable use of CMSIS in project options settings.

    **-done**
      
    e. Implement toggling of LED1 using the CMSIS data structures.

    **-done**
   
2. Convert the blinking led program into assembly code.

    a. Download the zip file “Module07_Assignment06_Problem2_Starter_Files.zip” from canvas. Use the skeleton files 
    (main.c, user_led.s, and delay.s) inside that zip file.

    **-done**
   
    b. Create a new project and add the skeleton files to that project.

    **-done** 

    c. Make sure to setup the project to connect to your board (follow instructions form Module_02 if you forgot how to do that).

    **-done**

    d. Implement the function control_user_led1 in assembly:

        i. The function takes as input the desired led state (0 == OFF, 1 == ON) and the duration for holding that state.

    **-assignment06/user_led.s**

        ii. The function returns void.

    e. Implement the function delay in assembly:

    **-assignment06/delay.s**

        i. The function takes as input an integer value.

        ii. The function will decrement the value until it reaches 0.

        iii. The function returns void.

    f. Call the “control_user_led1” & “delay” functions from a while loop inside the main function.

    **I integrated the delay() call into the control_user_led function rather than in the while loop since the control_user_led1 function had a duration parameter**

    g. For any C code, use only data types defined in the “stdint.h” file.

## Hints:
    a. Start with your simple LED1 code that made use of the peripheral registers.
    b. Replace the delay function with the one you implemented in assembly first.
    c. Once the delay works in assembly, implement control_user_led1 function next.