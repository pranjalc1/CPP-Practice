#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");

    int N, K, B;
    fin >> N >> K >> B;

    vector<int> broken(N, 0);

    for (int i = 0; i < B; i++) {
        int index;
        fin >> index;
        index--;
        broken[index] = 1;
    }

    vector<int> psum(N, 0);

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            psum[i] = broken[i];
        } else {
            psum[i] = psum[i - 1] + broken[i];
        }
    }

    int minCount = INT32_MAX;
    for (int i = 0; i < N - K + 1; i++) {
        int count;
        if (i == 0) {
            count = psum[i + K - 1];
        } else {
            count = psum[i + K - 1] - psum[i - 1];
        }

        if (count < minCount) {
            minCount = count;
        }
    }

    fout << minCount << "\n";
}