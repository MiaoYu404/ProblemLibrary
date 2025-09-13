#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> construct_latin_square(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = (i + j) % n + 1;
        }
    }
    return matrix;
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) cout << " ";
            cout << row[i];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
    } else {
        int m = 0; // The minimum possible disorder value for n >= 3 (odd) is 0
        cout << m << endl;
        vector<vector<int>> matrix = construct_latin_square(n);
        print_matrix(matrix);
    }
    
    return 0;
}
