// https://leetcode.com/problems/two-sum/

// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/

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

/*INPUTS
9
10 20 30 40 50 60 70 80 90
100
*/