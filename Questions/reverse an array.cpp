// reverse an array

#include<iostream>
using namespace std;

void reverseArray(int arr[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(arr[s++], arr[e--]);
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

int main(){

    int arr[] = {10,20,30,40,50,60,70};
    int n = 7;
    reverseArray(arr, n);
    printArray(arr, n);

    return 0;
}