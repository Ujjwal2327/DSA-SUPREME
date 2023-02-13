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

    return 0;
}