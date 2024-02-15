#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    int N, B;

    fin >> N;
    fin >> B;

    vector<int> coordsX;
    vector<int> coordsY;
    int points[N][2];

    for (int i = 0; i < N; i++) {
        int a, b;
        fin >> a;
        fin >> b;
        coordsX.push_back(a);
        coordsY.push_back(b);
        points[i][0] = a;
        points[i][1] = b;
    }

    // sort(coordsX, coordsX + N);
    // sort(coordsY, coordsY + N);

    // int medA, medB;

    // if (N % 2 == 0) {
    //     medA = (coordsX[N/2] + coordsX[N/2 + 1])/2;
    //     medB = (coordsY[N/2] + coordsY[N/2 + 1])/2;
    // } else {
    //     medA = coordsX[N/2];
    //     medB = coordsY[N/2];
    // }

    vector<int> centersA;
    vector<int> centersB;

    set<int> coordsXSet(coordsX.begin(), coordsX.end());
    set<int> coordsYSet(coordsY.begin(), coordsY.end());

    vector<int> tempA(coordsXSet.begin(), coordsXSet.end());
    vector<int> tempB(coordsYSet.begin(), coordsYSet.end());

    if (tempA.size() == 1) {
        centersA.push_back(tempA[0] - 1);
    } else {
        for (int i = 0; i < tempA.size() - 1; i++) {
            centersA.push_back((tempA[i] + tempA[i + 1]) / 2);
        }
    }

    if (tempB.size() == 1) {
        centersB.push_back(tempB[0] - 1);
    } else {
        for (int i = 0; i < tempB.size() - 1; i++) {
            centersB.push_back((tempB[i] + tempB[i + 1]) / 2);
        }
    }

    // if (medA % 2 == 0) {
    //     centersA.push_back(medA - 2);
    //     centersA.push_back(medA);
    //     centersA.push_back(medA + 2);
    // } else {
    //     centersA.push_back(medA - 1);
    //     centersA.push_back(medA + 1);
    // }

    // if (medB % 2 == 0) {
    //     centersB.push_back(medB - 2);
    //     centersB.push_back(medB);
    //     centersB.push_back(medB + 2);
    // } else {
    //     centersB.push_back(medB - 1);
    //     centersB.push_back(medB + 1);
    // }

    int M = 2000000;

    for (int i = 0; i < centersA.size(); i++) {
        int a = centersA[i];
        for (int j = 0; j < centersB.size(); j++) {
            int b = centersB[j];
            int reg1 = 0, reg2 = 0, reg3 = 0, reg4 = 0;
            for (int k = 0; k < N; k++) {
                if (points[k][0] < a && points[k][1] < b) {
                    reg1++;
                } else if (points[k][0] < a && points[k][1] > b) {
                    reg2++;
                } else if (points[k][0] > a && points[k][1] < b) {
                    reg3++;
                } else {
                    reg4++;
                }
            }

            int m = max(max(reg1, reg2), max(reg3, reg4));
            if (m < M) {
                M = m;
            }
        }
    }

    fout << M << "\n";
}