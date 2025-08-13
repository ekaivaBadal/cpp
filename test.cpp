#include <iostream>
#include <cmath>

using namespace std;

class Prime {
public:
    void findPrime(int n) {
        for (int i = 2; i <= n; i++) {
            bool isPrime = true;
            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                cout << i << endl;
            }
        }
    }
};

int main() {
    Prime pr;
    pr.findPrime(29);
    return 0;
}
