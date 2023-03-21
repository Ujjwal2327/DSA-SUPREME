#include<iostream>
#include<vector>
using namespace std;

void printVector(int arr[], int n, int i, int j){
    
    for(int k=i; k<=j; k++)
        cout << arr[k] << ' ';
    cout << '\n';
}

void printSubarrays(int arr[], int &n, int i){
    if(i>=n){
        return;
    }

    for(int j=i ; j<n; j++){
        printVector(arr, n, i, j);
    }
    
    printSubarrays(arr, n, i+1);
}

int main(){

    int arr[] = {1,2,3};
    int n = sizeof(arr) / sizeof(int);
    int i = 0;

    printSubarrays(arr, n, i);

    return 0;
}