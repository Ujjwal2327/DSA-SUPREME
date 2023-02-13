#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(int arr[][500], int rows, int cols, int key){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(key==arr[i][j])
                return true;
        }
    }
    return false;
}

int main(){

    int rows = 3;
    int cols = 4;
    int arr[500][500];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;

    bool ans = linearSearch(arr, rows, cols, key);
    if(ans)
        cout << "present\n";
    else
        cout << "absent\n";

    return 0;
}
/*INPUTS
1 2 3 4
5 6 7 8
9 2 4 6

8
*/