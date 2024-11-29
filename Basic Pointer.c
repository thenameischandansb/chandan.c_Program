#include <stdio.h>
int main() {
    int num = 10;
    int *ptr = &num; 

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Pointer pointing to: %p\n", ptr);
    printf("Value at pointer: %d\n", *ptr); 

    return 0;
}
