#include <stdio.h>
#include <string.h>

// Define the structure to store student information
struct Student {
    char name[50];
    int roll_number;
    float marks[3];
    float total;
    float average;
};

// Function to calculate total and average marks for a student
void calculate_marks(struct Student *s) {
    s->total = s->marks[0] + s->marks[1] + s->marks[2];
    s->average = s->total / 3.0;
}

// Function to compare two students based on their average marks in descending order
int compare_students(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;

    // Compare by average in descending order
    if (studentA->average < studentB->average) {
        return 1;
    } else if (studentA->average > studentB->average) {
        return -1;
    }
    return 0;
}

int main() {
    int n;

    // Input number of students
    scanf("%d", &n);

    // Declare an array of students
    struct Student students[n];

    // Read student data
    for (int i = 0; i < n; i++) {
        getchar();  // To consume the newline character after the number of students
        fgets(students[i].name, 50, stdin);  // Read the student's name
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove the trailing newline character
        scanf("%d", &students[i].roll_number);  // Read roll number

        // Read marks for the three subjects
        scanf("%f %f %f", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);

        // Calculate total and average marks for the student
        calculate_marks(&students[i]);
    }

    // Sort students by average marks in descending order using qsort
    qsort(students, n, sizeof(struct Student), compare_students);

    // Display the student information in sorted order
    for (int i = 0; i < n; i++) {
        // Print the student information with no extra commas or spaces
        printf("Name: %s, Roll Number: %d, Total Marks: %.2f, Average Marks: %.2f\n",
               students[i].name, students[i].roll_number, students[i].total, students[i].average);
    }

    return 0;
}