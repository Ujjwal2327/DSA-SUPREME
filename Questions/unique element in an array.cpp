#include<iostream>
#include<vector>
using namespace std;

int findUnique(vector<int>arr){
    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        // all duplicates will cancel each other
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }
    int ans = findUnique(arr);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
7
1 6 3 3 5 1 6
*/