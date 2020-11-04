# Assignment03

1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate.

**assignment03/main-blinky.c**

2. Use the XOR bit wise operator to toggle the LED.

**assignment03/main-blinky_xor.c**

3. Morse Code is considered a sequence of binaries. Please read about Morse Code and share the following findings:

a. What is Morse Code?

**Morse code is a telecomunication method that uses sequences of long and short pulses to encode alpha numeric characters, A-Z and 0-9.  The dot duration is the basic measure of time in the system.  Timing between letters in a word, timing between words, timing of dots and dashes all play a role in how easy it is to communicate with morse code.  Slight changes in the timing can create phrases that have different meanings.  Different mediums can be used to transmit the information such as electric current, radio waves, visible light, or sound waves.  To increase the efficiency of encoding, Morse code was designed so that the length of each symbol is approximately inverse to the frequency of occurrence of the character that it represents in text of the English language.**

b. Who developed Morse Code?

**Samuel Morse is the inventer of the telegraph and he also developed morse code**

4. Using the International Code below, please write a small program to present your first name with Morse Code using the user LED on our B-L475E-IOT01A1 evaluation board.

**assignment03/main-morse_code.c**

**scope capture of led drive signal**

![](/assignment03/scope_morse_code_rick.png)

**video of morse code on LED**

**/assignment03/assignment03_morse_code.MOV**

https://youtu.be/XXQdULSHz00

5. Use the STM32CubeMx tool to generate the boiler plate code for controlling LED1 & LED2

**assignment03/main-stm32cube_blinky.c**
