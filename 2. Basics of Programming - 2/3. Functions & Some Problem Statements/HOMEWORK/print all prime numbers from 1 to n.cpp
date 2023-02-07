// print all prime numbers from 1 to n

// https://www.geeksforgeeks.org/program-to-print-first-n-prime-numbers/

#include<iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void printAllPrimes(int n){
    if(n<2)
        return;

    for(int i=2; i<=n; i++){
        if(isPrime(i))
            cout << i <<' ';
    }
    cout<<'\n';
}

int main(){

    int n;
    cin>>n;
    printAllPrimes(n);    

    return 0;
}