#include <iostream>
#include <string>

using namespace std;

int main() {
    // Array storing student names
    string students[3] = {"Alex", "Jordan", "Taylor"};
    
    // Array storing corresponding final grade percentages
    int grades[3] = {91, 84, 97};

    // Pointer pointing to the first student's score
    int *gradePtr = &grades[0];

    cout << "=== STUDENT GRADE TRACKER (MODULE 4) ===" << endl << endl;

    // Loop through the arrays using index values
    for (int i = 0; i < 3; i++) {
        cout << "Student: " << students[i] << " | Grade: " << grades[i] << "%" << endl;
    }

    cout << endl;
    // Accessing score data via pointer
    cout << "First student score retrieved via pointer: " << *gradePtr << "%" << endl;

    return 0;
}