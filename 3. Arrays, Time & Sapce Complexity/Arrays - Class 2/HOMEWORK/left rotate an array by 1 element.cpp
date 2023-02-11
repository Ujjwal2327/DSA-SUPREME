#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void leftRotateBy1(vector<int>arr){
    int n = arr.size();
    int startElement = arr[0];
    for(int i=0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = startElement;

    printArray(arr);
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    leftRotateBy1(arr);

    return 0;
}