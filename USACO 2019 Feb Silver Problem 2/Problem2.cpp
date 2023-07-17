#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");

    int N, K;

    fin >> N >> K;

    vector<vector<int>> canvas(1000, vector<int>(1000, 0));

    for (int k = 0; k < N; k++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        canvas[x1][y1]++;
        canvas[x1][y2]--;
        canvas[x2][y1]--;
        canvas[x2][y2]++;
    }

    int count = 0;
    vector<vector<int>> prefix(1000, vector<int>(1000, 0));
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            prefix[i][j] += canvas[i][j];

            if (i != 0 && j != 0) {
                prefix[i][j] -= prefix[i-1][j-1];
            }

            if (i != 0) {
                prefix[i][j] += prefix[i-1][j];
            }

            if (j != 0) {
                prefix[i][j] += prefix[i][j-1];
            }

            if (prefix[i][j] == K) {
                count++;
            }
        }
    }

    fout << count << "\n";
}