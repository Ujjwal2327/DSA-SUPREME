// https://www.geeksforgeeks.org/print-matrix-in-wave-form/

#include<iostream>
#include<vector>
using namespace std;

void wavePrint(vector<vector<int>>arr){
    int rows = arr.size();
    int cols = arr[0].size();

    // traverse colwise (as for one wave top to bottom and bottom to top)
    for(int j=0; j<cols; j++){
        if((j&1)==0){     // 0,2,4,6...col index
            // top to bottom
            for(int i=0; i<rows; i++){
                cout << arr[i][j] << ' ';
            }
        }
        else{       // 1,3,5,7...col index
            // bottom to top
            for(int i=rows-1; i>=0; i--){
                cout << arr[i][j] << ' ';
            }
        }
    }
    cout << '\n';
}

void rowWiseWavePrint(vector<vector<int>>arr){
    int rows = arr.size();
    int cols = arr[0].size();

    for(int i=0; i<rows; i++){
        if((i&1)==0){     // for i=0,2,4  go left to right
            for(int j=0; j<cols; j++)
                cout << arr[i][j] << ' ';
        }
        else{       // for i=1,3,5  go right to left
            for(int j=cols-1; j>=0; j--)
                cout << arr[i][j] << ' ';
        }
    }
    cout << '\n';
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
    
    wavePrint(arr);
    rowWiseWavePrint(arr);

    return 0;
}

/*INPUTS
3 3
1 2 3
4 5 6
7 8 9
*/