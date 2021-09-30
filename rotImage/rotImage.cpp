#include <iostream>
#include <vector>

using namespace std;

// Swap 2 numbers using XOR bit manipulation operation
void swap(int &num1, int &num2) {
    if(num1 != num2) {
        num1 = num1 ^ num2;
        num2 = num1 ^ num2;
        num1 = num1 ^ num2;
    }
}

// Rotate the image 90 degrees to the right
void rotate(vector<vector<int>>& mat, int row, int col) {
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(visited[i][j] == 0) {
                swap(mat[i][j], mat[j][row-i-1]);
                visited[i][j] = 1;
                visited[j][row-i-1] = 1;
            }
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
    vector <vector<int>> mat (3, vector<int> (3));
    mat = {{1,2,3},
           {4,5,6},
           {7,8,9}};
    int row = mat.size();
    int col = mat[0].size();
    rotate(mat, row, col);
    display(mat, row, col);
    return 0;
}
