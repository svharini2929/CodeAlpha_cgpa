#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double gradePoints;
    double creditHours;
};

int main() {
    int numCourses;
    double totalGradePoints = 0, totalCredits = 0;
    vector<Course> courses;

    cout << "--- CGPA Calculator ---" << endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        Course c;
        cout << "\nEnter details for course " << i + 1 << ":" << endl;
        cout << "Course Name (or ID): ";
        cin >> c.name;
        cout << "Grade Points (e.g., 4.0 for A, 3.0 for B): ";
        cin >> c.gradePoints;
        cout << "Credit Hours: ";
        cin >> c.creditHours;

        courses.push_back(c);
        
        totalGradePoints += (c.gradePoints * c.creditHours);
        totalCredits += c.creditHours;
    }

    
    cout << "\n--- Academic Report ---" << endl;
    cout << left << setw(15) << "Course" << setw(10) << "Grade" << "Credits" << endl;
    
    for (const auto& c : courses) {
        cout << left << setw(15) << c.name 
             << setw(10) << c.gradePoints 
             << c.creditHours << endl;
    }

    if (totalCredits > 0) {
        double cgpa = totalGradePoints / totalCredits;
        cout << "\n-----------------------" << endl;
        cout << "Total Credits: " << totalCredits << endl;
        cout << fixed << setprecision(2);
        cout << "Final CGPA: " << cgpa << endl;
        cout << "-----------------------" << endl;
    }

    return 0;
}