#include <iostream>
#include <string>
using namespace std;
class Person{
public:
    string name;
    int age;
void display_person(string n , int a){
    name = n;
    age = a;
    // cout << "I am " << name<< " i am " <<age<<" years old" << endl;
    // cout << "I am here to Give Interview"<<endl;
}
};

class Employee{
    public:
    int empId;
    string postOfJob;

    void display_employee(int e,string p){
        empId = e;
        postOfJob = p;
        // cout << "My id is "<< empId << " my post is " << postOfJob <<endl;
        // cout << "I work in this company"<< endl;
    }
};


class Orgnization:public Person,public Employee{
    public:
    void info(){
        cout << name << " here to give interview"<<endl;
        cout << empId << " this ID of employee is very special" << endl;

    }

};
int main(){
    Orgnization o;
    o.display_person("Badal" , 20);
    o.display_employee(24024, "Hacker");
    o.info();
    return 0;
}