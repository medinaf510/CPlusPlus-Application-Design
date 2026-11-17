#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Assignment {
    string name;
    double earned;
    double possible;
};

// --- MODULE 8: INPUT VALIDATION HELPERS ---
int getValidatedMenuChoice(int minOption, int maxOption) {
    int choice;
    while (true) {
        cout << "Enter choice (" << minOption << "-" << maxOption << "): ";
        if (cin >> choice && choice >= minOption && choice <= maxOption) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
        cout << "[Invalid Input] Please enter a valid number between " 
             << minOption << " and " << maxOption << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double getValidatedDouble(const string& prompt, double minVal, bool allowZero = true) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) {
            if (allowZero && val >= minVal) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return val;
            } else if (!allowZero && val > minVal) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return val;
            }
        }
        cout << "[Invalid Input] Please enter a valid number" 
             << (allowZero ? " (>= " : " (> ") << minVal << ").\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string getValidatedString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty() && input.find_first_not_of(' ') != string::npos) {
            return input;
        }
        cout << "[Invalid Input] Text cannot be empty.\n";
    }
}

// --- CORE GRADE CALCULATIONS ---
char calculateLetterGrade(double percentage) {
    if (percentage >= 90.0) return 'A';
    if (percentage >= 80.0) return 'B';
    if (percentage >= 70.0) return 'C';
    if (percentage >= 60.0) return 'D';
    return 'F';
}

void addAssignment(vector<Assignment>& grades) {
    cout << "\n--- Add New Assignment ---\n";
    string name = getValidatedString("Assignment Name: ");
    double earned = getValidatedDouble("Points Earned: ", 0.0, true);
    double possible = getValidatedDouble("Points Possible: ", 0.0, false);

    grades.push_back({name, earned, possible});
    cout << "Saved '" << name << "' successfully!\n";
}

void viewGrades(const vector<Assignment>& grades) {
    cout << "\n--- Current Grade Report ---\n";
    if (grades.empty()) {
        cout << "No assignments logged yet.\n";
        return;
    }

    double totalEarned = 0.0;
    double totalPossible = 0.0;

    cout << left << setw(25) << "Assignment" 
         << setw(15) << "Score" 
         << "Percentage\n";
    cout << string(52, '-') << "\n";

    for (const auto& a : grades) {
        double pct = (a.earned / a.possible) * 100.0;
        totalEarned += a.earned;
        totalPossible += a.possible;

        cout << left << setw(25) << a.name 
             << fixed << setprecision(1) << a.earned << "/" << a.possible << "\t"
             << pct << "%\n";
    }

    double overallPct = (totalEarned / totalPossible) * 100.0;
    cout << string(52, '-') << "\n";
    cout << "Overall Score: " << totalEarned << "/" << totalPossible 
         << " (" << fixed << setprecision(2) << overallPct << "%) - Letter Grade: " 
         << calculateLetterGrade(overallPct) << "\n";
}

// --- MODULE 9: MOCK AI FEATURE PROTOTYPE ---
void runAIGradeAdvisor(const vector<Assignment>& grades) {
    cout << "\n============================================\n";
    cout << "      AI SMART GRADE & STUDY ADVISOR        \n";
    cout << "============================================\n";

    if (grades.empty()) {
        cout << "[AI Insight] Log at least one assignment first so I can analyze your progress!\n";
        return;
    }

    double totalEarned = 0.0;
    double totalPossible = 0.0;
    double lowestPct = 101.0;
    string weakestAssignment = "";

    for (const auto& a : grades) {
        double pct = (a.earned / a.possible) * 100.0;
        totalEarned += a.earned;
        totalPossible += a.possible;

        if (pct < lowestPct) {
            lowestPct = pct;
            weakestAssignment = a.name;
        }
    }

    double currentPct = (totalEarned / totalPossible) * 100.0;
    char currentLetter = calculateLetterGrade(currentPct);

    cout << "Analyzing " << grades.size() << " assignment(s)...\n\n";
    cout << "1. Current Standing: " << fixed << setprecision(2) << currentPct 
         << "% (" << currentLetter << ")\n";

    cout << "2. Focus Area Identified: '" << weakestAssignment 
         << "' (" << fixed << setprecision(1) << lowestPct << "%)\n";

    cout << "3. AI Study Recommendation:\n   ";
    if (currentPct >= 90.0) {
        cout << "You are maintaining an A! Keep reviewing '" << weakestAssignment 
             << "' concepts to stay sharp for cumulative exams.\n";
    } else {
        // Calculate points needed on a hypothetical 100-point final/project to reach 90% (A)
        double targetPct = 90.0;
        double futurePossible = 100.0;
        double neededPoints = ((targetPct / 100.0) * (totalPossible + futurePossible)) - totalEarned;

        cout << "Prioritize reviewing topics from '" << weakestAssignment << "'.\n   ";
        if (neededPoints <= futurePossible && neededPoints > 0) {
            cout << "Goal Path: Scoring at least " << fixed << setprecision(1) << neededPoints 
                 << "/100 on your next major assignment will boost your grade to an A (90%)!\n";
        } else {
            cout << "Goal Path: Aim for 90%+ on remaining assignments to steadily raise your average.\n";
        }
    }
    cout << "============================================\n";
}

// --- MAIN APPLICATION LOOP ---
int main() {
    vector<Assignment> grades;
    int choice = 0;

    cout << "Welcome to Student Grade Tracker!\n";

    while (choice != 4) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Assignment\n";
        cout << "2. View All Grades\n";
        cout << "3. AI Study & Grade Advisor (Module 9 Prototype)\n";
        cout << "4. Exit\n";

        choice = getValidatedMenuChoice(1, 4);

        switch (choice) {
            case 1:
                addAssignment(grades);
                break;
            case 2:
                viewGrades(grades);
                break;
            case 3:
                runAIGradeAdvisor(grades);
                break;
            case 4:
                cout << "Exiting Grade Tracker. Good luck with your classes!\n";
                break;
        }
    }

    return 0;
}