#include<bits/stdc++.h>
using namespace std;

void tripletSum(vector<int>arr, int sum){
    int n = arr.size();

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            for(int k=j+1; k<n; k++){

                if(arr[i] + arr[j] + arr[k] == sum)
                    cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] <<'\n';
            }
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
    tripletSum(arr, sum);

    return 0;
}