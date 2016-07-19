/* Que is at :- HackerRank > HourRank9 > Fair Ration*/

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

    /* Logic behind this code is after all distribution according question all loaves will be even
     * only if, number of person having odd number of loaves initially is even
     * For example: n = 5
                    2 3 4 5 6
                    Here, only two person have odd number of loaves initially; Therefore, in
     * in last even distribution is possible;
     * Where as if, for example: n = 5
                                 2 3 4 5 7
                                 Here, we cannot distribute them according to question because initially
     * 3 person have odd number of loaves */

    while(i<N){
        if(B[i] % 2 != 0){
            odd++;          // finds total number of odds;
            i++;
     /* Whenever total number of odd (variable) is even means distribution is possible */
            if(odd % 2 == 0){
                q += ++p;
                p = 0;
            }

            while((B[i] % 2 == 0) && (i<N) && (odd % 2 != 0)){
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
