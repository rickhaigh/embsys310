# EMBSYS 310 - AU20
# ASSIGNMENT 07
## Goal
### The goals for the assignment this week:
1. Practice setting up a user-defined vector table.
2. Practice dealing with interrupts and the use of the SysTick timer.
3. Practice generating and looking thru the map file.
## Problems:
1. Starting from the blinking LED code that you created using the CMSIS definitions:
    
    a. Add the files “stm32l475xx.h” & “stm32l4xx_it.h” to the folder where “main.c” is saved. You could get these files from our “Code” folder from our canvas site.
    
    b. Define your own vector table as we did during the class.
    
    c. Setup the SysTick timer to trigger an interrupt every 1ms.
    
    **Two functions in main.c setup and handle the SysTick timer: SysTick_Initialize() and SysTick_Handler()**

    **1ms time reference is determined by (SYS_CLOCK_HZ-1)/1000 = 1ms event**
    
    d. Modify the delay() function to be able to accept an input variable indicating the number of milliseconds: void delay(uint32_t delayInMilliseconds)

    **delay_ms function takes a number of milliseconds as the argument and compares this value to the global g_ms_tick which keeps track of the number of ms since it was reset by the delay_ms function**
    
    e. Implement the delay() function to be accurate to one millisecond count (Hint: rely on the SysTick interrupt handler to decrement a global variable used by the delay() function)
2. Generate the map file for your program and provide details on:
   
    **assignment07\blinky_cmsis.map**

    a. How much total ROM your program is occupying?
   
    **376 bytes + 82 bytes = 458 bytes**

    b. How much total RAM your program is using?
   
    **8196 bytes, with the stack set to 0x2000 (8192)**
    
    **0x4 bytes were used for the global g_ms_tick int**

    c. What part of your program is using the most ROM?
   
    **code memory, 376 bytes**

    d. What part of your program is using the most RAM?
   
    **stack is consuming almost all of the ram used by this program (all but 4bytes)**

3. Bonus: Is there anything that can be done to optimize the usage of ROM or RAM resources? Explain any options.
   
   **Reducing the stack size appears to be a practical way to reduce ram usage.  Reducing worked fine at 64bytes, but became flaky at 32bytes**

   **Increasing optimization did not appear to have any impact on ram usage, but did slightly change ROM usage**
## What to turn in and how:
- Check in all your homework in your repo under the folder “assignment07”.
- Your folder should contain the following:

    o Turn in your source code files only (for example: main.c, …etc.) and any other files that you have authored.

    **All files are located in assignment07 directory**
    
    **main.c**
    
    **delay.h & delay.c**

    **startup_stm32l475xx.c** 

    o Turn in answers to questions in markdown file format.
    **assignment07/assignment07.md**

- Submit a link to your GitHub repo assignment:

    https://github.com/rickhaigh/embsys310/blob/main/assignment07