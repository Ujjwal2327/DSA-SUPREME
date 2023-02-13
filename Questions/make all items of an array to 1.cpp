#include<iostream>
using namespace std;

void inputArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void makeAllTo1(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i]=1;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

int main(){

    int arr[500];
    int n;
    cin>>n;
    inputArray(arr, n);
    makeAllTo1(arr, n);
    printArray(arr, n);

    return 0;
}

/*INPUTS
7
10 20 40 30 60 30 21
*/