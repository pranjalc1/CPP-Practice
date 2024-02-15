#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void swap(int &loc, int a, int b) {
    if (loc == a) {
        loc = b;
    } else if (loc == b) {
        loc = a;
    }
}

int maxim(int list[]) {
    if (list[0] >= list[1] && list[0] >= list[2]) {
        return list[0];
    } else if (list[1] >= list[0] && list[1] >= list[2]) {
        return list[1];
    } else {
        return list[2];
    }
}

int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int N;
    fin >> N;

    int swaps[N][2];
    int guess[N];

    for (int i = 0; i < N; i++) {
        fin >> swaps[i][0];
        fin >> swaps[i][1];
        fin >> guess[i];
    }

    int start[3] = {1, 2, 3};
    int correct[3] = {0, 0, 0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            swap(start[j], swaps[i][0], swaps[i][1]);
            if (guess[i] == start[j]) {
                correct[j]++;
            }
        }
    }

    fout << maxim(correct) << "\n";
}