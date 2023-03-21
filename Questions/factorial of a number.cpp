// find factorial of a number

// https://www.geeksforgeeks.org/factorial-large-number/

#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull fact(int n){
    ull ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * i;
    }
    return ans;
}

void printReverse(vector<int>arr){
    for(int i=arr.size()-1; i>=0; i--){
        cout << arr[i];
    }
    cout<<'\n';
}

// factorial of a large number
void largeFact(int n){
    vector<int>ans(1,1);
    // ans will contain the ans in reverse order
    for(int i=2; i<=n; i++){
        // multiplication of i to ans(fact(i-1)) to get fact(i)
        int carry = 0;
        for(int ind =0; ind<ans.size(); ind++){
            int val = ans[ind]*i + carry;
            ans[ind] = val % 10;
            carry = val / 10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry = carry/10;
        }
    }
    // as the ans stored in ans is in reverse order, reverse the number
    printReverse(ans);
}

int main(){
    
    int n;
    cin>>n;
    ull ans = fact(n);
    cout << ans << '\n';

    cin>>n;
    largeFact(n);

    return 0;
}

/*INPUTS
20
30
*/