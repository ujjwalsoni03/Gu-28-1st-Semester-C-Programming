#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numAssessments;
    int *scores; // Dynamic array for assessment scores
} Course;

typedef struct {
    int numCourses;
    Course *courses; // Dynamic array for courses
} Student;

void calculateAndDisplayAverages(Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        double totalStudentAverage = 0.0;
        
        for (int j = 0; j < students[i].numCourses; j++) {
            Course course = students[i].courses[j];
            double totalCourseScore = 0.0;
            
            for (int k = 0; k < course.numAssessments; k++) {
                totalCourseScore += course.scores[k];
            }
            double courseAverage = totalCourseScore / course.numAssessments;
            totalStudentAverage += courseAverage;
            printf("Course %d Average: %.2f\n", j + 1, courseAverage);
        }
        
        double overallAverage = totalStudentAverage / students[i].numCourses;
        printf("Overall Average: %.2f\n", overallAverage);
    }
}

int main() {
    int numStudents;
    //printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamic array for students
    Student *students = (Student *)malloc(numStudents * sizeof(Student));

    for (int i = 0; i < numStudents; i++) {
        //printf("Enter the number of courses for student %d: ", i + 1);
        scanf("%d", &students[i].numCourses);
        
        // Dynamic array for courses
        students[i].courses = (Course *)malloc(students[i].numCourses * sizeof(Course));

        for (int j = 0; j < students[i].numCourses; j++) {
            //printf("Enter the number of assessments for course %d of student %d: ", j + 1, i + 1);
            scanf("%d", &students[i].courses[j].numAssessments);
            
            // Dynamic array for scores
            students[i].courses[j].scores = (int *)malloc(students[i].courses[j].numAssessments * sizeof(int));
            
            //printf("Enter the scores for assessments: ");
            for (int k = 0; k < students[i].courses[j].numAssessments; k++) {
                scanf("%d", &students[i].courses[j].scores[k]);
            }
        }
    }

    // Calculate and display averages
    calculateAndDisplayAverages(students, numStudents);

    // Free allocated memory
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < students[i].numCourses; j++) {
            free(students[i].courses[j].scores); // Free scores for each course
        }
        free(students[i].courses); // Free courses for each student
    }
    free(students); // Free students array

    return 0;
}