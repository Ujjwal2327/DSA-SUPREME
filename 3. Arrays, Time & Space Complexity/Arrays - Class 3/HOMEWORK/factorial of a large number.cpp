// https://www.geeksforgeeks.org/factorial-large-number/

#include<iostream>
#include<vector>
using namespace std;

void printReverse(vector<int>arr){
    for(int i=arr.size()-1; i>=0; i--){
        cout << arr[i];
    }
    cout<<'\n';
}

void fact2(int n){
    vector<int>arr(1,1);
    // arr will contain the ans in reverse order
    for(int i=2; i<=n; i++){
        // multiplication of i to arr(fact(i-1)) to get fact(i)
        int carry = 0;
        for(int ind =0; ind<arr.size(); ind++){
            int val = arr[ind]*i + carry;
            arr[ind] = val % 10;
            carry = val / 10;
        }
        while(carry){
            arr.push_back(carry%10);
            carry = carry/10;
        }
    }
    // as the ans stored in arr is in reverse order, reverse the number
    printReverse(arr);
}

int main(){
    
    int n;
    cin>>n;
    fact2(n);

    return 0;
}