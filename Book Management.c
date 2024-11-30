#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;
void addBook(Book *library, int *bookCount);
void displayBooks(Book *library, int bookCount);
int searchBook(Book *library, int bookCount, const char *title);
void deleteBook(Book *library, int *bookCount, const char *title);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;
    char title[MAX_TITLE_LENGTH];

    while (1) {
        printf("\nLibrary Book Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar();  
        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                printf("Enter book title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  
                int foundIndex = searchBook(library, bookCount, title);
                if (foundIndex != -1) {
                    printf("Book found:\n");
                    printf("Title: %s\n", library[foundIndex].title);
                    printf("Author: %s\n", library[foundIndex].author);
                    printf("Year: %d\n", library[foundIndex].year);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 4:
                printf("Enter book title to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  
                deleteBook(library, &bookCount, title);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  
    printf("Enter author name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  
    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    getchar();  
    library[*bookCount] = newBook;
    (*bookCount)++;
    printf("Book added successfully!\n");
}
void displayBooks(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }
    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("------------------------\n");
    }
}
int searchBook(Book *library, int bookCount, const char *title) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            return i;  
        }
    }
    return -1; 
}
void deleteBook(Book *library, int *bookCount, const char *title) {
    int index = searchBook(library, *bookCount, title);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }
    for (int i = index; i < *bookCount - 1; i++) {
        library[i] = library[i + 1];
    }

    (*bookCount)--;  
    printf("Book '%s' deleted successfully!\n", title);
}
