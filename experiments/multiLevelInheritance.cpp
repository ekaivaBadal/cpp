#include <iostream>
#include <string>
using namespace std;
class Person{
public:
    string name;
    int age;
void basicInfo(string n , int a){
    name = n;
    age = a;
}
};

class SkillsAndInfo:public Person{
    public:
    string softSkill;
    string techSkill;

    void skillsInfo(string e,string p){
        softSkill = e;
        techSkill = p;
    }
};


class Orgnization:public SkillsAndInfo{
    public:
    void info(){
        cout << name << " here to give interview"<<endl;
        cout << "his/her age is " << age <<endl;
        cout << "he/she have the soft skill "<< softSkill << " and tech skill " <<techSkill << endl;
    }

};
int main(){
    Orgnization o;
    o.basicInfo("Badal" , 20);
    o.skillsInfo("communication and leadership" , "React , js etc");
    o.info();
    return 0;
}