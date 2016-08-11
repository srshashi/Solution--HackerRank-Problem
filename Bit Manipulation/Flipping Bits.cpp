#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
vector<int> deciToBin(long long N){
    long i;
    vector<int> bin(32);
    i = 31;
    while(N!=0) {
        bin[i]=(char)N%2;
        N/=2;
        i--;
    }

    return bin;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        unsigned long long x;
        string s = "";
        cin >> x;
        vector<int> b(deciToBin(x));

        for(unsigned int i=0;i<b.size();i++)
            s += (b[i] == 0 ? '1' : '0');

        x = std::bitset<32>(s).to_ulong();

        cout << x << endl;

    }
    return 0;
}
