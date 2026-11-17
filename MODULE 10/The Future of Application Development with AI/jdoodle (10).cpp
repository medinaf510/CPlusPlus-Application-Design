#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>

using namespace std;

struct Assignment {
    string name;
    double earned;
    double possible;
};

class StudentGradeTracker {
private:
    vector<Assignment> assignments;

    // Step 5 & 6: Input validation & security/correctness helpers
    double getValidDouble(const string& prompt, double minVal, bool allowZero = true) {
        double value;
        while (true) {
            cout << prompt;
            if (cin >> value) {
                if ((allowZero && value >= minVal) || (!allowZero && value > minVal)) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return value;
                }
            }
            cout << "[Error] Please enter a valid number"
                 << (allowZero ? " (>= " : " (> ") << minVal << ").\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    string getValidString(const string& prompt) {
        string text;
        while (true) {
            cout << prompt;
            getline(cin, text);
            if (!text.empty() && text.find_first_not_of(' ') != string::npos) {
                return text;
            }
            cout << "[Error] Assignment name cannot be blank.\n";
        }
    }

    char getLetterGrade(double pct) const {
        if (pct >= 90.0) return 'A';
        if (pct >= 80.0) return 'B';
        if (pct >= 70.0) return 'C';
        if (pct >= 60.0) return 'D';
        return 'F';
    }

public:
    // Step 4: Core feature — Add assignment
    void addAssignment() {
        cout << "\n--- Add Assignment ---\n";
        string name = getValidString("Assignment Name: ");
        double earned = getValidDouble("Points Earned: ", 0.0, true);
        double possible = getValidDouble("Points Possible: ", 0.0, false);

        assignments.push_back({name, earned, possible});
        cout << "Added '" << name << "' (" << earned << "/" << possible << ").\n";
    }

    // Step 4 & 6: Deterministic grade report
    void viewReport() const {
        cout << "\n--- Grade Report ---\n";
        if (assignments.empty()) {
            cout << "No assignments recorded yet.\n";
            return;
        }

        double totalEarned = 0.0;
        double totalPossible = 0.0;

        cout << left << setw(24) << "Assignment"
             << setw(16) << "Points"
             << "Percentage\n";
        cout << string(50, '-') << "\n";

        for (const auto& a : assignments) {
            double pct = (a.earned / a.possible) * 100.0;
            totalEarned += a.earned;
            totalPossible += a.possible;

            cout << left << setw(24) << a.name
                 << fixed << setprecision(1) << a.earned << "/" << a.possible << "\t\t"
                 << pct << "%\n";
        }

        double overall = (totalEarned / totalPossible) * 100.0;
        cout << string(50, '-') << "\n";
        cout << "Current Average: " << fixed << setprecision(2) << overall
             << "% (" << getLetterGrade(overall) << ")\n";
    }

    // Step 3: AI-assisted grade trajectory & study advisor
    void runAIGradeAdvisor() const {
        cout << "\n--- AI Study & Target Grade Advisor ---\n";
        if (assignments.empty()) {
            cout << "Log at least one assignment so the AI advisor can analyze your progress.\n";
            return;
        }

        double totalEarned = 0.0;
        double totalPossible = 0.0;
        double lowestPct = 101.0;
        string weakestName;

        for (const auto& a : assignments) {
            double pct = (a.earned / a.possible) * 100.0;
            totalEarned += a.earned;
            totalPossible += a.possible;
            if (pct < lowestPct) {
                lowestPct = pct;
                weakestName = a.name;
            }
        }

        double currentAvg = (totalEarned / totalPossible) * 100.0;
        cout << "Current Standing : " << fixed << setprecision(2) << currentAvg
             << "% (" << getLetterGrade(currentAvg) << ")\n";
        cout << "Weakest Area     : '" << weakestName << "' ("
             << fixed << setprecision(1) << lowestPct << "%)\n";

        if (currentAvg >= 90.0) {
            cout << "AI Recommendation: Great work maintaining an A! Review '"
                 << weakestName << "' before finals to lock in your grade.\n";
        } else {
            double nextExamPoints = 100.0;
            double needed = (0.90 * (totalPossible + nextExamPoints)) - totalEarned;
            cout << "AI Recommendation: Focus study time on topics from '" << weakestName << "'.\n";
            if (needed <= nextExamPoints && needed > 0) {
                cout << "Target Forecast  : Score at least " << fixed << setprecision(1)
                     << needed << "/100 on your next major assignment to reach an A (90%).\n";
            } else {
                cout << "Target Forecast  : Aim for 90%+ on remaining coursework to raise your average.\n";
            }
        }
    }

    // Step 7: Improve design — Long-term file storage
    void saveToFile() const {
        ofstream outFile("grades_backup.txt");
        if (!outFile) {
            cout << "[Error] Unable to open file for saving.\n";
            return;
        }
        for (const auto& a : assignments) {
            outFile << a.name << "," << a.earned << "," << a.possible << "\n";
        }
        outFile.close();
        cout << "Saved " << assignments.size() << " assignment(s) to grades_backup.txt.\n";
    }
};

int main() {
    StudentGradeTracker tracker;
    int choice = 0;

    cout << "=========================================\n";
    cout << "   Student Grade Tracker (Module 10)     \n";
    cout << "=========================================\n";

    while (choice != 5) {
        cout << "\n1. Add Assignment\n";
        cout << "2. View Grade Report\n";
        cout << "3. AI Study & Target Grade Advisor\n";
        cout << "4. Save Grades to File\n";
        cout << "5. Exit\n";
        cout << "Select an option (1-5): ";

        if (!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "[Error] Invalid choice. Enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                tracker.addAssignment();
                break;
            case 2:
                tracker.viewReport();
                break;
            case 3:
                tracker.runAIGradeAdvisor();
                break;
            case 4:
                tracker.saveToFile();
                break;
            case 5:
                cout << "Exiting Student Grade Tracker. Goodbye!\n";
                break;
        }
    }

    return 0;
}