#include<iostream>
using namespace std;

void printDigits(int n){
    while(n){
        int rem = n % 10;
        n = n/10;
        cout << rem << ' ';
    }
    cout<<'\n';
}

void printDigits2(int n){
    for( ; n>0; n=n/10){
        int rem = n % 10;
        cout << rem <<' ';
    }
    cout<<'\n';
}

int printNum(int n){
    int ans = 0;
    int digit;
    for(int i=0; i<n; i++){
        cin >> digit;
        ans = ans*10 + digit;
    }
    return ans;
}

int countSetBit(int n){
    int ans = 0;
    while(n){
        if(n&1){
            ans++;
            cout<<ans<<' ';
        }
        n = n>>1;
    }
    cout<<'\n';
    return ans;
}

float getMiles(int n){
    float ans = n/1.609;
    return ans;
}

int main(){

    // ternary / conditional operator
        /*
        int age = 15;
        (age>=18) ? cout<<"Can Votes", cout<<'\n' : cout<<"Cannot Vote", cout<<'\n';

        int num = 5;
        (num%2) ? cout<<"Odd"<<'\n' : cout<<"Even"<<'\n';
        */
    
    /*// print digits of a number
        int n;
        cin>>n;
        printDigits(n);
        printDigits2(n);
    */

    /*// print number from digits
        int n;
        cin>>n;
        int ans = printNum(n);
        cout << ans <<'\n';
    */

    /*// print number of set bits
    // For signed numbers, the sign bit is used to fill the vacated bit positions. In other words, if the number is positive, 0 is used, and if the number is negative, 1 is used.
        int n;
        cin>>n;
        int ans = countSetBit(n);
        cout << ans << '\n';
    */
    
    /*// convert km to miles
        int n;
        cin>>n;
        float ans = getMiles(n);
        cout << ans << '\n';
    */

    /*// oveflow in char
        char ch = 227;
        cout<<ch<<'\n';
        cout<<(int)ch<<'\n';
        cout<<(int)(ch<<1)<<'\n';
    */

    return 0;
}