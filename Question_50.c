#include <stdio.h> 
#include <stdlib.h> 
typedef struct { 
int *buffer; 
int size; 
int front; 
int rear; 
int count; 
} CircularBuffer; 
void initBuffer(CircularBuffer *cb, int size) { 
cb->size = size; 
cb->buffer = (int *)malloc(size * sizeof(int)); 
cb->front = 0; 
cb->rear = 0; 
cb->count = 0; 
} 
void freeBuffer(CircularBuffer *cb) { 
free(cb->buffer); 
} 
int isFull(CircularBuffer *cb) { 
return cb->count == cb->size; 
} 
int isEmpty(CircularBuffer *cb) { 
return cb->count == 0; 
} 
void addElement(CircularBuffer *cb, int element) { 
if (isFull(cb)) { 
printf("Buffer is full. Unable to add element.\n"); 
return; 
} 
cb->buffer[cb->rear] = element; 
cb->rear = (cb->rear + 1) % cb->size; 
cb->count++; 
} 
void removeElement(CircularBuffer *cb) { 
if (isEmpty(cb)) { 
printf("Buffer is empty. Unable to remove element.\n"); 
return; 
} 
cb->front = (cb->front + 1) % cb->size; 
cb->count--; 
} 
void resizeBuffer(CircularBuffer *cb, int newSize) { 
int *newBuffer = (int *)malloc(newSize * sizeof(int)); 
int i, j; 
for (i = cb->front, j = 0; j < cb->count; j++) { 
newBuffer[j] = cb->buffer[i]; 
i = (i + 1) % cb->size; 
} 
free(cb->buffer); 
cb->buffer = newBuffer; 
cb->size = newSize; 
cb->front = 0; 
cb->rear = cb->count; 
} 
void printBuffer(CircularBuffer *cb) { 
if (isEmpty(cb)) { 
printf("Buffer is empty.\n"); 
return; 
} 
int i = cb->front; 
for (int j = 0; j < cb->count; j++) { 
printf("%d ", cb->buffer[i]); 
i = (i + 1) % cb->size; 
} 
printf("\n"); 
} 
int main() { 
int n, newSize, value; 
char operation[10]; 
scanf("%d", &n); 
CircularBuffer cb; 
initBuffer(&cb, 10); 
for (int i = 0; i < n; i++) { 
scanf("%s", operation); 
if (strcmp(operation, "ADD") == 0) { 
scanf("%d", &value); 
addElement(&cb, value); 
} else if (strcmp(operation, "REMOVE") == 0) { 
removeElement(&cb); 
} else if (strcmp(operation, "RESIZE") == 0) { 
scanf("%d", &newSize); 
resizeBuffer(&cb, newSize); 
} 
printBuffer(&cb); 
} 
freeBuffer(&cb); 
return 0; 
}