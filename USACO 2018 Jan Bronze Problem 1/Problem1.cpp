#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    int coords[2][4];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            fin >> coords[i][j];
        }
    }

    // No covering
    if (coords[0][0] >= coords[1][2] || coords[0][1] >= coords[1][3] || coords[0][2] <= coords[1][0] || coords[0][3] <= coords[1][1]) {
        fout << (coords[0][3] - coords[0][1])*(coords[0][2] - coords[0][0]) << "\n";
        return 0;
    }

    // Completely covered
    if (coords[0][0] >= coords[1][0] && coords[0][1] >= coords[1][1]  && coords[0][2] <= coords[1][2] && coords[0][3] <= coords[1][3]) {
        fout << 0 << "\n";
        return 0;
    }

    // Side is covered
    // Left
    if (coords[0][0] >= coords[1][0] && coords[0][0] <= coords[1][2] && coords[0][1] >= coords[1][1] && coords[0][3] <= coords[1][3] && coords[0][2] >= coords[1][2]) {
        fout << (coords[0][3] - coords[0][1])*(coords[0][2] - coords[1][2]) << "\n";
        return 0;
    }

    // Bottom
    if (coords[0][1] >= coords[1][1] && coords[0][1] <= coords[1][3] && coords[0][0] >= coords[1][0] && coords[0][2] <= coords[1][2] && coords[0][3] >= coords[1][3]) {
        fout << (coords[0][3] - coords[1][3])*(coords[0][2] - coords[0][0]) << "\n";
        return 0;
    }

    // Right
    if (coords[0][2] >= coords[1][0] && coords[0][2] <= coords[1][2] && coords[0][1] >= coords[1][1] && coords[0][3] <= coords[1][3] && coords[0][0] <= coords[1][0]) {
        fout << (coords[0][3] - coords[0][1])*(coords[1][0] - coords[0][0]) << "\n";
        return 0;
    }

    // Top
    if (coords[0][3] >= coords[1][1] && coords[0][3] <= coords[1][3] && coords[0][0] >= coords[1][0] && coords[0][2] <= coords[1][2] && coords[0][1] <= coords[1][1]) {
        fout << (coords[1][1] - coords[0][1])*(coords[0][2] - coords[0][0]) << "\n";
        return 0;
    }

    // Everything else
    fout << (coords[0][3] - coords[0][1])*(coords[0][2] - coords[0][0]) << "\n";
    return 0;
}