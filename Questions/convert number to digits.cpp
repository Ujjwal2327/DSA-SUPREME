// print digits of a number

#include<iostream>
using namespace std;

// print digits in reverse order
void numToDigits(int n){
    while(n){
        int rem = n % 10;
        n = n/10;
        cout << rem << ' ';
    }
    cout<<'\n';
}

// print digits in reverse order
void numToDigits2(int n){
    for( ; n>0; n=n/10){
        int rem = n % 10;
        cout << rem <<' ';
    }
    cout<<'\n';
}

int main(){
    int n;
    cin>>n;
    numToDigits(n);
    numToDigits2(n);

    return 0;
}

/*INPUTS
12345
*/