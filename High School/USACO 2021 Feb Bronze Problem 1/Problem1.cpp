#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> translation;
    translation = {{"Ox", 0},
                   {"Tiger", 1},
                   {"Rabbit", 2},
                   {"Dragon", 3},
                   {"Snake", 4},
                   {"Horse", 5},
                   {"Goat", 6},
                   {"Monkey", 7},
                   {"Rooster", 8},
                   {"Dog", 9},
                   {"Pig", 10},
                   {"Rat", 11}};

    map<string, vector<string> > statements;
    map<string, int> births;
    vector<string> names;

    for (int i = 0; i < N; i++) {
        string name, temp, relative, year, other;
        cin >> name >> temp >> temp >> relative >> year >> temp >> temp >> other;

        statements[name] = {relative, year, other};
        births[name] = INT32_MAX;
        names.push_back(name);
    }

    births["Bessie"] = 0;
    bool allDone = false;

    while (!allDone) {
        allDone = true;

        for (int i = 0; i < names.size(); i++) {
            string name = names[i];
            if (births[name] == INT32_MAX) {
                allDone = false;
                string other = statements[name][2];
                if (births[other] != INT32_MAX) {
                    int year = translation[statements[name][1]];
                    string relative = statements[name][0];
                    int other_year;

                    if (other == "Bessie") {
                        other_year = 0;
                    }
                    else {
                        other_year = translation[statements[other][1]];
                    }

                    if (relative == "next") {
                        int delta = year - other_year;
                        if (delta <= 0) {
                            delta += 12;
                        }
                        births[name] = births[other] + delta;
                    } else {
                        int delta = other_year - year;
                        if (delta <= 0) {
                            delta += 12;
                        }
                        births[name] = births[other] - delta;
                    }
                }
            }
        }
    }

    cout << abs(births["Elsie"]) << "\n";
}