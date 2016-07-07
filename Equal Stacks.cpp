/* Question is at :- HackerRank>World CodeSprint#4>Equal Stack*/

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> a,b,c;
    long A = 0, B = 0, C = 0, x = 0, num[3];
    int height = 0;

    cin >> num[0] >> num[1] >> num[2];

    /* Input of stack first plus sum of all heights*/
    while(num[0]--){
        cin >> height;
        a.push_back(height);
        A += height;
    }

    /* Input of stack second plus sum of all heights*/
    while(num[1]--){
        cin >> height;
        b.push_back(height);
        B += height;
    }

    /* Input of stack third plus sum of all heights*/
    while(num[2]--){
        cin >> height;
        c.push_back(height);
        C += height;
    }

    list<int> :: iterator itr1, itr2, itr3;

    itr1 = a.begin();
    itr2 = b.begin();
    itr3 = c.begin();

    while(A != B || B != C){
        /* First step is to find the stack of max height 4
           because we need to minimize that height according to question */
        x = max(A,B);
        x = max(x,C);

        /* Finding required stack and then deleting(incrementing our pointer to next)*/
        if(A == x){
            A -=(*itr1);
            ++itr1;
        }
        if(B == x){
            B -= (*itr2);
            ++itr2;
        }
        if(C == x){
            C -= (*itr3);
            ++itr3;
        }
    }

    /* Now all the stacks are of same height*/
    cout << A << endl;

    return 0;
}
