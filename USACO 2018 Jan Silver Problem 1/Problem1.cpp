#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Slot {
    long long a, b;
};

bool cmp1(const Slot &first, const Slot &second) {
        return ((first.a != second.a) ? (first.a < second.a) : (first.b > second.b));
}

bool cmp2(const Slot &first, const Slot &second) {
        return ((first.a != second.a) ? (first.a < second.a) : (first.b < second.b));
}

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int N;
    fin >> N;

    vector<Slot> lifeguards;
    for (int i = 0; i < N; i++) {
        Slot times;
        fin >> times.a >> times.b;
        lifeguards.push_back(times);
    }

    sort(lifeguards.begin(), lifeguards.end(), cmp1);

    if (N == 1) {
        fout << 0 << "\n";
        return 0;
    }

    long long start = lifeguards[0].a, end = lifeguards[0].b, total_time = 0;
    long long min_time_lost = __LONG_LONG_MAX__;

    for (int i = 1; i < N; i++) {
        Slot lifeguard = lifeguards[i];
        if (lifeguard.a > end) {
            total_time += end - start;
            start = lifeguard.a;
            end = lifeguard.b;
        } else if (lifeguard.b > end) {
            end = lifeguard.b;
        } else {
            min_time_lost = 0;
        }
    }

    total_time += end - start;

    sort(lifeguards.begin(), lifeguards.end(), cmp2);

    if (min_time_lost == 0) {
        fout << total_time - min_time_lost << "\n";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        Slot thisguard = lifeguards[i], prevguard, nextguard;
        int time = 0;
        if (i == 0) {
            nextguard = lifeguards[i + 1];
            if (thisguard.b > nextguard.a) {
                time = nextguard.a - thisguard.a;
            } else {
                time = thisguard.b - thisguard.a;
            }
        } else if (i == N - 1) {
            prevguard = lifeguards[i - 1];
            if (thisguard.a < prevguard.b) {
                time = thisguard.b - prevguard.b;
            } else {
                time = thisguard.b - thisguard.a;
            }
        } else {
            prevguard = lifeguards[i - 1];
            nextguard = lifeguards[i + 1];
            if (thisguard.b > nextguard.a) {
                time += nextguard.a;
            } else {
                time += thisguard.b;
            }
            if (thisguard.a < prevguard.b) {
                time -= prevguard.b;
            } else {
                time -= thisguard.a;
            }
        }

        if (time < min_time_lost) {
            min_time_lost = time;
        }
    }

    fout << total_time - min_time_lost << "\n";
}