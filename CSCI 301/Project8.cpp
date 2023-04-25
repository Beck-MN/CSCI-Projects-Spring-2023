#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <utility>
#include "BinarySearchTree.h" // Include your BinarySearchTree implementation

using namespace std;

class Date {
    int month;
    int day;
    int year;

public:
    // Getters and Setters
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    void setYear(int y) { year = y; }

    // Operator Overloading
    friend istream& operator>>(istream& is, Date& date);
    friend ostream& operator<<(ostream& os, const Date& date);
};

istream& operator>>(istream& is, Date& date) {
    is >> date.month >> date.day >> date.year;
    return is;
}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.month << '/' << date.day << '/' << date.year;
    return os;
}

class People {
    string name;
    Date birthday;

public:
    // Getters and Setters
    const string& getName() const { return name; }
    const Date& getBirthday() const { return birthday; }

    void setName(const string& n) { name = n; }
    void setBirthday(const Date& b) { birthday = b; }

    // Operator Overloading
    friend istream& operator>>(istream& is, People& person);
    friend ostream& operator<<(ostream& os, const People& person);

    bool operator==(const People& other) const { return name == other.name; }
    bool operator<(const People& other) const { return name < other.name; }
    bool operator>(const People& other) const { return name > other.name; }
};

istream& operator>>(istream& is, People& person) {
    is >> person.name >> person.birthday;
    return is;
}

ostream& operator<<(ostream& os, const People& person) {
    os << person.name << " " << person.birthday;
    return os;
}

class PeopleDB {
    BinarySearchTree<People> db;

public:
    PeopleDB(string filename) {
        ifstream file("DB1.txt");
        People person;

        while (file >> person) {
            db.add(person);
        }

        file.close();
    }

    void addPerson(const People& person) {
        db.add(person);
    }

    void removePerson(const People& person) {
        db.remove(person);
    }

    void modifyPerson(const People& oldPerson, const People& newPerson) {
        db.remove(oldPerson);
        db.add(newPerson);
    }

    bool searchPerson(const People& person) {
        return db.contains(person);
    }

    void displayPreorder() {
        db.preorderTraverse(toScreen);
    }

    void displaySorted() {
        db.inorderTraverse(toScreen);
    }

    static void toScreen(People& p) {
        cout << p << endl;
    }

    void saveToFile(string filename) {
        ofstream file("DB1.txt");
        
        db.preorderTraverse(toFile);
        file.close();
    }

    static void toFile(People& p) {
        fsOut << p << endl;
    }

private:
    static ofstream fsOut;
};

ofstream PeopleDB::fsOut;
