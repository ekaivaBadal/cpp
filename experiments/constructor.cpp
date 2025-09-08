#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Default constructor
    Person() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called\n";
    }

    // Parameterized constructor
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called: ";
        cout << "My name is " << name << " and age is " << age << endl;
    }

    // Copy constructor
    Person(const Person &p) {
        name = p.name;
        age = p.age;
        cout << "Copy constructor called: ";
        cout << name << " and " << age << endl;
    }

    // Destructor
    ~Person() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Person p1;             // Default constructor
    Person p2("Badal", 19); // Parameterized constructor
    Person p3 = p2;         // Copy constructor

    return 0; // destructors are automatically called here
}
