// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/896257751/

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>arr){
    int n = arr.size();
    int ans = 0;
    // find all pairs and find maximum difference (later-earlier)
    for(int i=n-1; i>0; i--){
        for(int j=i-1; j>=0; j--){
            int diff = arr[i] - arr[j];
            ans = max(ans, diff);
        }
    }
    return ans;
}

int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    // maxi is maximum element
    int maxi = prices[n-1];
    // ans is maximum profit
    int ans = 0;
    for(int i=n-1; i>=0; i--){
        if(prices[i]>=maxi)
            maxi = prices[i];
        else
            ans = max(ans, maxi-prices[i]);
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = maxProfit(arr);
    cout<<ans<<'\n';

    int ans2 = maxProfit2(arr);
    cout<<ans2<<'\n';

    return 0;
}