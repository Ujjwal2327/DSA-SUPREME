// https://leetcode.com/problems/find-the-duplicate-number/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int findDuplicate(vector<int>arr){
    int n = arr.size();
    vector<int>cnts(n);

    for(int i=0; i<n; i++){
        int element = arr[i];
        cnts[element]++;
        if(cnts[element]>1)
            return element;
    }
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = findDuplicate(arr);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
5
1 3 4 2 2
*/