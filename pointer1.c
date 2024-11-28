#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x; 

    printf("Address of x: %p\n", (void *)ptr); 
    printf("Value of x: %d\n", *ptr);         

    return 0; 
}
