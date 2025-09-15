#include <iostream>
using namespace std;

class Complex{
    private:
    int real,imag;

    public:
    Complex(int r =0, int i = 0): real(r),imag(i) {};

    Complex operator-(const Complex& other){
        return Complex(real - other.real, imag - other.imag);
    }

 void print() {
        cout << real << " + " << imag << "i" << endl;
    }

};
int main(){
    Complex c1(5, 3);  // 5 + 3i
    Complex c2(2, 1);  // 2 + 1i

    // Subtract the complex numbers using the overloaded '-' operator
    Complex result = c1 - c2;

    // Print the result
    cout << "Result of subtraction: ";
    result.print();

    return 0;
    
}