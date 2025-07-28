#include <iostream>
using namespace std;

int main(){
    int prev=0,current=1,total;

    cout << "How many number of sequence do you want ? : ";
    cin >> total;
    cout << prev << endl;
    cout << current<< endl;
    for(int i = 1;i<total;i++){
        int c = prev + current;
        
        cout << c <<endl;
        prev = current;
        current = c;

    }
return 0;
}
