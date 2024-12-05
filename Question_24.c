#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    return temp;
}

// Function to reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    
    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // If list is not empty, reset head to the new first node
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to remove duplicates from the doubly linked list
void removeDuplicates(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    struct Node* prev = NULL;
    
    // Use a hash table (or a set) to keep track of seen values
    int seen[1000001] = {0};  // For values in range -10^6 to 10^6
    
    while (current != NULL) {
        // If the value is already in the seen array, remove the node
        if (seen[current->data] > 0) {
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
            temp = current;
            current = current->next;
            free(temp);
        } else {
            // Mark the value as seen
            seen[current->data] = 1;
            prev = current;
            current = current->next;
        }
    }
}

// Function to insert the sum of elements at the end of the list
void insertSumAtEnd(struct Node** head) {
    int sum = 0;
    struct Node* current = *head;
    
    // Calculate the sum of all elements
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    
    // Create a new node for the sum and add it to the end of the list
    struct Node* sumNode = newNode(sum);
    
    // Traverse to the last node
    if (*head == NULL) {
        *head = sumNode;
        return;
    }
    
    current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = sumNode;
    sumNode->prev = current;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to drive the solution
int main() {
    int n;
    
    // Read the number of nodes
    scanf("%d", &n);
    
    // Create an empty linked list
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    // Read the list elements
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        
        struct Node* new_node = newNode(data);
        
        if (head == NULL) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    
    // Step 1: Reverse the list
    reverseList(&head);
    
    // Step 2: Remove duplicates
    removeDuplicates(&head);
    
    // Step 3: Insert the sum at the end
    insertSumAtEnd(&head);
    
    // Print the final list
    printList(head);
    
    return 0;
}
