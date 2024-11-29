#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter 3 numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Increasing size to 5...\n");
    arr = (int *)realloc(arr, 5 * sizeof(int)); 
    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    printf("Enter 2 more numbers:\n");
    for (int i = 3; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Updated array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); 
    return 0;
}
