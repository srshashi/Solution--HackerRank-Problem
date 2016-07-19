#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> B(N);
    for(int B_i = 0;B_i < N;B_i++){
       cin >> B[B_i];
    }
    int i = 0, odd = 0, p = 0, q = 0;
    while(i<N){
        if(B[i] % 2 != 0){
            odd++;
            i++;
            if(odd % 2 == 0)
                q = ++p;
            while(B[i] % 2 == 0 && i<N){
                p++;
                i++;
            }
        }
        else
            i++;
    }
    if(odd % 2 == 0)
        cout << 2*q << endl;
    else
        cout << "NO" << endl;
    return 0;
}
