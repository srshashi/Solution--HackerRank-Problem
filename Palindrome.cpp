#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

long n;

// Check if string is palindrome
bool isPalindrome(const string &s){
    long j = 0;

    while(j < n/2 ){

        if(s[j] != s[n-j-1])
            return false;

        j++;
    }
    return true;
}

/* To make the palindrome bigger */

void bigger(string &s, long &k, const bool check[]){


        long i = 0;

        while(k > 0 && i < n/2){

            if(s[i] != '9' && s[n-1-i] != '9'){
        // if we have already traverse through char at i & n-1-i once so we need to do only by one
                if(check[i] == 1)
                    k--;
                else{
        /* if not, two case will arise
                            1. if k = 1 and check[i] = 0, in this case we cann't change, so we skip using continue
                            2. if k > 1 then we can change the char
        */
                    if(k > 1)
                        k -= 2;
                    else{
                        i++;
                        continue;
                    }
                }
                s[i] = s[n-1-i] = '9';
            }
            i++;
    }

    if(n%2 != 0)
        if(k > 0)
            s[n/2] = '9';
}

/* This function make the string into palindrome if possible in given k*/

void palindrome(string &s, long &k, bool check[]){

    long t = n/2 - 1;

    while(k > 0 && t >= 0){
        int c1 = s[n-t-1];
        int c2 = s[t];

        if(c1 < c2)
            s[n-t-1] = s[t];
        else if(c2 < c1)
            s[t] = s[n-t-1];

        if(c1 != c2){
            k--;
            check[t] = 1;
        }
        t--;
    }
}

int main()
{
    long k;
    cin >> n >> k;

    // to  keep track  if a char is traversed or not; We need to keep track of only half of element
    bool check[n/2];

    // initially all char are unchecked
    for(long i=0; i<n/2; i++)
        check[i] = 0;

    string s,get;
    cin >> s;

    palindrome(s,k,check);
    bigger(s,k,check);
    if(isPalindrome(s))
        cout << s << endl;
    else
        cout << "-1" << endl;

    return 0;
}
