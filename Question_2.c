#include <stdio.h> 
#include <string.h> 
  
// Define the structure and union 
typedef struct { 
    char name[50]; 
    int id; 
    float grades[5]; 
    float average; 
    union { 
        char passFail; 
        int gradeCategory; 
    } status; 
} Student; 
  
// Function to input student data 
void inputStudentData(Student *s, int n) { 
    for (int i = 0; i < n; i++) { 
        scanf("%s", s[i].name); // Read name 
        scanf("%d", &s[i].id);  // Read ID 
        for (int j = 0; j < 5; j++) { 
            scanf("%f", &s[i].grades[j]); // Read grades 
        } 
    } 
} 
  
// Function to calculate the average grades for each student 
void calculateAverage(Student *s, int n) { 
    for (int i = 0; i < n; i++) { 
        float sum = 0.0; 
        for (int j = 0; j < 5; j++) { 
            sum += s[i].grades[j]; 
        } 
        s[i].average = sum / 5; // Calculate the average 
    } 
} 
  
// Function to determine the status of each student 
void determineStatus(Student *s, int n) { 
    for (int i = 0; i < n; i++) { 
        if (s[i].average >= 85) { 
            s[i].status.gradeCategory = 1; // Excellent 
        } else if (s[i].average >= 70) { 
            s[i].status.gradeCategory = 2; // Good 
        } else if (s[i].average >= 50) { 
            s[i].status.passFail = 'P'; // Pass 
        } else { 
            s[i].status.passFail = 'F'; // Fail 
        } 
    } 
} 
  
// Function to display student details 
void displayStudents(const Student *s, int n) { 
    for (int i = 0; i < n; i++) { 
        printf("Student: %s\n", s[i].name); 
        printf("ID: %d\n", s[i].id); 
        printf("Grades: "); 
        for (int j = 0; j < 5; j++) { 
            printf("%.1f", s[i].grades[j]); 
            if (j < 4) printf(", "); // Separate grades with commas 
        } 
        printf("\nAverage: %.1f\n", s[i].average); 
  
        // Display status 
        if (s[i].average >= 70) { 
            printf("Status: Grade Category - %d\n", s[i].status.gradeCategory); 
        } else { 
            printf("Status: Pass/Fail - %c\n", s[i].status.passFail); 
        } 
    } 
} 
  
// Main function 
int main() { 
    int n; 
    scanf("%d", &n); 
  
    Student students[n]; 
  
    inputStudentData(students, n); 
    calculateAverage(students, n); 
    determineStatus(students, n); 
    displayStudents(students, n); 
  
    return 0; 
}
