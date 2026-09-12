#include <iostream>
#include <limits>

// Function declarations for student grade tracker features
void addAssignmentScore() {
    std::cout << "\n[Add Assignment Score] Score entry saved successfully.\n";
}

void viewScores() {
    std::cout << "\n[View Scores] Displaying recorded assignment scores...\n";
}

void calculateTotalPercentage() {
    std::cout << "\n[Calculate Total Percentage] Calculating current course average...\n";
}

void outputFinalGrade() {
    std::cout << "\n[Output Final Grade] Computing final letter grade...\n";
}

// Function to print menu options cleanly
void displayMenu() {
    std::cout << "\n==============================\n";
    std::cout << "    STUDENT GRADE TRACKER     \n";
    std::cout << "==============================\n";
    std::cout << "1. Add Assignment Score\n";
    std::cout << "2. View Recorded Scores\n";
    std::cout << "3. Calculate Total Percentage\n";
    std::cout << "4. Output Final Letter Grade\n";
    std::cout << "5. Exit\n";
    std::cout << "------------------------------\n";
    std::cout << "Enter your choice (1-5): ";
}

int main() {
    int choice = 0;

    // Loop continues until the user selects option 5 (Exit)
    do {
        displayMenu();

        // Input validation: handles non-numeric input safely
        if (!(std::cin >> choice)) {
            std::cout << "\nError: Invalid input. Please enter a valid number.\n";
            std::cin.clear(); // Clear the stream error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear invalid buffer
            continue;
        }

        // Switch/case routing each option to its corresponding function
        switch (choice) {
            case 1:
                addAssignmentScore();
                break;
            case 2:
                viewScores();
                break;
            case 3:
                calculateTotalPercentage();
                break;
            case 4:
                outputFinalGrade();
                break;
            case 5:
                std::cout << "\nExiting Student Grade Tracker. Goodbye!\n";
                break;
            default:
                std::cout << "\nError: Invalid option. Please enter a number between 1 and 5.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}