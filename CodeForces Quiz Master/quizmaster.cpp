#include <iostream>
#include <cmath>

using namespace std;

vector<int> divisors(int k) {
    vector<int> divs;
    for (int i = 1; i <= (int) sqrt(k) + 1; i++) {
        if (k % i == 0) {
            divs.push_back(i);
            divs.push_back(k / i);
        }
    }
    return divs;
}

int main() {
    int t, n, m;
    cin >> t;

    string OUT = "";

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        vector<int> a(n, 0);
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            a[j] = k;
        }
        int left = 0, right = 1;
        int countDone = m;
        vector<int> donePerTopic(m, 0);
        int minMaxDiff = INT32_MAX;
        int min = INT32_MAX, max = INT32_MIN;

        while (right <= n && left < right) {
            if (!countDone && right != n) {
                vector<int> divs = divisors(a[right++ - 1]);
                for (int k : divs) {
                    if (!donePerTopic[k]) {
                        countDone--;
                    }
                    donePerTopic[k - 1]++;
                }
            } else {
                vector<int> divs = divisors(a[left++ - 1]);
                for (int k : divs) {
                    if (donePerTopic[k] == 1) {
                        countDone++;
                    }
                    donePerTopic[k - 1]--;
                }
            }

            if (!countDone) {
                if (right - left < minMaxDiff) {
                    minMaxDiff = right - left;
                }
            }
        }

        if (minMaxDiff == INT32_MAX) {
            OUT += "-1\n";
        } else {
            OUT += to_string(minMaxDiff) + "\n";
        }
    }

    cout << OUT;
}