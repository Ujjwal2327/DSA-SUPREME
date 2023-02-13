// convert given digits to a number

#include<iostream>
using namespace std;

int digitsToNum(int n){
    int ans = 0;
    int digit;
    for(int i=0; i<n; i++){
        cin >> digit;
        ans = ans*10 + digit;
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    int ans = digitsToNum(n);
    cout << ans <<'\n';

    return 0;
}

/*INPUTS
5
1 2 3 4 5
*/