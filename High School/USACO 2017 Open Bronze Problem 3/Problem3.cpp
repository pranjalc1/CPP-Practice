#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool overlap(int i, int j, int num, vector<vector<int>> canvas, \
            map<int, int> leftCoords, map<int, int> rightCoords, \
            map<int, int> topCoords, map<int, int> bottomCoords) {
    if (canvas[i][j] == num || canvas[i][j] == 0) {
        return false;
    }

    if (i >= topCoords[num] && i <= bottomCoords[num] && j >= leftCoords[num] && j <= rightCoords[num]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ifstream fin("art.in");
    ofstream fout("art.out");

    int N;
    fin >> N;

    set<int> nums;
    vector<vector<int>> canvas;

    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < N; j++) {
            char newChar;
            fin >> newChar;

            int newNum = int(newChar) - 48;
            if (newNum != 0) {
                nums.insert(newNum);
            }
            row.push_back(newNum);
        }
        canvas.push_back(row);
    }

    map<int, int> leftCoords, rightCoords, topCoords, bottomCoords;

    for (int num : nums) {
        bool leftDone = false, rightDone = false, topDone = false, bottomDone = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!leftDone && canvas[j][i] == num) {
                    leftCoords[num] = i;
                    leftDone = true;
                }
                if (!rightDone && canvas[j][N-1-i] == num) {
                    rightCoords[num] = N-1-i;
                    rightDone = true;
                }
                if (!topDone && canvas[i][j] == num) {
                    topCoords[num] = i;
                    topDone = true;
                }
                if (!bottomDone && canvas[N-1-i][j] == num) {
                    bottomCoords[num] = N-1-i;
                    bottomDone = true;
                }
            }
        }
    }

    set<int> marked;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int num : nums) {
                if (overlap(i, j, num, canvas, leftCoords, rightCoords, topCoords, bottomCoords)) {
                    marked.insert(canvas[i][j]);
                }
            }
        }
    }

    fout << nums.size() - marked.size() << "\n";
}