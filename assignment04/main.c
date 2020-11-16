#include <stdio.h>
#include "stack.h"

// global variables
extern int g_top;
extern int g_stack[STACK_SIZE];

int main()
{
    int i;
    
    // Initialize stack
    stack_init();
    
    // view stack before we put anything on it
    int err = print_stack(g_stack);
    
    // TEST 1: try to pop empty stack
    err = pop();
    if(err == 1) {
        // expecting an error
        printf("Stack empty: Problem popping from empty stack: err = %d, g_top = %d\n", err, g_top);
    }
    
    // TEST 2: test pushing to stack with automated loop to handle changes in stack size
    // TEST 3: try to push more data than stack can hold (for loop with STACK_SIZE+1)
    stack_init();
    
    for(i=0; i < STACK_SIZE + 1; i++){
        err = push(i+10); // just offset by 10 since stack error is indicated by value 1 return
        if(err == 1) {
            printf("Stack full: Problem pushing to full stack: err = %d, g_top = %d\n", err, g_top);
        } else {
            printf("Pushed to stack: value = %d, g_top = %d\n", err, g_top);
        }
    }
    
    print_stack(g_stack);
    
    // TEST 4: try to pop from good stack
    // TEST 5: try to pop from empty stack (for loop with STACK_SIZE+1)
    for(i=0; i < STACK_SIZE + 1; i++){
        err = pop();
        if(err == 1) {
            printf("Stack Empty: Problem popping from empty stack: err = %d, g_top = %d\n", err, g_top);
        } else {
            printf("Popped from stack: value = %d, g_top = %d\n", err, g_top+1);
        }
    }
    
    return 0;
}