// https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int firstRepeatingElement(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j])
                return arr[i];
        }
    }
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = firstRepeatingElement(arr);
    cout << ans << '\n';

    return 0;
}