// print extreme elements of an array and come towards center

#include<iostream>
using namespace std;

void printExtremes(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(s==e)
            cout<<arr[s];
        else
            cout<<arr[s]<<' '<<arr[e]<<' ';
        s++;
        e--;
    }
}

int main(){

    int arr[] = {10,20,30,40,50,60,70};
    int n = 7;
    printExtremes(arr, n);

    return 0;
}