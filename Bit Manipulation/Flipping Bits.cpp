/*
** Hackerrank
** Domains:: Algorithns:: Bit Manipulation: Flipping Bits
** Logic #2
*/

#include <iostream>
using namespace std;


int main() 
{
    unsigned int n, t;
    cin>>n;
    while(n--)
    {
        cin>>t;
        t = ~t;
        cout<<t<<endl;
    }
    return 0;
}
