# Assignment04
## Problems:
1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit- band region to enable the clock to Port A, then answer the following:
	a.   What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?
		**MOVS  R0, #1 //moves the constant 1 into R0 and update APSR**
		**LDR.N R1, [PC,#0x28]; 0x4242'0980 // read memory at PC+0x28 and store in R1**
		**STR   R0, [R1]  // This is the store of 1 to the bit banding address 0x4242.0980 (single instruction to write to GPIO)**
	b.   What were the instructions produced when writing to the GPIOx_ODR without using bit- banding?
		**LDR.N  R0, [PC, #0x30]  // load RCC_AHB2ENR location into R0**
		**LDR    R1, [R0]  // read memory contents (RCC_AHB2ENR register) into R1**
		**ORRS.W R1, R1, #1 // OR value in R1 with 1 and put result back in R1**
		**STR    R1, [R0]  // Store R1 back in RCC_AHB2ENR memory location**

2. Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:
	a.   How does the calling function “func2” pass the values to the called function “func1”?
		**Stores the last arg in R0 and then transfers it to RAM, then stores the other 4 args in R0-R3**
	b.   What extra code did the compiler generate before calling the function “func1” with the multiple arguments?
		**Reads the arg into R0 and then STR R0,[SP] which stores this arg in RAM**
	c.    What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?
		**There does not appear to be any extra code in funct1**
	d.   Any other observations?
		**Adding other instructions in the functions or declaring variable in the functions uses much more stack space**
		**It is interesting how the system is always planning ahead to save of state as it runs new functions**
		**Using just 3 args in func1 does not store any of the args in RAM, just in the registers**

3. Following the queue data structure approach, design, implement and test a stack data structure:
	a.   The following is the list of requirements:
		i.   The stack should have a predefined size
			**Defined by STACK_SIZE in stack.h**
		ii.   The stack supports “int” data types.
			**int g_stack[STACK_SIZE]; in stack.c**
		iii.   Provide a function to initialize the stack internals.
			**stack_init() in stack.c**
		iv.   Provide a function to push an element onto the stack
			**push(int elem) in stack.c, it was my intention to include vii functionality of returning 1 if stack is full here rather than a separage function**
		v.   Provide a function to pop an element off the stack.
			**pop() in stack.c, it was my intention to include vi functionality of returning 1 if stack is empty here rather than a separate function**
		vi.   Provide a function that returns 1 if stack is empty.
			**return 1 in pop() when stack is empty**
		vii.   Provide a function that returns 1 if stack is full.
			**return 1 in push() when stack is full**
	b.   Provide a list of the test cases and their implementation inside of main.c
		**TEST 1: try to pop empty stack**
		**TEST 2: test pushing to stack with automated loop to handle changes in stack size**
		**TEST 3: try to push more data than stack can hold (for loop with STACK_SIZE+1)**
		**TEST 4: try to pop from good (non empty) stack**
		**TEST 5: try to pop from empty stack (for loop with STACK_SIZE+1)**
	c.    Separate the stack code from the rest of the test code (create stack.h & stack.c)
		**stack.c and stack.h are included**

4. Bonus: Using the power of pointers and type casting, create a function that can determine if a computer is big-endian or little-endian. Test your function in the simulator and modify the Project Options in IAR against:
**see assignment04/endian.c
	a. Cortex M4 (Little endian option)
		**int number = 0x12345678**
		**Little Endian option setting (addr : value) -> 0x3F4 : 78, 0x3F5 : 56, 0x3F6 : 34, 0x3F7 : 12
	b. Cortex M4 (Big Endian option)
			**int number = 0x12345678**
		**Little Endian option setting (addr : value) -> 0x3F4 : 12, 0x3F5 : 34, 0x3F6 : 56, 0x3F7 : 78
What to turn in and how:
- Check in all your homework in your repo under the folder “assignment04”.
- Your folder should contain the following:
	o Turn in your source code files only (for example: main.c, stack.c, stack.h) and any other files that you have authored.
		**File sumbitted for #1 is blinky_xor.c**
		**File submitted for #2 is 5args.c**
		**Files submitted for #3 are main.c, stack.c & stack.h**
		**File submitted for #4 is endian.c**
	o Turn in answers to questions in markdown file format.
- Submit a link to your GitHub repo assignment:
o https://github.com/rickhaigh/embsys310/tree/main/assignment04