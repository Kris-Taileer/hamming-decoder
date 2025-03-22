#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calcSyn(const vector<int>& received) {
    int syn = 0;
    for (int i = 0; i < 4; ++i) {
        int parity_pos = 1 << i; // 1, 2, 4, 8
        int parity = 0;
        for (int j = 1; j <= 15; ++j) {
            if (j & parity_pos) {
                parity ^= received[j - 1];
            }
        }
        if (parity) syn |= parity_pos;
    }
    return syn;
}

int main() {
    string input;
    cin >> input;
    vector<int> received(15);
    for (int i = 0; i < 15; ++i) {
        received[i] = input[i] - '0';
    }

    int syndrome = calcSyn(received);

    if (syndrome != 0) {
        received[syndrome - 1] ^= 1;
    }

    string data;
    for (int i = 1; i <= 15; ++i) {
        if (!(i == 1,  i == 2,  i == 4 || i == 8)) {
            data += received[i - 1] + '0';
        }
    }

    cout << data << endl;

    return 0;
}




