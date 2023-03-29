#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void printBoard(vector<vector<int>>arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] <<' ';
        }
        cout << '\n';
    }
    cout << "\n";
}

// by thinking that which cells can harm current
// TC-O{n^2}
bool isSafe(vector<vector<int>>&board, int n, int row, int col){
    for(int j=0; j<col; j++){
        for(int i=0; i<n; i++){
            if(board[i][j]==1){
                if(i==row || j==col || i-j==row-col || i+j==row+col)
                    return false;
            }
        }
    }
    return true;
}

// by thinking that which cells current can harm
// TC-O{n}
bool isSafe2(vector<vector<int>>&board, int n, int row, int col){
    // check row
    for(int j=col-1; j>=0; j--){
        if(board[row][j]==1)
            return false;
    }

    // check top left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1)
            return false;
    }

    // check for bottom left diagonal
    for(int i=row+1, j=col-1; i<n && j>=0; i++, j--){
        if(board[i][j]==1)
            return false;
    }

    return true;
}

void solveNQueens(vector<vector<int>>&board, int n, int col) {
    if(col>=n){
        printBoard(board);
        return;
    }

    for(int i=0; i<n; i++){
        if(isSafe2(board, n, i, col)){
            board[i][col] = 1;
            solveNQueens(board, n, col+1);
            board[i][col] = 0;
        }
    }

}

unordered_map<int, bool>rowMap;
unordered_map<int, bool>upperLeftDiagonalMap;
unordered_map<int, bool>lowerLeftDiagonalMap;

// TC-O{1}
bool isSafe3(vector<vector<int>>&board, int n, int row, int col){
    if(rowMap[row] || upperLeftDiagonalMap[row-col] || lowerLeftDiagonalMap[row+col])
        return false;
    else
        return true;
}

void solveNQueens2(vector<vector<int>>&board, int n, int col ) {
    if(col>=n){
        printBoard(board);
        return;
    }

    for(int i=0; i<n; i++){
        if(isSafe3(board, n, i, col)){
            board[i][col] = 1;
            rowMap[i] = upperLeftDiagonalMap[i-col] = lowerLeftDiagonalMap[i+col] = true;
            solveNQueens2(board, n, col+1);
            rowMap[i] = upperLeftDiagonalMap[i-col] = lowerLeftDiagonalMap[i+col] = false;
            board[i][col] = 0;
        }
    }

}

int main(){

    // pace n queens in a board such that no queen can attack each other

    int n = 4;
    vector<vector<int>>board( n, vector<int>(n) );
    int col = 0;
    solveNQueens(board, n, col);
    cout << '\n';

    solveNQueens2(board, n, col);


    return 0;
}