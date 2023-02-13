#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void getMinMax(vector<vector<int>>arr){
    int rows = arr.size();
    int cols = arr[0].size();
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(arr[i][j] > maxi)
                maxi = arr[i][j];
            if(arr[i][j] < mini)
                mini = arr[i][j];
        }
    }
    cout<<mini<<' '<<maxi<<'\n';
}

int main(){

    int rows;
    int cols;
    cin>>rows>>cols;
    vector<vector<int>>arr(rows,vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }
    
    getMinMax(arr);

    return 0;
}

/*INPUTS
3 4
1 2 3 4
5 6 7 8
9 134 2523 12
*/