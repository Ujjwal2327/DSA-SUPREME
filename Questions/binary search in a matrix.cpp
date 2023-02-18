#include<iostream>
#include<vector>
using namespace std;

bool binarySearchInMatrix(vector<vector<int>>arr, int target){
    int rows = arr.size();
    int cols = arr[0].size();
    int total = rows*cols;
    int s = 0;
    int e = total-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        int i = mid / cols;
        int j = mid % cols;
        if(target == arr[i][j]){
            cout << "found at " << i << " row and " << j << " col\n";
            return true;
        }
        else if(target < arr[i][j])
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    
    cout << "not found\n";
    return false;
}

int main(){

    int rows;
    int cols;
    cin>>rows>>cols;
    vector<vector<int>>arr(rows, vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;

    int ans = binarySearchInMatrix(arr, target);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
3 4
1 2 3 4
5 6 7 8
9 10 11 12
7
*/