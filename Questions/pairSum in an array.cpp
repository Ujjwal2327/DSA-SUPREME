#include<bits/stdc++.h>
using namespace std;

void pairSum(vector<int>arr, int sum){
    int n = arr.size();

    for(int i=0; i<n; i++){
        int element1 = arr[i];

        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==sum)
                cout<<arr[i]<<' '<<arr[j]<<'\n';
        }
    }
    cout<<'\n';
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    pairSum(arr, sum);

    return 0;
}