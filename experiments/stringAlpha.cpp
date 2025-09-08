#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    string nextT;

    for(int i = 0;i< str.size() ; i++){
        if(str[i] == 'z'){
            nextT += 'a';
        }else if(str[i] == ' ' ){
            nextT += ' ';
        }else{
        nextT += char(str[i]+1);
        }
    }
    cout<< "simple : " << str<<endl;
    cout << "next : " << nextT<<endl;
return 0;
}