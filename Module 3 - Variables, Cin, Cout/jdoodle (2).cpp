#include <iostream>
#include <string>
using namespace std;

int main() {
    // Homework Checker App Variables
    string studentName = "Alex Rivera"; // text
    string assignmentName = "Math Homework #3"; // text
    int totalQuestions = 10; // whole number
    int correctAnswers = 8; // whole number
    double scorePercentage = 80.0; // decimal number
    char letterGrade = 'B'; // single character
    bool isPassed = true; // true or false

    // Displaying Assignment Results
    cout << "========================================" << endl;
    cout << "         HOMEWORK CHECKER APP           " << endl;
    cout << "========================================" << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Assignment:   " << assignmentName << endl;
    cout << "Score:        " << correctAnswers << "/" << totalQuestions << " (" << scorePercentage << "%)" << endl;
    cout << "Grade:        " << letterGrade << endl;
    cout << "Passed:       " << isPassed << " (1 = True, 0 = False)" << endl;
    cout << "========================================" << endl;

    return 0;
}