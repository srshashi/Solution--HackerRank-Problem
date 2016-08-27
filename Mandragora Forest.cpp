/* Que is at:- HackerRank > HourRank9 > Mandragora Forest */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long t;
    cin >> t;

    while(t--){
        long n,num;
        long long p = 0,sum = 0;
        cin >> n;

        vector<long> a;

        for(int i=0; i<n; i++){
            cin >> num;
            a.push_back(num);
        }

    /* First sort the health point (input array) because according to question Garnet's pet
     * can eat one Mandragora, and each time S(his strength point) will increase by 1
     * so it is better to eat Mandragora having less health point */
        sort(a.begin(),a.end());

    /* We will find maximum experience by checking from last;
     * Means we first assume that Granet's pet has eaten all the Mandrogora except last one;
     * if it will give the max experience then we are done but if not we decrease by one, means
     * this time the pet has eaten first n-2 Mandragora, then we find the experience according
     * question if this will be max we are done if not we will proceed until S = 0; */
        p = a[a.size()-1]*n;
        sum = a[a.size()-1];
        long S = a.size() - 2;

        while(S>=0){
            sum += a[S];
            p = max(p,sum*(S + 1));
            S--;
        }

        cout << p << endl;
    }

    return 0;
}
