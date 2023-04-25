#include <iostream>
#include <string>
#include "Project8.cpp" // Include your PeopleDB implementation

using namespace std;

void displayMenu() {
    cout << "Please enter your option:\n";
    cout << "1. Add a new person\n";
    cout << "2. Remove a person\n";
    cout << "3. Modify the database\n";
    cout << "4. Search for a person in the database\n";
    cout << "5. Display the database\n";
    cout << "6. Display the database sorted by names\n";
    cout << "7. Quit and save the database to a file\n";
    cout << "-->";
}

int main() {
    string filename;
    cout << "Welcome to the PeopleDB database system. Please enter the file that contains the initial people list:";
    cin >> filename;

    PeopleDB db(filename);
    cout << "The initial database built from the input file is displayed by its original order:\n";
    db.displayPreorder();

    int option;
    do {
        displayMenu();
        cin >> option;

        switch (option) {
            case 1: {
                People person;
                char addAnother;
                do {
                    cout << "To add, enter name and birthday (month day year):\n";
                    cin >> person;
                    db.addPerson(person);
                    cout << "Add another one? (Y/N) ";
                    cin >> addAnother;
                } while (tolower(addAnother) == 'y');
                break;
            }
            case 2: {
                People person;
                cout << "To remove, enter the name and birthday (month day year) of the person:\n";
                cin >> person;
                db.removePerson(person);
                break;
            }
            case 3: {
                People oldPerson, newPerson;
                cout << "To modify, enter the name and birthday (month day year) of the person to be modified:\n";
                cin >> oldPerson;
                cout << "Now, enter the new name and birthday (month day year):\n";
                cin >> newPerson;
                db.modifyPerson(oldPerson, newPerson);
                break;
            }
            case 4: {
                People person;
                cout << "To search, enter the name and birthday (month day year) of the person:\n";
                cin >> person;
                if (db.searchPerson(person)) {
                    cout << "Person found: " << person << endl;
                } else {
                    cout << "Person not found.\n";
                }
                break;
            }
            case 5: {
                cout << "Displaying the database:\n";
                db.displayPreorder();
                break;
            }
            case 6: {
                cout << "Displaying the database sorted by names:\n";
                db.displaySorted();
                break;
            }
            case 7: {
                string outputFile;
                cout << "Enter the output file name to save the database: ";
                cin >> outputFile;
                db.saveToFile(outputFile);
                break;
            }
            default: {
                cout << "Invalid option. Please try again.\n";
                break;
            }
        }

    } while (option != 7);

    string outputFile;
    cout << "Enter the output file name to save the database: ";
    cin >> outputFile;
    db.saveToFile(outputFile);

    return 0;
}
