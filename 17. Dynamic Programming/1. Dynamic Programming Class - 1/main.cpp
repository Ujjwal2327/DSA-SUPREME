#include<iostream>
#include<vector>
using namespace std;

// TC-O(2^n)    SC-O(n)
int recursiveSolve(int n) {
    if(n==0 || n==1)
        return n;

    return recursiveSolve(n-1) + recursiveSolve(n-2);
}

// TC-O(n)    SC-O(n+n)
int topDownSolve(int n, vector<int>& dp){
    if(n==0 || n==1)
        return n;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp);
}

// TC-O(n)    SC-O(n)
int bottomUpSolve(int n, vector<int>& dp){
    if(n==0)
        return 0;
        
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

// TC-O(1)    SC-O(n)
int spaceOptSolve(int n, int prev2=0, int prev1=1){
    if(n==0 || n==1)
        return n;

    prev2 = 0;
    prev1 = 1;
    int curr;

    for(int i=2; i<=n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main(){

    int n = 10;
    cout << recursiveSolve(n) << '\n';

    vector<int>dp(n+1,-1);
    cout << topDownSolve(n,dp) << '\n';

    vector<int>dp2(n+1,-1);
    cout << bottomUpSolve(n,dp2) << '\n';

    cout << spaceOptSolve(n) << '\n';



    return 0;
}