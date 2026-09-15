#include <iostream>
#include <string>
using namespace std;

int main() {
    string studentName;
    string homeworkStatus;

    cout << "=============================" << endl;
    cout << "      HW CHECKER APP         " << endl;
    cout << "=============================" << endl;
    
    cout << "Enter student name: ";
    getline(cin, studentName);
    
    cout << "Is the homework complete? (Yes/No): ";
    getline(cin, homeworkStatus);
    
    cout << "\n[RECORD UPDATED]" << endl;
    cout << "Student: " << studentName << endl;
    cout << "Status: " << homeworkStatus << endl;

    return 0;
}