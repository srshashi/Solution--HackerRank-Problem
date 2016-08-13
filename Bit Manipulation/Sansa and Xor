#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    /*          2 2
     *         3 4 3
     *        4 6 6 4
     *       5 8 9 8 5
     *    6 10 12 12 10 6
     *   ................... so on
     *   each layer shows the number of times, each element at that position in
     *   array comes according to questions; */

    while(t--){
        long n,ans = 0;
        cin >> n;
        vector<long> a(n);
        for(long i=0; i<n; i++)
            cin >> a[i];

        if(n % 2 != 0){
            long k = 0, i = 0;
            while((n - 2*k) > 0){
                i += (n - 2*k);
                if(i % 2 != 0){
                    ans ^= a[k];
                    if(k != (n/2))
                        ans ^= a[n-k-1];
                }
                ++k;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
