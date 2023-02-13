#include<bits/stdc++.h>
using namespace std;

int getLength(int n){
    return log10(n)+1;
}

int getLength2(int n){
    int ans = 0;
    while(n){
        ans++;
        n = n / 10;
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    int ans = getLength(n);
    cout << ans << '\n';

    int ans2 = getLength2(n);
    cout << ans2 << '\n';

    return 0;
}

/*INPUTS
123456789
*/