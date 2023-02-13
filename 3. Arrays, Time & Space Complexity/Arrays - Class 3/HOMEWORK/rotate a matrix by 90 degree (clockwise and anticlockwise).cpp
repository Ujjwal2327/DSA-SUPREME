// https://leetcode.com/problems/rotate-image/

// https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/

#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>>arr){
    int n=arr.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void rotateClockwise(vector<vector<int>>arr){
    int n = arr.size();
    // transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    // reverse all rows
    for(int i=0; i<n; i++){
        // reverse each row
        int s=0, e=n-1;
        while(s<e){
            swap(arr[i][s++], arr[i][e--]);
        }
    }
    printMatrix(arr);
}

void rotateAntiClockwise(vector<vector<int>>arr){
    int n = arr.size();
    // transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    // reverse all cols
    for(int j=0; j<n; j++){
        // reverse each row
        int s=0, e=n-1;
        while(s<e){
            swap(arr[s++][j], arr[e--][j]);
        }
    }
    printMatrix(arr);
}

int main(){
    
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<'\n';
    
    rotateClockwise(arr);
    rotateAntiClockwise(arr);

    return 0;
}