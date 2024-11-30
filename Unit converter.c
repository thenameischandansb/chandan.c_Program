#include <stdio.h>
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float metersToKilometers(float meters);
float kilometersToMeters(float kilometers);
float gramsToKilograms(float grams);
float kilogramsToGrams(float kilograms);
int main() {
    int choice;
    float input, output;
    printf("Unit Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Kilometers\n");
    printf("4. Kilometers to Meters\n");
    printf("5. Grams to Kilograms\n");
    printf("6. Kilograms to Grams\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = celsiusToFahrenheit(input);
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, output);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = fahrenheitToCelsius(input);
            printf("%.2f Fahrenheit = %.2f Celsius\n", input, output);
            break;
        case 3:
            printf("Enter distance in meters: ");
            scanf("%f", &input);
            output = metersToKilometers(input);
            printf("%.2f meters = %.2f kilometers\n", input, output);
            break;
        case 4:
            printf("Enter distance in kilometers: ");
            scanf("%f", &input);
            output = kilometersToMeters(input);
            printf("%.2f kilometers = %.2f meters\n", input, output);
            break;
        case 5:
            printf("Enter weight in grams: ");
            scanf("%f", &input);
            output = gramsToKilograms(input);
            printf("%.2f grams = %.2f kilograms\n", input, output);
            break;
        case 6:
            printf("Enter weight in kilograms: ");
            scanf("%f", &input);
            output = kilogramsToGrams(input);
            printf("%.2f kilograms = %.2f grams\n", input, output);
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
    }

    return 0;
}
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float metersToKilometers(float meters) {
    return meters / 1000;
}

float kilometersToMeters(float kilometers) {
    return kilometers * 1000;
}

float gramsToKilograms(float grams) {
    return grams / 1000;
}

float kilogramsToGrams(float kilograms) {
    return kilograms * 1000;
}
