# Assignment2 Questions and Answers
## 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.

a) What is the value of the “counter” from the “Locals” window?

**Value = 0x80000000 (-2147483648)**

b) What is the value of the “counter” in the “Registers” window?

**Value = 0x80000000**

c) Please note down if the N and/or V flags are set in the APSR register. And explain why.

**N = 1 (Negative)**
**V = 1 (Overflow)**
**The reason the N and V flags are set is that we went from the largest positive value of 0x7FFFFFFF and added 1 which caused the overflow and set the negative flag, making the number the largest negative number possible**

## 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”
a) What happens to the value of “counter” in the “Locals” window?

**Value starts at -1 then increments to 0**

b) Please note down if the N and/or V flags are set in the APSR register. And explain why.

**N = 0**
**V = 0**
**Neither N or V flags are set after incrementing from -1 to 0 The N flag is not set because the value is no longer negative and the V flag is not set because there was not an overflow during the addition

## 3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?

**Value = 2147483648, type is recognized as unsigned in in Locals window**

b) Please note down if the N and/or V flags are set in the APSR register. And explain why.

**N = 1**
**V = 1**
**Both the N and V flags are set.  It does not appear that IAR is checking the type of int and assumes it is a signed variable.**

## 4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?

**Value = 0**

b) Please note down if the N and/or V flags are set in the APSR register. And explain why.

**N = 0**
**V = 0**
**Both the N and V flags are set.  The value is 0, so it is not negative (N=0) and the calculation did not result in an overflow (V=0)**

## 5. Move the “counter’ variable outside of main (at the top of the file):
a) What is the scope of the variable “counter”?

**When counter declaration is moved out of main, it is now global**

b) Is it still visible in the “Locals” view?

**It is no longer visible in the Locals view**

c) In which window view can we track “counter” now?

**You can add counter to the Watch 1 window**

d) What is the address of the “counter” variable in memory?

**0x20000000**

## 6. Change the source code to the following, then run the program in the simulator:
```c
int counter = 0x0;
int main() {
    int *p_int = (int *)0x20000000;
    ++(*p_int);
    ++(*p_int);
    ++(*p_int);
    counter ++;
    return 0;
}
```
a) What is the value of “counter” at the end of the program (halting at the return 0 statement)

**Value = 4**

b) Explain why the counter value has changed?

**p_int is a pointer that points to the memory location used by the counter variable, ++(*p_int) first dereferences and points to the value of counter and then increments the 
value in counter**

## 7. Change the setting of IAR to run the same program on the evaluation board:
a) What is the address where “counter” is stored?

**0x20000000**

b) Is the “counter” variable stored in RAM or ROM?

**RAM**

c) What is the value of “counter” at the end of the program (halting at the return 0 statement).

**Value = 4**
