// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void findDuplicates(vector<int>arr){
    int n = arr.size();
    vector<int>cnts(n);

    for(int i=0; i<n; i++){
        int element = arr[i];
        cnts[element]++;
    }
    for(int i=0; i<n; i++){
        if(cnts[i]>1)
            cout << i << ' ';
    }
    cout << '\n';
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    findDuplicates(arr);

    return 0;
}