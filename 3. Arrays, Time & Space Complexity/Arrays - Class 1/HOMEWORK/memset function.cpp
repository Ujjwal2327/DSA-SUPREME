#include<bits/stdc++.h>
using namespace std;

int main(){

    // memset function to initialize an array with 0 or -1 (not work on other value)s
        int arr[10];
        memset(arr, -1, sizeof(arr));
        for(int i=0; i<10; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';

    return 0;
}