#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Specify the number of rows and columns and the default value (e.g., 0)
    int rows = 3;
    int columns = 4;
    int default_value = 0;

    // Create a vector of vectors with the specified size and default value
    vector<vector<int>> matrix(rows, vector<int>(columns, default_value));

    // Access and print the elements
    for (auto& row: matrix)
    {
        row.assign(row.size(), -1);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
