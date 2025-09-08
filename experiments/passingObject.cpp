#include <iostream>
#include <string>
using namespace std;
class Student{
    public:
    string name,gender,address;
    int age;
    
    void studentInfo(string n, string g, string a, int ag){
            name = n;
            gender = g;
            address = a;
            age = ag;
    }

    void showInfo(Student s){
        cout<<"My name is " << s.name << endl;
        cout<<"I am a " << s.gender << endl;
        cout<<"I live in her heart " << s.address << endl;
        cout<<"My age is "<<s.age<<endl;
    }

};
int main(){
    Student s1,s2;
    s1.studentInfo("Badal" , "Male" , "secret" , 20);
    s2.showInfo(s1);
    return 0;
}