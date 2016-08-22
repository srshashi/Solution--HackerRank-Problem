/*Que :- HackerRank > Algorithim > BitManipulation > What next? */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t,n,m;
    cin >> t;

    while(t--){
        cin >> n;

        long long num;
        vector<long long > a;
        for(int i=0;i<n;i++){
            cin >> num;
            a.push_back(num);
        }
        vector<long long> b(5);
        int i = 0, j = 0;
        if(n%2 == 0)
            i = n - 4;
        else
            i = n - 3;
        j = 0;
        if(n == 2 || n == 1){
            j = 2;
            i += 2;
        }
        while(i < a.size()){
            b[j++] = a[i];
            a.erase(a.begin()+i);
        }

    /* Here logic is in the number of element in t = A[A.size()-3] for(n=even) or t = A[A.size()-2] for( n =odd)
     * case 1. t = 1;
     * case 2. t > 1;
     * for n = 2 or n = 1 can also be handled with this logic. */

        if(b[1] == 0)
            b[1]++;
        if(b[1] == 1){
            b[0]++;
            b[2]--;
            b[1] += b[3];
            b[3] = 0;

        }
        else{
            b[1]--;
            b[4] = b[2] - 1;
            b[2] = 1;
            b[3]++;
        }

        j = 0;
        for( i=0; i<5; i++)
            if(b[i] != 0)
                j++;
        n = a.size() + j;
        cout << n << endl;
        for(i = 0; i<a.size();i++)
            cout << a[i] << " ";
        for(i = 0; i< j; i++)
            cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}
