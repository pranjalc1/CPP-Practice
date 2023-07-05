#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    int N;
    fin >> N;

    vector<vector<int>> cows(N);

    for (int i = 0; i < N * N; i++) {
        char readChar;
        fin >> readChar;
        int cow = (int) (readChar - 48);

        cows[i / N].push_back(cow);
    }

    int num_flips = 0;
    while (true) {
        int bottomRow = -1, rightCol = -1, bottomCol, rightRow;

        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (bottomRow != -1 && rightCol != -1) {
                    break;
                }

                if (bottomRow == -1 && cows[i][j] == 1) {
                    bottomRow = i;
                    bottomCol = j;
                }

                if (rightCol == -1 && cows[j][i] == 1) {
                    rightCol = i;
                    rightRow = j;
                }
            }
        }

        if (bottomRow == -1 && rightCol == -1) {
            break;
        }
        
        if (bottomCol == rightCol && bottomRow == rightRow) {
            for (int i = 0; i < bottomRow + 1; i++) {
                for (int j = 0; j < rightCol + 1; j++) {
                    cows[i][j] = 1 - cows[i][j];
                }
            }

            num_flips++;
        } else {
            for (int i = 0; i < bottomRow + 1; i++) {
                for (int j = 0; j < bottomCol + 1; j++) {
                    cows[i][j] = 1 - cows[i][j];
                }
            }

            for (int i = 0; i < rightRow + 1; i++) {
                for (int j = 0; j < rightCol + 1; j++) {
                    cows[i][j] = 1 - cows[i][j];
                }
            }

            num_flips += 2;
        }
    }

    fout << num_flips << "\n";
}