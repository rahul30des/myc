#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void rotate(vector<vector<int>>& matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for(int j = i + 1; j < col; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < (row/2); i++) {
        for(int j = 0; j < col; j++) {
            swap(matrix[i][j], matrix[row - i - 1][j]);
        }
    }    
}


void display(vector<vector<int>> matrix, int row, int col) {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout<<"\t"<<matrix[i][j];
        }
        cout<<endl;
    }

}

// Main Function
int main() {
    vector <vector<int>> matrix = {{1,0},
                                   {0, 1}};
    int row = matrix.size();
    int col = matrix[0].size();
    rotate(matrix, row, col);
    display(matrix, row, col);
    return 0;
}
