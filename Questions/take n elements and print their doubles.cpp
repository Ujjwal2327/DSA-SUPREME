#include<iostream>
using namespace std;

void printDoubles(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<2*arr[i]<<' ';
    }
    cout<<'\n';
}

int main(){

    int arr[500];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    printDoubles(arr, n);

    return 0;
}