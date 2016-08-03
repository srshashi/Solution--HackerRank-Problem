#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int lonelyinteger(vector < int > a) {
    int odd = a[0];
    for(unsigned int i=1; i<a.size();i++){
        odd ^= a[i];
    }

return odd;
}
int main() {
    int res;

    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = lonelyinteger(_a);
    cout << res;

    return 0;
}
