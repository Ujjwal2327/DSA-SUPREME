// print all pairs of a vector

#include<bits/stdc++.h>
using namespace std;

void printAllPairs(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout << arr[i] << ' ' << arr[j] <<'\n';
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
    printAllPairs(arr);
    
    return 0;
}

/*INPUTS
4
10 20 30 40
*/