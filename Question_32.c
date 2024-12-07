#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
typedef struct { 
    int id; 
    char name[51]; 
    int quantity; 
    float price; 
} Product; 
  
void addProduct(Product** inventory, int* size, int* capacity, int id, const char* name, int 
quantity, float price) { 
    if (*size == *capacity) { 
        *capacity *= 2; 
        *inventory = realloc(*inventory, (*capacity) * sizeof(Product)); 
    } 
    (*inventory)[*size].id = id; 
    strcpy((*inventory)[*size].name, name); 
    (*inventory)[*size].quantity = quantity; 
    (*inventory)[*size].price = price; 
    (*size)++; 
} 
  
void updateProduct(Product* inventory, int size, int id, int quantity) { 
    for (int i = 0; i < size; i++) { 
        if (inventory[i].id == id) { 
            inventory[i].quantity = quantity; 
            printf("Product updated successfully\n"); 
            return; 
        } 
    } 
    printf("Product not found\n"); 
} 
  
void removeProduct(Product** inventory, int* size, int id) { 
    for (int i = 0; i < *size; i++) { 
        if ((*inventory)[i].id == id) { 
            for (int j = i; j < *size - 1; j++) { 
                (*inventory)[j] = (*inventory)[j + 1]; 
            } 
            (*size)--; 
            printf("Product removed successfully\n"); 
            return; 
        } 
    } 
    printf("Product not found\n"); 
} 
  
void calculateTotalValue(Product* inventory, int size) { 
    float total = 0.0; 
    for (int i = 0; i < size; i++) { 
        total += inventory[i].quantity * inventory[i].price; 
    } 
    printf("%.2f\n", total); 
} 
  
void listAllProducts(Product* inventory, int size) { 
    for (int i = 0; i < size; i++) { 
        printf("%d \"%s\" %d %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, 
inventory[i].price); 
    } 
} 
  
int main() { 
    int n; 
    scanf("%d", &n); 
  
    Product* inventory = malloc(2 * sizeof(Product)); 
    int size = 0, capacity = 2; 
  
    for (int i = 0; i < n; i++) { 
        char operation[10]; 
        scanf("%s", operation); 
  
        if (strcmp(operation, "ADD") == 0) { 
            int id, quantity; 
            float price; 
            char name[51]; 
            scanf("%d \"%[^\"]\" %d %f", &id, name, &quantity, &price); 
            addProduct(&inventory, &size, &capacity, id, name, quantity, price); 
        } else if (strcmp(operation, "UPDATE") == 0) { 
            int id, quantity; 
            scanf("%d %d", &id, &quantity); 
            updateProduct(inventory, size, id, quantity); 
        } else if (strcmp(operation, "REMOVE") == 0) { 
            int id; 
            scanf("%d", &id); 
            removeProduct(&inventory, &size, id); 
        } else if (strcmp(operation, "TOTAL") == 0) { 
            calculateTotalValue(inventory, size); 
        } else if (strcmp(operation, "LIST") == 0) { 
            listAllProducts(inventory, size); 
        } 
    } 
  
    free(inventory); 
    return 0; 
}