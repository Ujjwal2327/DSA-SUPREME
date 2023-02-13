#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>>arr){
    int rows = arr.size();
    int cols = arr[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

// transpose of any rectangular matrix
// extra space
void transpose(vector<vector<int>>arr, vector<vector<int>>ans){
    int rows = arr.size();
    int cols = arr[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            ans[j][i] = arr[i][j];
        }
    }
    cout << '\n';
    printMatrix(ans);
}

// transpose of a square matrix
// inplace
void transpose2(vector<vector<int>>arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    cout<<'\n';
    printMatrix(arr);
}

int main(){

    /*// transpose of any rectangular matrix
        int rows;
        int cols;
        cin>>rows>>cols;
        vector<vector<int>>arr(rows,vector<int>(cols));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cin>>arr[i][j];
            }
        }
        vector<vector<int>>ans(cols,vector<int>(rows));
        transpose(arr, ans);
    */

    /*// transpose of a square matrix
        int n;
        cin>>n;
        vector<vector<int>>arr(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        transpose2(arr);
    */

    return 0;
}

/*INPUTS
// for transpose
3 4
1 2 3 4
5 6 7 8
9 10 11 12
// for transpose2
3 
1 2 3
4 5 6
7 8 9
*/