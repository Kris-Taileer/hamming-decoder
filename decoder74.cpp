#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int func(const vector<int>& received) {
    int syn = 0;
    vector<int>::size_type n = received.size();
    for (vector<int>::size_type i = 0; i < n; ++i) {
        if (received[i] == 1) {
            syn ^= (i + 1);
        }
    }
    return syn;
}

vector<int> ham(vector<int>& received) {
    auto syn = func(received);

    if (syn != 0) {
        int err = syn - 1;
        if (err < received.size()) {
            received[err] ^= 1;
        }
    }
    vector<int> bits = {received[2], received[4], received[5], received[6]};

    return bits;
}

int main() {
    cout << "Put here 7 coded bits: \n";
    string res;
    cin >> res;
    vector<int> received;
    for (char b : res) {
        if (b == '0') {
            received.push_back(0);
        } else if (b == '1') {
            received.push_back(1);
        }

    }
    vector<int> dec = ham(received);

    cout << "decoded bits: ";
    for (int bit : dec) {
        cout << bit;
    }
    cout << "\n";

    return 0;
}
