#include <iostream>
#include <string>
using namespace std;

class User{
private:
    string name;
    int age;
    string pass;

public:
    User(string n,int a, string p) : name(n) , age(a) , pass(p) {}
    friend void printUser(User u);
};

void printUser(User u){
   
        cout << "Inside Friend" <<endl;
        cout<< "Name :" << u.name <<endl;
        cout << "Age :" << u.age <<endl;
        cout << "Password : " << u.pass<<endl;
    
}
int main(){
    User info("Badal" , 20, "badal@123@");
    printUser(info);

    return 0;
}