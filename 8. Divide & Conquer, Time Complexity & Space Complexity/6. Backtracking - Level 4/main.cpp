#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int value){
    for(int i=0; i<9; i++){
        // row check
        if(board[row][i]==value){
            return false;
        }
    
        // col check
        if(board[i][col]==value){
            return false;
        }

        // 3X3 box check
        if( board[3*(row/3) + i/3] [ 3*(col/3) + i%3 ] == value )
            return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]=='.'){
                for(int val='1'; val<='9'; val++){
                    if(isSafe(board, i, j, val)){
                        board[i][j] = val;
                        bool remainAns = solve(board);
                        if(remainAns)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;   // hona hoga true to val=1 to 9 me hi ho jayega
            }
        }
    }

    return true;    // if sb phle se hi placed hain
}

int main(){

    // sudoku solver
    vector<vector<char>>board { {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'} };

    solve(board);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}