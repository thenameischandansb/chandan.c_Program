#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
    struct Employee employees[2]; 

    
    for (int i = 0; i < 2; i++) {
        printf("Enter the details of employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name); 
        printf("ID: ");
        scanf("%d", &employees[i].id); 
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    
    printf("\nEmployee Details:\n");
    for (int i = 0; i < 2; i++) {
        printf("Name: %s, ID: %d, Salary: %.2f\n", employees[i].name, employees[i].id, employees[i].salary);
    }

    return 0;
}
