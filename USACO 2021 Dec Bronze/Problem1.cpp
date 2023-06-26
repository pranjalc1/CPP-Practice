#include <iostream>
#include <vector>
#include <string>

using namespace std;

// int right(vector<char> cows, int i, int N) {
//     if (cows[i+1] == cows[i]) {
//         return 0;
//     } else {
//         int j = i + 2;
//         int count = 0;
//         while (cows[j] != cows[i] && j < N) {
//             count++;
//             j++;
//         }
//         return count;
//     }
// }

// int left(vector<char> cows, int i, int N) {
//     if (cows[i] == cows[i-1]) {
//         return 0;
//     } else {
//         int j = i - 2;
//         int count = 0;
//         while (cows[j] != cows[i] && j >= 0) {
//             count++;
//             j--;
//         }
//         return count;
//     }
// }

// int middle(vector<char> cows, int i, int N) {
//     if (cows[i] == cows[i-1] || cows[i] == cows[i+1]) {
//         return 0;
//     } else {
//         int left = 0;
//         int right = 0;
//         for (int k = i-1; k >= 0; k--) {
//             if (cows[k] != cows[i]) {
//                 left++;
//             } else {
//                 break;
//             }
//         }

//         for (int k = i+1; k < N; k++) {
//             if (cows[k] != cows[i]) {
//                 right++;
//             } else {
//                 break;
//             }
//         }
//         return left * right;
//     }
// }

int main() {
    long long N;
    cin >> N;

    vector<char> cows(N);

    for (long long i = 0; i < N; i++) {
        cin >> cows[i];
    }

    // int count = 0;
    // vector<int> switches;

    // for (int i = 0; i < N-1; i++) {
    //     if (cows[i] != cows[i+1]) {
    //         switches.push_back(i);
    //     }
    // }

    // // LEFT
    // for (int i = 0; i < switches.size(); i++) {
    //     int current = switches[i];
    //     if (i == 0) {
    //         if (current >= 1) {
    //             count += current;
    //         }
    //     } else {
    //         int before = switches[i-1];
    //         if (current - before >= 2) {
    //             count += current - before - 1;
    //         }
    //     }
    // }

    // // RIGHT
    // for (int i = 0; i < switches.size(); i++) {
    //     int current = switches[i];
    //     if (i == switches.size() - 1) {
    //         if (N - current >= 3) {
    //             count += N - current - 2;
    //         }
    //     } else {
    //         int after = switches[i+1];
    //         if (after - current >= 2) {
    //             count += after - current - 1;
    //         }
    //     }
    // }

    // // MIDDLE
    // vector<int> quick_switches_places;
    // for (int i = 0; i < switches.size() - 1; i++) {
    //     if (switches[i + 1] - switches[i] == 1) {
    //         quick_switches_places.push_back(i+1);
    //     }
    // }

    // for (int i = 0; i < quick_switches_places.size(); i++) {
    //     if (quick_switches_places[i] == 1) {
    //         count += (switches[0] + 1) * ((switches.size() > 2 ? switches[2] : N-1) - switches[1]);
    //     } else if (quick_switches_places[i] == switches.size() - 1) {
    //         count += (switches[switches.size() - 2] - switches[switches.size() - 3]) * (N-1 - switches[switches.size() - 1]);
    //     } else if (switches.size() >= 4) {
    //         int k = quick_switches_places[i];
    //         count += (switches[k-1] - switches[k-2]) * (switches[k+1] - switches[k]);
    //     }
    // }

    // int count = 0;

    // for (int i = 0; i < N; i++) {
    //     if (i == 0) {
    //         count += right(cows, i, N);
    //     } else if (i == N-1) {
    //         count += left(cows, i, N);
    //     } else {
    //         count += left(cows, i, N);
    //         count += right(cows, i, N);
    //         count += middle(cows, i, N);
    //     }
    // }

    long long count = 0;

    for (long long i = 0; i < N; i++) {
        long long left = 0;
        long long right = 0;
        for (long long k = i-1; k >= 0; k--) {
            if (cows[k] != cows[i]) {
                left++;
            } else {
                break;
            }
        }

        for (long long k = i+1; k < N; k++) {
            if (cows[k] != cows[i]) {
                right++;
            } else {
                break;
            }
        }

        count += left * right;
        count += left >= 2 ? left-1 : 0;
        count += right >= 2 ? right-1 : 0;
    }

    cout << count << "\n";
}