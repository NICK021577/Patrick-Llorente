#include <iostream>  // For input and output
#include <iomanip>   // For formatted output
#include <fstream>   // For file input and output
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
    // user to enter student details
    cout << "\nEnter details for student " << studentCount + 1 << ":\n";
    cout << "ID: "; cin >> students[studentCount].studentID;
    cout << "First Name: "; cin >> students[studentCount].firstName;
    cout << "Last Name: "; cin >> students[studentCount].lastName;
    cout << "Course: "; cin >> students[studentCount].course;
    cout << "GPA: "; cin >> students[studentCount].gpa;

    // check if sutednt ID already exists
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == students[studentCount].studentID) { // Check if student ID already exists
            cout << "Student ID already exists. Try again.\n";
            return;
        }
    }

    // student count after successful entry
    studentCount++;
    cout << "Student added successfully!\n";
}
// Edit student Details
void editStudentDetail() {
    int studentID;
    cout << "Enter student ID to edit: ";
    cin >> studentID;       // Input student ID

    for (int i = 0; i < studentCount; i++) {        // Search for student ID based on the input data
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
// display all student records
void displayStudents() {
    // arange students by GPA or by Alphabetical order
    int choice;
    cout << "Sort students by:\n";
    cout << "1. Alphabetical order\n";
    cout << "2. GPA\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1: // Display students in alphabetical order
        for (int i = 0; i < studentCount; i++) {
            for (int j = i + 1; j < studentCount; j++) {
                if (students[i].firstName > students[j].firstName) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
        cout << "Students in alphabetical order:\n";
        cout << "ID\tName\t\tCourse\tGPA\n";
        cout << fixed << setprecision(2);
        for (int i = 0; i < studentCount; i++) {
            cout << students[i].studentID << "\t";
            cout << students[i].firstName << " " << students[i].lastName << "\t";
            cout << students[i].course << "\t";
            cout << students[i].gpa << "\n";
        }
        break;

    case 2: // Display students by GPA
        for (int i = 0; i < studentCount; i++) {
            for (int j = i + 1; j < studentCount; j++) {
                if (students[i].gpa < students[j].gpa) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
        cout << "Students by GPA:\n";
        cout << "ID\tName\t\tCourse\tGPA\n";
        cout << fixed << setprecision(2);
        for (int i = 0; i < studentCount; i++) {
            cout << students[i].studentID << "\t";
            cout << students[i].firstName << " " << students[i].lastName << "\t";
            cout << students[i].course << "\t";
            cout << students[i].gpa << "\n";
        }
        break;
    default:
        cout << "Invalid choice. Try again.\n";
    }
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }
    return;
}




// Student delete function
void deleteStudent() {
    int studentID;
    cout << "Enter student ID to delete: ";
    cin >> studentID;       // Input student ID

    for (int i = 0; i < studentCount; i++) { // Search for student ID based on the input data
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
