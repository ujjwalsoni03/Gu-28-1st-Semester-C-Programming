#include <stdio.h>

#define MAX_N 1000
#define MAX_M 1000

// Directions for 8 neighbors (left, right, up, down, 4 diagonals)
int directions[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},  // vertical and horizontal
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  // diagonal directions
};

// Helper function to perform DFS and mark the connected land
void dfs(int grid[][MAX_M], int visited[][MAX_M], int n, int m, int x, int y) {
    // Stack for DFS, using an explicit stack to avoid recursion depth issues.
    int stack[MAX_N * MAX_M][2]; 
    int top = -1;
    
    // Push the starting point to stack
    stack[++top][0] = x;
    stack[top][1] = y;
    
    // Mark the current cell as visited
    visited[x][y] = 1;
    
    while (top >= 0) {
        int cx = stack[top][0];
        int cy = stack[top][1];
        top--;
        
        // Visit all 8 neighbors
        for (int i = 0; i < 8; i++) {
            int nx = cx + directions[i][0];
            int ny = cy + directions[i][1];
            
            // Check if the neighbor is valid and hasn't been visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 1 || grid[nx][ny] == 2)) {
                visited[nx][ny] = 1;
                stack[++top][0] = nx;
                stack[top][1] = ny;
            }
        }
    }
}

// Function to count distinct islands
int countIslands(int grid[][MAX_M], int n, int m) {
    int visited[MAX_N][MAX_M] = {0};
    int islandCount = 0;
    
    // Loop through the grid to find all unvisited land or bridge cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Start DFS if we find an unvisited land or bridge
            if ((grid[i][j] == 1 || grid[i][j] == 2) && !visited[i][j]) {
                dfs(grid, visited, n, m, i, j); // Explore the island
                islandCount++; // Increment the island count
            }
        }
    }
    
    return islandCount;
}

// Helper function to read the grid from input
void getInputGrid(int grid[][MAX_M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int main() {
    int n, m;
    
    // Read the dimensions of the grid
    scanf("%d %d", &n, &m);
    
    int grid[MAX_N][MAX_M];
    
    // Read the grid input
    getInputGrid(grid, n, m);
    
    // Count and output the number of distinct islands
    printf("%d\n", countIslands(grid, n, m));
    
    return 0;
}
