#include <iostream>

using namespace std;

unsigned long long int powerOfTwo(unsigned long long int n)
{
    while((n & (n-1)) != 0)
        n = n & (n-1);
    return n;
}


int main() {
    int t;
    cin >> t;

    while(t--){
        unsigned long long int n,k = 0;
        cin >> n;

        while(n != 1){
            k++;
            if((n & (n-1)) == 0)
                n = n/2;
            else
                n = n - powerOfTwo(n);
        }
        if(k % 2 == 0)
            cout << "Richard" << endl;
        else
            cout << "Louise" << endl;
    }
    return 0;
}
