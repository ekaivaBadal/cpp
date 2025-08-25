#include <iostream>
#include <string>
using namespace std;
    class Person{
        public:
        string name;
        int age;

        Person(string n,int a){
            name = n;
            age = a;
            cout << "My name is "<< name << " and age is "<< age <<endl;
        }

        Person(const Person &p){
                name = p.name;
                age = p.age;
                cout << "copy of p  :";
                cout << name << " and "<< age<<endl;
        }

        ~Person(){
            name = "";
            age = 0;
            cout<< "destructor is called"<<endl;
        }
    };

int main(){
    Person p("badal", 19);
    Person p2 = p;
    // ~Person p3;
    return 0;
}