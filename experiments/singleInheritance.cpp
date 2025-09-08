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
}
};




class Orgnization:public Person{
    public:
    void info(){
        cout << name << " here to give interview"<<endl;
    }

};
int main(){
    Orgnization o;
    o.display_person("Badal" , 20);
    o.info();
    return 0;
}