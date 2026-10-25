#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to represent an individual assignment
struct Assignment {
    string name;
    double score;
    double maxScore;
};

// Student class to manage assignments and calculate grades
class Student {
private:
    string studentName;
    vector<Assignment> assignments;

public:
    // Constructor
    Student(string name) : studentName(name) {}

    // Get student name
    string getName() const {
        return studentName;
    }

    // Add a new assignment score
    void addAssignment(string name, double score, double maxScore) {
        assignments.push_back({name, score, maxScore});
    }

    // Binary search to find an assignment by name (requires sorting vector)
    int searchAssignment(const string& targetName) {
        // Sort assignments alphabetically by name for binary search
        sort(assignments.begin(), assignments.end(), [](const Assignment& a, const Assignment& b) {
            return a.name < b.name;
        });

        int left = 0;
        int right = assignments.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (assignments[mid].name == targetName) {
                return mid;
            }
            if (assignments[mid].name < targetName) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Not found
    }

    // Calculate total percentage grade
    double calculateTotalPercentage() const {
        if (assignments.empty()) return 0.0;
        double totalEarned = 0.0;
        double totalPossible = 0.0;
        for (const auto& a : assignments) {
            totalEarned += a.score;
            totalPossible += a.maxScore;
        }
        if (totalPossible == 0.0) return 0.0;
        return (totalEarned / totalPossible) * 100.0;
    }

    // Determine final letter grade
    char calculateLetterGrade(double percentage) const {
        if (percentage >= 90.0) return 'A';
        else if (percentage >= 80.0) return 'B';
        else if (percentage >= 70.0) return 'C';
        else if (percentage >= 60.0) return 'D';
        else return 'F';
    }

    // Display formatted summary report
    void displayReport() const {
        cout << fixed << setprecision(2);
        cout << "\n========================================\n";
        cout << "       STUDENT GRADE TRACKER REPORT     \n";
        cout << "========================================\n";
        cout << "Student Name: " << studentName << "\n\n";
        cout << left << setw(20) << "Assignment" << setw(10) << "Score" << setw(10) << "Max" << endl;
        cout << "----------------------------------------\n";
        for (const auto& a : assignments) {
            cout << left << setw(20) << a.name << setw(10) << a.score << setw(10) << a.maxScore << endl;
        }
        cout << "----------------------------------------\n";
        double finalPct = calculateTotalPercentage();
        cout << "Final Percentage: " << finalPct << "%\n";
        cout << "Final Letter Grade: " << calculateLetterGrade(finalPct) << "\n";
        cout << "========================================\n";
    }
};

int main() {
    cout << "Initializing Student Grade Tracker...\n";
    
    // Create a student instance
    Student student("Francisco Medina");

    // Add sample assignments
    student.addAssignment("Homework 1", 18.0, 20.0);
    student.addAssignment("Midterm Exam", 85.0, 100.0);
    student.addAssignment("Lab Project", 45.0, 50.0);
    student.addAssignment("Quiz 1", 9.0, 10.0);

    // Display the full grade report
    student.displayReport();

    // Demonstrate binary search lookup feature
    string query = "Midterm Exam";
    cout << "\n[Binary Search Demo] Searching for assignment: '" << query << "'...\n";
    int index = student.searchAssignment(query);
    if (index != -1) {
        cout << "-> Assignment found successfully via binary search! (Index in sorted list: " << index << ")\n";
    } else {
        cout << "-> Assignment not found.\n";
    }

    return 0;
}