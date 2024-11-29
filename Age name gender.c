#include <stdio.h>

struct User {
    char name[50];
    int age;
    char gender[10];
    char branch[50];
    char college[100];
};

int main() {
    struct User user1;

    
    printf("Enter Name: ");
    fgets(user1.name, 50, stdin);
    printf("Enter Age: ");
    scanf("%d", &user1.age);
    getchar(); 
    printf("Enter Gender: ");
    fgets(user1.gender, 10, stdin);
    printf("Enter Branch: ");
    fgets(user1.branch, 50, stdin);
    printf("Enter College: ");
    fgets(user1.college, 100, stdin);

    
    printf("\nUser Details:\n");
    printf("Name: %s", user1.name);
    printf("Age: %d\n", user1.age);
    printf("Gender: %s", user1.gender);
    printf("Branch: %s", user1.branch);
    printf("College: %s", user1.college);

    return 0;
}
