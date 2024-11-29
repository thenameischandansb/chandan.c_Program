#include <stdio.h>
// defining stricture 
//Chndan s B 
struct student{
char name[50];
int roll;
float marks;
};
int main(){
  struct student s1;
  printf("Enter the name");
  scanf("%s",s1.name);
  printf("Enter the roll mumber");
  scanf("%d",&s1.roll);
  printf("Enter the marks");
  scanf("%f",&s1.marks);
  printf("\nstudent Details");
  printf("Name:%s\nRoll:%d\nMarks:%.2f",s1.name,s1.roll,s1.marks);
  return 0;
}