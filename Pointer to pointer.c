#include <stdio.h>
int main() {
    int num = 25;
    int *ptr = &num;        
    int **pptr = &ptr;      

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value stored in ptr: %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);
    printf("Value stored in pptr: %p\n", pptr);
    printf("Value pointed to by pptr: %p\n", *pptr);
    printf("Value at the address pointed to by pptr: %d\n", **pptr);

    return 0;
}
