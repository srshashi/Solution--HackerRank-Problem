#include <iostream>


using namespace std;

int main()
{
    long q;
    cin >> q;

    /* Whole array can be divided into four different sequence.
     * 1. sequence - which satisfies (4*k - 1). All array element at this position have value equal to 0.
     * And XOR of any number with 0 is number itself, therefore no need to include this. */

    while(q--){
        unsigned long long l,r,j = 0,i = 0,ans = 0, k;
        cin >> l >> r;

    /* 2. sequence - which satisfies (4*k -3). All array element at this position have value equal to 1.
     *    And XOR of same number even number of times equal to 0. Here only need is to check if array element
     *    at these position, if had come odd number of times then, only need is ans ^= 1; */

        j = (l + 3)/4;
        i = (r + 3)/4;
        if((l + 3) == 4*j)
            j = l;
        else
            j = 4*(j + 1) - 3;
        if((r + 3) == 4*i)
            i = r;
        else
            i = 4*i - 3;

        if(j <= i)
            if(((i - j)/4 + 1)%2 != 0)
                ans ^= 1;

    /* 3. sequence = (4 * k), array element at this position have value equal to (4*k).
     *    So we need to do Xor with all this. But in this sequence every element at even position "Xor"
     *    with every element at odd position = 4; So we only need to count the number of element satisfying
     *    this sequence */

        j = (l + 0)/4;
        i = (r + 0)/4;
        if((l + 0) != 4*j)
            j = j + 1;

        k = i - j;
        if(i != 0 && j != 0)
            k++;
        if(j % 2 != 0){
            ans ^= (4*j);
            k--;
        }
        k = k % 4;
        if(k != 0){
                if(k % 2 != 0){
                    if(k == 3)
                        ans ^= 4;
                    ans ^= (4*i);
                }
                else
                    ans ^= 4;
            }

    /* 4. sequence = (4 * k - 2), array element at this position have value equal to (4*k -2 +1).
     *    So we need to do Xor with all this. But in this sequence every element at odd position "Xor"
     *    with every element at even position = 4; So we only need to count the number of element satisfying
     *    this sequence */

        j = (l + 2)/4;
        i = (r + 2)/4;
        if((l + 2) != 4*j)
           j = j + 1;

        k = i - j;
        if(i != 0 && j != 0)
            k++;
        if(j % 2 == 0){
            ans ^= (4*j - 1);
            k--;
        }
        k = k % 4;
        if(k != 0){
            if(k % 2 != 0){
                if(k == 3)
                    ans ^= 4;
                ans ^= ((4*i - 2) + 1);
            }
            else
                ans ^= 4;
        }

        cout << ans << endl;

    }
    return 0;
}
