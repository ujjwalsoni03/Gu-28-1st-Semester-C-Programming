#include <stdio.h> 
#include <stdlib.h> 
  
int main() { 
    int original; 
    int *ptr1; 
    int *heapPtr; 
    int initialValue, heapValue; 
  
    scanf("%d %d", &initialValue, &heapValue); 
  
    original = initialValue; 
  
    ptr1 = &original; 
  
    *ptr1 += 5; 
  
    heapPtr = (int *)malloc(sizeof(int)); 
  
    if (heapPtr == NULL) { 
        return 1; 
    } 
  
    *heapPtr = heapValue; 
  
printf("Original Integer: %d\n", original); 
printf("Heap Integer: %d\n", *heapPtr); 
free(heapPtr); 
return 0; 
}