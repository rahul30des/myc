#include <iostream>
#include <vector>

using namespace std;

// Swap 2 numbers using XOR bit manipulation operation
void swap(int &num1, int &num2) {
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}

// Rotate the image 90 degrees to the right
void rotate(vector<vector<int>>& mat, int row, int col) {
    // First Pass
    for(int i = 0; i < row; i++) {
        for(int j = i + 1; j < col; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Second Pass
    for(int i = 0; i < row/2; i++) {
        for(int j = 0; j < col; j++) {
            swap(mat[i][j], mat[row - i - 1][j]);
        }
    }
}

// Display all elements of a row
void display(vector <vector<int>> mat, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout<<"\t"<<mat[i][j];
        }
        cout<<endl;
    }
}

// Main Function
int main() {
    vector <vector<int>> mat (2, vector<int> (5));
    mat = {{1, 0},
           {0, 1}};
    int row = mat.size();
    int col = mat[0].size();
    rotate(mat, row, col);
    display(mat, row, col);
    return 0;
}
