// find minimum and maximum n=element in an array

#include<iostream>
#include<limits.h>
using namespace std;

void inputArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

pair<int,int> getMinMax(int arr[], int n){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;  i<n; i++){
        if(arr[i]>maxi)
            maxi = arr[i];
        if(arr[i]<mini)
            mini = arr[i];
    }
    return {mini, maxi};
}

int main(){

    int n;
    cin>>n;
    int arr[500];
    inputArray(arr, n);
    pair<int,int>ans = getMinMax(arr, n);
    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

/*INPUTS
11
2 4 6 1 3 7 9 12 56 43 21
*/