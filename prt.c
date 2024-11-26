#include <stdio.h>
int main() {
    float principal, rate, time, simple_interest;
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &rate);
    printf("Enter the time (in years): ");
    scanf("%f", &time);
    simple_interest = (principal * rate * time) / 100;
    printf("The Simple Interest is: %.2f\n", simple_interest);
    return 0;
}
