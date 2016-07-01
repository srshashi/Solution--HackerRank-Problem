/* Que is at :- HackerRank>Archive>May world codeSprint>Absolute Difference*/

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){
        long n,k;
        cin >> n >> k;
        vector<long> a;

    //to keep track of n: if we made changes to position i then explored[i] = 1;
        bool explored[n];
    // initializing false(0) to every n at position n && 0 to each no. in vector
        for(long i=0; i<n; i++){
            explored[i] = 0;
            a.push_back(0);
        }

       /* if changes has not been done at position i then:
        * according to this problem only two number can come at any position  'i'
        * if difference is k then only either k - position or k + position comes at particular position
        * now if k + position comes at 'i' then absolute(k - position) must go at 'k + i' position
        * Ex-  n = 6 k = 3
        *   position:       1   2   3   4   5   6
        *   Permutation:    4   5   6   1   2   3
        *   Difference:     3   3   3   3   3   3
        */

        for(long i=0;(i+k)<n; i++){
            if(explored[i] == 0){
                a[i] = i+1+k;
                a[i+k] = i+1;
                explored[i] = explored[i+k] = 1;
            }
        }

        /* Without applying above condition at every position we cannot create
         * required permutation. Hence, if explored[i] == 0 means there is position where required
         * condition is not satisfied therefore permutation is not possible
         */

        for(long i=0; i<n; i++){
            if(explored[i] == 0){
                cout << "-1";
                k = -1;
                break;
            }
        }

        /* If possible print the required permutation */

        if(k != -1){
            for(long i=0; i<n; i++)
                cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}
