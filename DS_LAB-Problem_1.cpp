#include <iostream>
using namespace std;

struct Student {
    int uniqueID;
    int semestersCompleted;
    int creditsCompleted;
    double cgpa;
};

int main() {
    Student students[15]; // Array to store 15 student records

    // Input student information
    for (int i = 0; i < 15; i++) {
        cout << "Enter information for student " << i + 1 << ":" << endl;
        cout << "Unique ID: ";
        cin >> students[i].uniqueID;
        cout << "Number of semesters completed: ";
        cin >> students[i].semestersCompleted;
        cout << "Number of credits completed: ";
        cin >> students[i].creditsCompleted;
        cout << "CGPA: ";
        cin >> students[i].cgpa;
    }

    cout << "Scholarship students (CGPA >= 3.75):" << endl;
    for (int i = 0; i < 15; i++) {
        if (students[i].cgpa >= 3.75) {
            cout << "Student ID: " << students[i].uniqueID << endl;
        }
    }

    cout << "Students with more than 50 credits completed:" << endl;
    for (int i = 0; i < 15; i++) {
        if (students[i].creditsCompleted > 50) {
            cout << "Student ID: " << students[i].uniqueID << endl;
        }
    }

    cout << "Students with at least 2 semesters and 28 credits completed:" << endl;
    for (int i = 0; i < 15; i++) {
        if (students[i].semestersCompleted >= 2 && students[i].creditsCompleted >= 28) {
            cout << "Student ID: " << students[i].uniqueID << endl;
        }
    }

    return 0;
}
