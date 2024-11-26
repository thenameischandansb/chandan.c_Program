#include <stdio.h>
int main() {
    float num1, num2, sum;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    sum = num1 + num2;
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, sum);
    return 0;
}
