#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MIN_LENGTH 8
int validatePassword(char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (ispunct(password[i])) { 
            hasSpecial = 1;
        }
    }
    if (hasUpper && hasLower && hasDigit && hasSpecial) {
        return 1; 
    } else {
        if (!hasUpper) {
            printf("Password must contain at least one uppercase letter.\n");
        }
        if (!hasLower) {
            printf("Password must contain at least one lowercase letter.\n");
        }
        if (!hasDigit) {
            printf("Password must contain at least one digit.\n");
        }
        if (!hasSpecial) {
            printf("Password must contain at least one special character (e.g., !@#$%^&*()).\n");
        }
        return 0;
    }
}
int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    if (validatePassword(password)) {
        printf("Password is valid!\n");
    } else {
        printf("Password is invalid. Please try again.\n");
    }

    return 0;
}
