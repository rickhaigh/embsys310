int swap_pointers(void **a, void **b);

int swap_pointers(void **a, void **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}

int main(){
    char a = 'A';
    char b = 'B';
    char *a_ptr = &a;
    char *b_ptr = &b;
    
    int ret;
    printf("a = %X *a_ptr = %X; b = %X *b_ptr = %X\n", a, *a_ptr, b, *b_ptr);
    ret = swap_pointers(&a_ptr, &b_ptr);
    printf("a = %X *a_ptr = %X; b = %X *b_ptr = %X\n", a, *a_ptr, b, *b_ptr);
    
    return ret;
}