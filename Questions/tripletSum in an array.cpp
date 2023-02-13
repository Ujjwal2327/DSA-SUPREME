// find set of 3 numbers whose sum is equal to the given sum

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

/*INPUTS
10
10 20 30 40 50 60 70 80 90 100
100
*/