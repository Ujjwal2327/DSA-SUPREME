#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>arr, int rows, int cols, vector<vector<bool>>visited){
    if( (x>=0 && x<rows) && (y>=0&&y<cols) && visited[x][y]==true )
        return true;
    else
        return false;
}

// TC-O(4^(rows+cols))
void ratInMaze(vector<vector<int>>&arr, int &rows, int &cols, vector<vector<bool>>&visited, int i, int j, vector<string>&path, string output){

    if(i==rows-1 && j==cols-1){
        path.push_back(output);
    }

    // go down
    if(isSafe(i+1, j, arr, rows, cols, visited)){
        visited[i+1][j] = true;
        ratInMaze(arr, rows, cols, visited, i+1, j, path, output+'D');
        visited[i+1][j] = true;
    }

    // go left
    if(isSafe(i, j-1, arr, rows, cols, visited)){
        visited[i][j-1] = true;
        ratInMaze(arr, rows, cols, visited, i, j-1, path, output+'L');
        visited[i][j-1] = true;
    }

    // go right
    if(isSafe(i, j+1, arr, rows, cols, visited)){
        visited[i][j+1] = true;
        ratInMaze(arr, rows, cols, visited, i, j+1, path, output+'R');
        visited[i][j+1] = true;
    }

    // go up
    if(isSafe(i-1, j, arr, rows, cols, visited)){
        visited[i-1][j] = true;
        ratInMaze(arr, rows, cols, visited, i-1, j, path, output+'U');
        visited[i-1][j] = true;
    }

}

int main(){

    /*
    */
    // rat in a maze




    return 0;
}