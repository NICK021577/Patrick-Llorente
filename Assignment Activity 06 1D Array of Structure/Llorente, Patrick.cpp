#include <iostream>  // For input and output
#include <string>    // For handling string data
using namespace std;

// structure to store student details
struct Student {
    int studentID;       // student ID
    string firstName;    // First name of the student
    string lastName;     // Last name of the student
    string course;       // Course of student
    float gpa;           // Student previous semester GPA
};

// Define constants
const int MAX_STUDENTS = 100;  // Maximum number of students that can be stored

// Declare global variables
Student students[MAX_STUDENTS];  // Array to store student records
int studentCount = 0;            // track number of students added

// Function to add a student
void addStudent() {
    // Check if student list is full
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student list is full!\n";
        return;
    }
    // if student ID is the same
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == students[studentCount].studentID) {
            cout << "Student ID already exists!\n";
            return;
        }
    }
    
    // user to enter student details
    cout << "\nEnter details for student " << studentCount + 1 << ":\n";
    cout << "ID: "; cin >> students[studentCount].studentID;
    cout << "First Name: "; cin >> students[studentCount].firstName;
    cout << "Last Name: "; cin >> students[studentCount].lastName;
    cout << "Course: "; cin >> students[studentCount].course;
    cout << "GPA: "; cin >> students[studentCount].gpa;
    
    // student count after successful entry
    studentCount++;
    cout << "Student added successfully!\n";
}

// display all student records
void displayStudents() {
    // Check if there are any students to display
    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }
    
    // Display all stored student details
    cout << "\nStudent Records:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].studentID << ", "
             << "Name: " << students[i].firstName << " " << students[i].lastName << ", "
             << "Course: " << students[i].course << ", "
             << "GPA: " << students[i].gpa << endl;
    }
}

// Edit student Details
void editStudentDetail() {
    int studentID;
    cout << "Enter student ID to edit: ";
    cin >> studentID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            cout << "Enter new details for student " << studentID << ":\n";
            cout << "First Name: "; cin >> students[i].firstName;
            cout << "Last Name: "; cin >> students[i].lastName;
            cout << "Course: "; cin >> students[i].course;
            cout << "GPA: "; cin >> students[i].gpa;
            cout << "Student details updated successfully!\n";
            return;
        }
    }

    cout << "Student with ID " << studentID << " not found.\n";
}

// Student delete function
void deleteStudent() {
    int studentID;
    cout << "Enter student ID to delete: ";
    cin >> studentID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student with ID " << studentID << " not found.\n";
}

// Main function: program entry point
int main() {
    int choice;  // Variable to store menu selection

    // Display menu in a loop until user chooses to exit
    do {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Edit Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        //Input users choice
        cout << "Enter your choice: ";
        cin >> choice;
        // Process user selection using a switch statement
        switch (choice) {
            case 1: addStudent(); break;        // Call function to add student
            case 2: displayStudents(); break;   // Call function to display students
            case 3: editStudentDetail(); break; // Call function to edit student
            case 4: deleteStudent(); break;     // Call function to delete student
            case 5: cout << "Exiting program...\n"; break;  // Exit message
            default: cout << "Invalid choice. Try again.\n";  // Handle invalid input
        }
        
    } while (choice != 5);  // Repeat menu until user chooses to exit

    return 0;  // End of program
}
