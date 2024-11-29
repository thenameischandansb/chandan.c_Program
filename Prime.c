#include <stdio.h>
int main() {
    int n, i, isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (n < 2) isPrime = 0;
    if (isPrime)
        printf("Prime\n");
    else
        printf("Not Prime\n");
    return 0;
}
