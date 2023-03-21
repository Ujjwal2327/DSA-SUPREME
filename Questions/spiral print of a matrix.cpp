// https://leetcode.com/problems/spiral-matrix/

// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    int n = arr.size();

    for(int i:arr)
        cout << i << ' ';
    cout << '\n';
}

void spiralPrint(vector<vector<int>>arr){
    int rows = arr.size();
    int cols = arr[0].size();
    int rowStart = 0;
    int rowEnd = rows-1;
    int colStart = 0;
    int colEnd = cols-1;
    vector<int>ans;

    int cnt = 1;
    int total = rows*cols;
    while(cnt<=total){
        // upper row
        for(int j=colStart; cnt<=total && j<=colEnd; j++){
            ans.push_back(arr[rowStart][j]);
            cnt++;
        }
        rowStart++;

        // right col
        for(int i=rowStart; cnt<=total && i<=rowEnd; i++){
            ans.push_back(arr[i][colEnd]);
            cnt++;
        }
        colEnd--;

        // bottom row
        for(int j=colEnd; cnt<=total && j>=colStart; j--){
            ans.push_back(arr[rowEnd][j]);
            cnt++;
        }
        rowEnd--;

        // left col
        for(int i=rowEnd; cnt<=total && i>=rowStart; i--){
            ans.push_back(arr[i][colStart]);
            cnt++;
        }
        colStart++;
    }

    printVector(ans);
}

int main(){
    
    int rows;
    int cols;
    cin >> rows >> cols;
    vector<vector<int>>arr(rows,vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }
    cout<<'\n';
    
    spiralPrint(arr);

    return 0;
}

/*INPUTS
4 5
1 5 10 14 18
2 6 11 15 19
3 7 12 16 20
4 8 13 17 21
*/