#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for student structure.
typedef struct student {
    char name[100];
    int student_id;
    float gpa;
    struct student* next;
} Student;

Student* head = NULL;

// Function to create an empty list.
void create_empty_list() {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("The list has been created and is now empty.\n");
}

// Function to count the number of nodes in the list.
int count_nodes() {
    int count = 0;
    Student* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to print all nodes in the list.
void print_all_nodes() {
    Student* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("Name: %s, Student ID: %d, GPA: %.2f\n", current->name, current->student_id, current->gpa);
        current = current->next;
    }
}

// Function to add a student at the beginning of the list.
void add_student_beginning() {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%99s", new_student->name);
    printf("Enter student ID: ");
    scanf("%d", &new_student->student_id);
    printf("Enter GPA: ");
    scanf("%f", &new_student->gpa);

    new_student->next = head;
    head = new_student;
    printf("Student added at the beginning of the list.\n");
}

// Function to add a student at the end of the list.
void add_student_end() {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%99s", new_student->name);
    printf("Enter student ID: ");
    scanf("%d", &new_student->student_id);
    printf("Enter GPA: ");
    scanf("%f", &new_student->gpa);

    new_student->next = NULL;

    if (head == NULL) {
        head = new_student;
    } else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
    printf("Student added at the end of the list.\n");
}

// Function to delete a student by ID.
void delete_student_by_id() {
    int student_id;
    printf("Enter student ID to delete: ");
    scanf("%d", &student_id);

    Student* current = head;
    Student* previous = NULL;

    while (current != NULL && current->student_id != student_id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %d not found.\n", student_id);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Student with ID %d deleted.\n", student_id);
}

// Function to delete students by name.
void delete_students_by_name() {
    char name[100];
    printf("Enter name to delete: ");
    scanf("%99s", name);

    Student* current = head;
    Student* previous = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            Student* temp = current;
            current = current->next;
            free(temp);
            found = 1;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (found) {
        printf("All students with name %s deleted.\n", name);
    } else {
        printf("No students with name %s found.\n", name);
    }
}

// Function to free all allocated memory.
void free_memory() {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All memory has been freed.\n");
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create an empty linked list of students\n");
        printf("2. Print the number of nodes of list\n");
        printf("3. Print all nodes of list\n");
        printf("4. Enter information of a student and add this student at the beginning of list\n");
        printf("5. Enter information of a student and add this student at the end of list\n");
        printf("6. Enter a student_id and delete the student with the student_id\n");
        printf("7. Enter a name and delete all the students with the same name\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_empty_list();
                break;
            case 2:
                printf("Number of nodes: %d\n", count_nodes());
                break;
            case 3:
                print_all_nodes();
                break;
            case 4:
                add_student_beginning();
                break;
            case 5:
                add_student_end();
                break;
            case 6:
                delete_student_by_id();
                break;
            case 7:
                delete_students_by_name();
                break;
            case 8:
                free_memory();
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
