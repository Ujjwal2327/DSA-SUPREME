// count number of 0s and 1s present in an array

#include<iostream>
using namespace std;

void cnt0sAnd1s(int arr[], int n){
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            cnt0++;
        else if(arr[i]==1)
            cnt1++;
    }
    cout << "number of zeroes-> " << cnt0 <<'\n';
    cout << "number of ones-> " << cnt1 <<'\n';
}

int main(){

    int arr[] = {0,1,1,1,0,0,0,0,1,0,1,0,1,0,1,2,4,5,7};
    int n = 19;
    cnt0sAnd1s(arr, n);

    return 0;
}