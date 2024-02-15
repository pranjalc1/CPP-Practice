#include <iostream>
#include <set>
#include <map>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int N, M = 0;
    fin >> N;

    set<int> outputs;
    map<int, int> cows;

    for (int i = 0; i < N; i++) {
        int output, num_cows;
        fin >> num_cows >> output;
        outputs.insert(output);
        cows[output] = num_cows;
        M += num_cows;
    }

    auto it1 = outputs.begin();
    auto it2 = outputs.end();
    --it2;

    int max_time = 0;

    while (M > 0) {
        if (cows[*it1] < cows[*it2]) {
            M -= 2 * cows[*it1];
            cows[*it2] -= cows[*it1];
            cows[*it1] = 0;
            int time = *it1 + *it2;
            if (time > max_time) {
                max_time = time;
            }
            ++it1;
        } else if (cows[*it2] < cows[*it1]) {
            M -= 2 * cows[*it2];
            cows[*it1] -= cows[*it2];
            cows[*it2] = 0;
            int time = *it1 + *it2;
            if (time > max_time) {
                max_time = time;
            }
            --it2;
        } else {
            M -= 2 * cows[*it1];
            if (*it1 == *it2) {
                M += cows[*it1];
            }
            cows[*it1] = cows[*it2] = 0;
            int time = *it1 + *it2;
            if (time > max_time) {
                max_time = time;
            }
            ++it1;
            --it2;
        }
    }

    fout << max_time << "\n";
}