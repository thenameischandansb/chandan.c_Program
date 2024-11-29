#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num = (int *)malloc(sizeof(int));
    if (num == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *num = 42; 
    printf("Value: %d\n", *num);

    free(num); 
    return 0;
}
