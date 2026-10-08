#include <iostream>
#include <string>
using namespace std;

class Assignment {
private:
    string name;
    double pointsPossible;
    double score;

public:
    // Constructor
    Assignment(string assignmentName, double maxPoints, double earnedScore) {
        name = assignmentName;
        pointsPossible = maxPoints;
        score = earnedScore;
    }

    // Calculates and returns the percentage grade
    double getPercentage() {
        if (pointsPossible == 0) return 0.0;
        return (score / pointsPossible) * 100.0;
    }

    // Determines the letter grade based on percentage
    char getLetterGrade() {
        double pct = getPercentage();
        if (pct >= 90.0) return 'A';
        if (pct >= 80.0) return 'B';
        if (pct >= 70.0) return 'C';
        if (pct >= 60.0) return 'D';
        return 'F';
    }

    // Displays details for this assignment
    void displayAssignment() {
        cout << "Assignment: " << name << endl;
        cout << "Score: " << score << " / " << pointsPossible << endl;
        cout << "Percentage: " << getPercentage() << "%" << endl;
        cout << "Grade: " << getLetterGrade() << endl;
    }

    // Getters and Setters
    string getName() {
        return name;
    }

    void setScore(double newScore) {
        score = newScore;
    }
};

int main() {
    // Creating assignment objects for the Grade Tracker
    Assignment assignment1("Midterm Exam", 100.0, 92.5);
    Assignment assignment2("C++ Lab 1", 50.0, 43.5);

    assignment1.displayAssignment();
    cout << endl;
    assignment2.displayAssignment();

    return 0;
}