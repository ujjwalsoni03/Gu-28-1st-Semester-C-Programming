#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node { 
int row, col, value; 
struct Node *next; 
} Node; 
Node *head = NULL; 
void insert(int row, int col, int value) { 
Node *newNode = (Node *)malloc(sizeof(Node)); 
newNode->row = row; 
newNode->col = col; 
newNode->value = value; 
newNode->next = NULL; 
if (!head) { 
head = newNode; 
return; 
} 
Node *temp = head; 
while (temp->next) { 
if (temp->row == row && temp->col == col) { 
temp->value = value; 
free(newNode); 
return; 
} 
temp = temp->next; 
} 
temp->next = newNode; 
} 
void delete(int row, int col) { 
Node *temp = head, *prev = NULL; 
while (temp) { 
if (temp->row == row && temp->col == col) { 
if (prev) { 
prev->next = temp->next; 
} else { 
head = temp->next; 
} 
free(temp); 
return; 
} 
prev = temp; 
temp = temp->next; 
} 
} 
int retrieve(int row, int col) { 
Node *temp = head; 
while (temp) { 
if (temp->row == row && temp->col == col) { 
return temp->value; 
} 
temp = temp->next; 
} 
return 0; 
} 
int main() { 
int n; 
scanf("%d", &n); 
for (int i = 0; i < n; i++) { 
char operation[10]; 
int row, col, value; 
scanf("%s", operation); 
if (operation[0] == 'I') { 
scanf("%d %d %d", &row, &col, &value); 
insert(row, col, value); 
} else if (operation[0] == 'D') { 
scanf("%d %d", &row, &col); 
delete(row, col); 
} else if (operation[0] == 'R') { 
scanf("%d %d", &row, &col); 
printf("%d\n", retrieve(row, col)); 
} 
} 
return 0; 
}