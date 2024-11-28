#include <stdio.h>
// CHANDAN S B
int main() {
    int arr[] = {10, 20, 30, 40, 50}; 
    int *ptr = arr;                  

    printf("%d\n", *ptr);            
    ptr++;                          
    printf("%d\n", *ptr);            

    return 0;                        
}
