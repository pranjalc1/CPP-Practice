#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<long long>> original_coords(2, vector<long long>(N, 0));
    set<long long> unique_x, unique_y;
    vector<map<long long, int>> original_new(2, map<long long, int>());

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        original_coords[0][i] = a;
        original_coords[1][i] = b;

        unique_x.insert(a);
        unique_y.insert(b);
    }

    vector<vector<long long>> ordered_coords{vector<long long>(unique_x.begin(), unique_x.end()),
                                       vector<long long>(unique_y.begin(), unique_y.end())};

    for (int i = 0; i < N; i++) {
        original_new[0][ordered_coords[0][i]] = i;
        original_new[1][ordered_coords[1][i]] = i;
    }

    vector<vector<int>> pasture(N, vector<int>(N, 0));
    vector<vector<int>> coords(N, vector<int>(2, 0));

    for (int i = 0; i < N; i++) {
        coords[i] = {original_new[0][original_coords[0][i]], original_new[1][original_coords[1][i]]};
        pasture[coords[i][0]][coords[i][1]] += 1;
    }
    
    vector<vector<int>> total_coords = pasture;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j != 0) {
                total_coords[i][j] += total_coords[i][j - 1];
            }
            if (i != 0) {
                total_coords[i][j] += total_coords[i - 1][j];
            }
            if (i != 0 && j != 0) {
                total_coords[i][j] -= total_coords[i - 1][j - 1];
            }
        }
    }

    long long count = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            vector<int> coord1 = coords[i], coord2 = coords[j];

            int x1 = min(coord1[0], coord2[0]), x2 = max(coord1[0], coord2[0]);
            int y1 = min(coord1[1], coord2[1]), y2 = max(coord1[1], coord2[1]);

            int below, above;
            if (y1 == 0) {
                below = 0;
            } else {
                below = total_coords[x2][y1 - 1] - total_coords[x1][y1 - 1];
            }

            if (y2 == N - 1) {
                above = 0;
            } else {
                above = total_coords[x2][N - 1] - total_coords[x2][y2] - total_coords[x1][N - 1] + total_coords[x1][y2];
            }

            count += (below + 1) * (above + 1);
        }
    }

    count += N + 1;

    cout << count << "\n";
}