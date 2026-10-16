#include <iostream>
#include <string>
using namespace std;

class User {
protected: 
    string username;
public: 
    User(string name) : username(name) {}
    string getUsername() { return username; }
    
    // Virtual function so students and admins can view dashboards differently
    virtual void showMenu() {
        cout << "Welcome, Student " << username << "!\n";
    }
};

class Admin : public User {
public: 
    Admin(string name) : User(name) {}
    
    void addRecord() { 
        cout << "[Admin] Adding a new student grade record...\n"; 
        // Logic to get student ID, name, and grade, then save to a file/array
    }
    
    void deleteRecord() { 
        cout << "[Admin] Deleting a student grade record...\n"; 
        // Logic to remove a student record by ID
    }

    void showMenu() override {
        cout << "Welcome, Professor " << username << " (Admin Mode)\n";
    }
};

// Added main function - this was missing!
int main() {
    // Example usage of the classes
    Admin admin("Dr. Smith");
    admin.showMenu();
    admin.addRecord();
    admin.deleteRecord();
    
    cout << "Admin username: " << admin.getUsername() << endl;
    
    return 0;
}
