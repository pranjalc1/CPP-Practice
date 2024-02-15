#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class matrix {
private:
    int N;
    vector<vector<int>> cow_matrix;

public:
    matrix(int N, vector<vector<int>> connections) {
        this->N = N;
        for (int i = 0; i < N; i++) {
            vector<int> row(N, 0);
            cow_matrix.push_back(row);
            cow_matrix[i][i] = 1;
        }
        
        for (vector<int> connection : connections) {
            cow_matrix[connection[0]][connection[1]] = 1;
        }
    }

    matrix(vector<vector<int>> cow_matrix) {
        this->cow_matrix = cow_matrix;
        this->N = cow_matrix.size();
    }

    matrix operator+(const matrix& other) {
        if (this->N != other.N) {
            throw "Matrix sizes are not equal!\n";
        }

        vector<vector<int>> new_matrix = cow_matrix;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                new_matrix[i][j] += other.cow_matrix[i][j];
                if (new_matrix[i][j] > 0) {
                    new_matrix[i][j] = 1;
                }
            }
        }

        return new_matrix;
    }

    matrix operator*(const matrix& other) {
        if (this->N != other.N) {
            throw "Matrix sizes are not equal!\n";
        }

        vector<vector<int>> new_matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    new_matrix[i][j] += cow_matrix[i][k] * other.cow_matrix[k][j];
                    if (new_matrix[i][j] > 0) {
                        new_matrix[i][j] = 1;
                    }
                }
            }
        }

        return new_matrix;
    }

    bool operator==(const matrix& other) {
        if (this->N != other.N) {
            return false;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (cow_matrix[i][j] != other.cow_matrix[i][j]) {return false;}
            }
        }

        return true;
    }

    vector<vector<int>> getMatrix() {
        return cow_matrix;
    }

    friend ostream& operator<<(ostream& os, const matrix& matr);
};

ostream& operator<<(ostream& os, const matrix& matr) {
    for (int i = 0; i < matr.N; i++) {
        for (int j = 0; j < matr.N; j++) {
            os << matr.cow_matrix[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

int main() {
    ifstream fin("factory.in");
    ofstream fout("factory.out");

    int N;
    fin >> N;
    vector<vector<int>> connections(N - 1, vector<int>(2));
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a >> b;
        connections[i][0] = a - 1; connections[i][1] = b - 1;
    }

    matrix cows(N, connections);

    while (true) {
        cout << cows << "\n";
        matrix temp = cows;
        temp = temp * temp + temp;
        if (temp == cows) {
            break;
        }
        cows = temp;
    }

    vector<vector<int>> cow_matrix = cows.getMatrix();

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (cow_matrix[i][j] == 0) {
                break;
            }
            if (i == N - 1) {
                fout << j + 1 << "\n";
                return 0;
            }
        }
    }

    fout << -1 << "\n";
    return 0;
}