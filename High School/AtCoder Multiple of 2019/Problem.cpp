#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string S;
    cin >> S;
    int length = S.size();

    vector<int> modulo(length, 0);
    vector<int> tenPowers;

    int power = 0;
    while (true) {
        if (power == 0) {
            tenPowers.push_back(1);
        } else {
            int tenPower = (10 * tenPowers[power - 1]) % 2019;
            if (tenPower == 1) {
                break;
            } else {
                tenPowers.push_back(tenPower);
            }
        }
        power++;
    }

    map<int, int> repeats;

    for (int i = length - 1; i >= 0; i--) {
        int num = (int) (S[i] - 48);
        if (i == length - 1) {
            modulo[i] = num % 2019;
        } else {
            modulo[i] = (num * tenPowers[(length - 1 - i) % tenPowers.size()] + modulo[i + 1]) % 2019;
        }
        repeats[modulo[i]];
        repeats[modulo[i]]++;
    }

    long long count = 0;
    if (repeats.count(0) > 0) {
        count += repeats[0];
    }

    for (auto entry : repeats) {
        int size = entry.second;
        count += size * (size - 1) / 2;
    }

    cout << count << "\n";
}