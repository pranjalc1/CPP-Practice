#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

set<int> friday(int barn1, vector<int> buckets1, vector<int> buckets2) {
    set<int> all_possible;
    for (int i = 0; i < buckets2.size(); i++) {
        vector<int> newBuckets1 = buckets1;
        vector<int> newBuckets2 = buckets2;

        int barn1Copy = barn1 + newBuckets2[i];

        all_possible.insert(barn1Copy);
    }

    return all_possible;
}

set<int> thursday(int barn1, vector<int> buckets1, vector<int> buckets2) {
    set<int> all_possible;
    for (int i = 0; i < buckets1.size(); i++) {
        vector<int> newBuckets1 = buckets1;
        vector<int> newBuckets2 = buckets2;

        int barn1Copy = barn1 - newBuckets1[i];
        newBuckets2.push_back(newBuckets1[i]);
        if (i == 0) {newBuckets1.erase(newBuckets1.begin());}
        else {newBuckets1.erase(next(newBuckets1.begin(), i));}

        set<int> new_possible = friday(barn1Copy, newBuckets1, newBuckets2);
        for (set<int>::iterator it = new_possible.begin(); it != new_possible.end(); it++) {
            all_possible.insert(*it);
        }
    }

    return all_possible;
}

set<int> wednesday(int barn1, vector<int> buckets1, vector<int> buckets2) {
    set<int> all_possible;
    for (int i = 0; i < buckets2.size(); i++) {
        vector<int> newBuckets1 = buckets1;
        vector<int> newBuckets2 = buckets2;

        int barn1Copy = barn1 + newBuckets2[i];
        newBuckets1.push_back(newBuckets2[i]);
        if (i == 0) {newBuckets2.erase(newBuckets2.begin());}
        else {newBuckets2.erase(next(newBuckets2.begin(), i));}

        set<int> new_possible = thursday(barn1Copy, newBuckets1, newBuckets2);
        for (set<int>::iterator it = new_possible.begin(); it != new_possible.end(); it++) {
            all_possible.insert(*it);
        }
    }

    return all_possible;
}

set<int> tuesday(int barn1, vector<int> buckets1, vector<int> buckets2) {
    set<int> all_possible;
    for (int i = 0; i < buckets1.size(); i++) {
        vector<int> newBuckets1 = buckets1;
        vector<int> newBuckets2 = buckets2;

        int barn1Copy = barn1 - newBuckets1[i];
        newBuckets2.push_back(newBuckets1[i]);
        if (i == 0) {newBuckets1.erase(newBuckets1.begin());}
        else {newBuckets1.erase(next(newBuckets1.begin(), i));}

        set<int> new_possible = wednesday(barn1Copy, newBuckets1, newBuckets2);
        for (set<int>::iterator it = new_possible.begin(); it != new_possible.end(); it++) {
            all_possible.insert(*it);
        }
    }

    return all_possible;
}

int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");

    vector<int> buckets1, buckets2;

    for (int i = 0; i < 10; i++) {
        int a;
        fin >> a;
        buckets1.push_back(a);
    }

    for (int i = 0; i < 10; i++) {
        int a;
        fin >> a;
        buckets2.push_back(a);
    }

    for (int i : tuesday(1000, buckets1, buckets2)) {
        cout << i << "\n";
    }

    fout << tuesday(1000, buckets1, buckets2).size() << "\n";
}