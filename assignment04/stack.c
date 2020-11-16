#include "stack.h"

// global variables
int g_top;
int g_stack[STACK_SIZE];

// stack_init resets stack data to 0's and resets TOP to -1
int stack_init() {
    int i;
    
    //initialize stack data
    for(i=0; i < STACK_SIZE; i++) {
        g_stack[i] = 0;
    }
    // set stack to empty
    g_top = EMPTY;
    
    return 0;
}

// print_stack displays stack and returns 1 if stack is empty
int print_stack(int *data) {
    int i;
    printf("\nPrint_Stack\n");
    if (g_top == EMPTY) {
        printf("print_stack: Stack is empty\n");
        return 1;
    }
    
    for(i=STACK_SIZE-1; i>EMPTY; i--){
        printf("stack[%d] = %d\n", i, data[i]);
    }
    printf("\nPrint_Stack\n");
    return 0;
}

// push adds data to stack if it is not full, returns 1 if full
int push(int elem){
    if(g_top >= STACK_SIZE-1) {
        // stack full so return 1
        return 1;
    }
    g_top++;
    g_stack[g_top] = elem;
    return elem;
}

// pop removes data from stack and returns it, returns 1 if stack is empty
int pop(){
    if(g_top == EMPTY) {
        // stack is empty, so return 1
        return 1;
    }
    g_top--;
    return g_stack[g_top+1];
}