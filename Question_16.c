#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
typedef struct {
 int id;
 char title[MAX_TITLE_LENGTH];
} Book;
Book library[MAX_BOOKS];
int bookCount = 0;
void addBook() {
if (bookCount >= MAX_BOOKS) {
 return;
 }
 int id;
 char title[MAX_TITLE_LENGTH];
 scanf("%d", &id);
 getchar();
 fgets(title, MAX_TITLE_LENGTH, stdin);
 title[strcspn(title, "\n")] = '\0';
 library[bookCount].id = id;
 strcpy(library[bookCount].title, title);
 bookCount++;
 printf("Book added successfully.\n");
}
void searchBook() {
 int id;
 scanf("%d", &id);
 for (int i = 0; i < bookCount; i++) {
 if (library[i].id == id) {
 printf("Book found: ID=%d, Title=\"%s\"\n", library[i].id, library[i].title);
return;
 }
 }
 printf("Book not found.\n");
}
void deleteBook() {
 int id;
 scanf("%d", &id);
 for (int i = 0; i < bookCount; i++) {
 if (library[i].id == id) {
 for (int j = i; j < bookCount - 1; j++) {
 library[j] = library[j + 1];
 }
 bookCount--;
 printf("Book deleted successfully.\n");
 return;
 }
 }
 printf("Book not found.\n");
}
void displayBooks() {
 if (bookCount == 0) {
 printf("No books in the library.\n");
return;
 }
 for (int i = 0; i < bookCount; i++) {
 printf("Book ID=%d, Title=\"%s\"\n", library[i].id, library[i].title);
 }
}
int main() {
 int choice;
 while (1) {
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 addBook();
 break;
 case 2:
 searchBook();
 break;
 case 3:
 deleteBook();
 break;
 case 4:
 displayBooks();
 break;
case 5:
 printf("Exiting the program...\n");
 return 0;
 }
 }
 return 0;
}
