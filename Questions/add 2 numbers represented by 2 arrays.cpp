#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string addArrays(vector<int>arr1, vector<int>arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    string ans;

    int i=n1-1, j=n2-1;
    int carry = 0;
    while(i>=0 && j>=0){
        int sum = arr1[i--] + arr2[j--] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        // cout << digit << ' ';
        ans.push_back(digit + '0');
    }

    while(i>=0){
        int sum = arr1[i--] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        // cout << digit << ' ';
        ans.push_back(digit + '0');
    }
  
    while(j>=0){
        int sum = arr2[j--] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        // cout << digit << ' ';
        ans.push_back(digit + '0');
    }
    
  
    while(carry){
        int digit = carry % 10;
        // cout << digit << ' ';
        ans.push_back(digit + '0');
        carry = carry / 10;
    }

    reverse(ans.begin(), ans.end());
    // ans.push_back('\0');

    cout << ans << '\n';
    return ans;
}

int main(){

    int n1;
    cin>>n1;
    vector<int>arr1(n1);
    for(int i=0; i<n1; i++)
        cin>>arr1[i];
  
    int n2;
    cin>>n2;
    vector<int>arr2(n2);
    for(int i=0; i<n2; i++)
        cin>>arr2[i];

    string ans = addArrays(arr1, arr2);
    ans.push_back(n1);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
4
1 2 3 4
5
9 9 9 9 9
*/