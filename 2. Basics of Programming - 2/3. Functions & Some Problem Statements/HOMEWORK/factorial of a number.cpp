// find factorial of a number

// https://www.geeksforgeeks.org/factorial-large-number/

#include<iostream>
using namespace std;

#define ull unsigned long long

ull fact(int n){
    ull ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * i;
    }
    return ans;
}

int main(){
    
    int n;
    cin>>n;
    ull ans = fact(n);
    cout << ans << '\n';


    return 0;
}