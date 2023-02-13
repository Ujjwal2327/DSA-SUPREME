#include<iostream>
#include<vector>
using namespace std;

void printRowWiseSum(vector<vector<int>>arr){
    int rows = arr.size();
    int cols = arr[0].size();
    for(int i=0; i<rows; i++){
        int sum = 0;
        for(int j=0; j<cols; j++){
            sum += arr[i][j];
        }
        cout << sum << ' ';
    }
    cout << "\n\n";
}

void printColWiseSum(vector<vector<int>>arr){
    int rows = arr.size();
    int cols = arr[0].size();
    for(int j=0; j<cols; j++){
        int sum = 0;
        for(int i=0; i<rows; i++){
            sum += arr[i][j];
        }
        cout << sum << ' ';
    }
    cout << "\n\n";
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

    cout<<"row-wise sum-> ";
    printRowWiseSum(arr);

    cout<<"row-wise sum-> ";
    printColWiseSum(arr);

    return 0;
}

/*INPUTS
3 3
1 2 3
4 5 6
7 8 9
*/