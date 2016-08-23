/* Que is at:- World CodeSprint #4 > A OR B */

#include <iostream>


using namespace std;

string convertToBin(const char &a){
    if(a == '0')
        return "0000";
    else if(a == '1')
        return "0001";
    else if(a == '2')
        return "0010";
    else if(a == '3')
        return "0011";
    else if(a == '4')
        return "0100";
    else if(a == '5')
        return "0101";
    else if(a == '6')
        return "0110";
    else if(a == '7')
        return "0111";
    else if(a == '8')
        return "1000";
    else if(a == '9')
        return "1001";
    else if(a == 'A')
        return "1010";
    else if(a == 'B')
        return "1011";
    else if(a == 'C')
        return "1100";
    else if(a == 'D')
        return "1101";
    else if(a == 'E')
        return "1110";
    return "1111";
}

char convertToHex(const string &a){
    if(a == "0000")
        return '0';
    else if(a == "0001")
        return '1';
    else if(a == "0010")
        return '2';
    else if(a == "0011")
        return '3';
    else if(a == "0100")
        return '4';
    else if(a == "0101")
        return '5';
    else if(a == "0110")
        return '6';
    else if(a == "0111")
        return '7';
    else if(a == "1000")
        return '8';
    else if(a == "1001")
        return '9';
    else if(a == "1010")
        return 'A';
    else if(a == "1011")
        return 'B';
    else if(a == "1100")
        return 'C';
    else if(a == "1101")
        return 'D';
    else if(a == "1110")
        return 'E';
    return 'F';
}

string hexToBinary(const string &A){
    unsigned long i = 0;
    string s;

    while(i<A.size()){
        s += convertToBin(A[i]);
        i++;
    }

    return s;
}


string binaryToHex(const string &A){
    unsigned long i = 0;
    string s,sub;

    while(i<A.size()){
        sub = A.substr(i,4);
        s += convertToHex(sub);
        i += 4;
    }

    return s;
}

int main()
{
    int q;
    cin >> q;

    while(q--){
        long k;
        string A, B, C;

        cin >> k;
        cin >> A >> B >> C;

        A = hexToBinary(A);
        B = hexToBinary(B);
        C = hexToBinary(C);

        unsigned long i = A.size() - 1;
        while(i >=0 && k > 0){
            if(C[i] == '1'){
                    if(A[i] == '0' && B[i] == '0'){
                        B[i] = '1';
                        k--;
                    }
            }
            else{
                if(A[i] == '1' && k != 0){
                    A[i] = '0';
                    k--;
                }
                if(B[i] == '1' && k != 0){
                    B[i] = '0';
                    k--;
                }
            }
            i--;
        }

        for(unsigned long j=0; j< A.size() && k != 0; j++){
            if(A[j] == '1'){
                if(B[j] == '1'){
                    A[j] = '0';
                    k--;
                }
                else if(k > 1){
                    A[j] = '0';
                    B[j] = '1';
                    k -= 2;
                }
            }
        }

        unsigned long j = 0;
        while(j < A.size()){
            bool a = (bool)(A[j] - 48);
            bool b = (bool)(B[j] - 48);
            bool c = (bool)(C[j] - 48);
            bool d = a  | b;
            if(d != c)
                break;
            j++;
        }
        i = A.size();

        A = binaryToHex(A);
        B = binaryToHex(B);

        if(j == i){
            while(A[0] == '0'  &&  A.size()  !=  1)
                A.erase(0,1);
            while(B[0] == '0'  &&  B.size()  !=  1)
                B.erase(0,1);

            cout << A << endl << B << endl;
        }
        else
            cout << "-1" << endl;

    }
    return 0;
}
