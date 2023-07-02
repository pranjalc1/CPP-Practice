#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int N;
    fin >> N;

    int bales[N];

    for (int i = 0; i < N; i++) {
        fin >> bales[i];
    }

    sort(bales, bales+N);

    int maxExploded = 0;

    for (int i = 0; i < N; i++) {
        int firstPos = bales[i];

        int delta = 1;
        int left = firstPos - delta, right = firstPos + delta;
        bool doneLeft = false, doneRight = false;

        while (true) {
            bool leftSet = false;
            int newLeft = bales[0], newRight = bales[N-1];

            if (!doneLeft) {
                for (int i = 0; i < N; i++) {
                    if (bales[i] >= left && !leftSet) {
                        newLeft = bales[i];
                        leftSet = true;
                        if (newLeft >= left + delta) {
                            doneLeft = true;
                        }
                    }
                }
            }

            if (!doneRight) {
                for (int i = 0; i < N; i++) {
                    if (bales[i] >= left && !leftSet) {
                        newLeft = bales[i];
                        leftSet = true;
                        if (newLeft >= left + delta) {
                            doneLeft = true;
                        }
                    }
                    if (bales[i] <= right) {
                        newRight = bales[i];
                        if (newRight <= right - delta) {
                            doneRight = true;
                        } else {
                            doneRight = false;
                        }
                    }
                }
            }

            if (doneLeft && doneRight) {
                break;
            }

            delta++;
            if (!doneLeft) {
                left = newLeft - delta;
            }
            if (!doneRight) {
                right = newRight + delta;
            }
        }

        int exploded = 0;
        for (int i = 0; i < N; i++) {
            if (bales[i] >= left && bales[i] <= right) {
                exploded++;
            }
        }

        if (exploded > maxExploded) {
            maxExploded = exploded;
        }
    }

    fout << maxExploded << "\n";
}