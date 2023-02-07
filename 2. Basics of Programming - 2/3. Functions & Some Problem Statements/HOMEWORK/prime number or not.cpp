// check whether the given number is prime or not

// https://www.geeksforgeeks.org/c-program-to-check-prime-number/

#include<iostream>
using namespace std;

bool isPrime(int n){
    bool flag = 1;
    for(int i=2; i<n; i++){
        if(n%i==0)
            flag = 0;
    }
    if(flag)
        return true;
    else
        return false;
}

bool isPrime2(int n){
    bool flag = 1;
    for(int i=2; i<n; i++){
        if(n%i==0)
            return false;
    }
    return true;
}

bool isPrime3(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){

    int n;
    cin>>n;
    // isPrimw
    if(isPrime(n))
        cout<<"prime"<<'\n';
    else
        cout<<"not a prime"<<'\n';

    // isPrimw2
    if(isPrime2(n))
        cout<<"prime"<<'\n';
    else
        cout<<"not a prime"<<'\n';

    // isPrimw3
    if(isPrime3(n))
        cout<<"prime"<<'\n';
    else
        cout<<"not a prime"<<'\n';


    return 0;
}