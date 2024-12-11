#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addVertex(Graph* graph, int vertex) {
    if (vertex >= graph->numVertices) {
        graph->adjLists = realloc(graph->adjLists, (vertex + 1) * sizeof(Node*));
        for (int i = graph->numVertices; i <= vertex; i++) {
            graph->adjLists[i] = NULL;
        }
        graph->numVertices = vertex + 1;
    }
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printAdjList(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        if (temp) {
            printf("%d: [", i);
            while (temp) {
                printf("%d", temp->vertex);
                temp = temp->next;
                if (temp) printf(" ");
            }
            printf("]\n");
        }
    }
}

void processOperations(int numOperations) {
    Graph* graph = createGraph(0);

    for (int i = 0; i < numOperations; i++) {
        char operation[20];
        scanf("%s", operation);

        if (strcmp(operation, "ADD_VERTEX") == 0) {
            int vertex;
            scanf("%d", &vertex);
            addVertex(graph, vertex);
        } else if (strcmp(operation, "ADD_EDGE") == 0) {
            int src, dest;
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
        } else if (strcmp(operation, "PRINT_ADJ_LIST") == 0) {
            printAdjList(graph);
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    int numOperations;
    scanf("%d", &numOperations);
    processOperations(numOperations);
    return 0;
}