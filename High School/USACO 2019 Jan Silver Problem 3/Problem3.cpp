#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

struct mount {
    int left, right;

    mount(int x, int y) {
        left = x - y;
        right = x + y;
    }
};

bool operator<(const mount &one, const mount &other) {
    return one.left != other.left ? one.left < other.left : one.right > other.right;
}

int main() {
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");

    int N;
    fin >> N;

    set<mount> mountains;

    for (int i = 0; i < N; i++) {
        int x, y;
        fin >> x >> y;

        mount mountain(x, y);
        mountains.insert(mountain);
    }

    auto it = mountains.begin();
    int count = 1;

    int rightmost = (*it).right;
    ++it;
    for (; it != mountains.end(); ++it) {
        if (it->right > rightmost) {
            count++;
            rightmost = it->right;
        }
    }

    fout << count << "\n";
}