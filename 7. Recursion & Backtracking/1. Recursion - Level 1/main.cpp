#include<iostream>
using namespace std;

int fact(int n){
    // base condition
    if(n==0)
        return 1;

    // recurrence relation
    return n*fact(n-1);
}

void printReverseCounting(int n){
    // base condition
    if(n==0)
        return;
    
    // processing
    cout << n << ' ';

    // recurrence relation
    printReverseCounting(n-1);
}

void printCounting(int n){
    // base condition
    if(n==0)
        return;
    
    // recurrence relation
    printCounting(n-1);

    // processing
    cout << n << ' ';
}

int fib(int n){
    if(n==0 || n==1)
        return n;
    
    return fib(n-1) + fib(n-2);
}

int main(){

    /*// factorial of given number
        int n;
        cin>>n;
        int ans = fact(n);
        cout << ans << '\n';
    */

    /*// print reverse counting
        int n;
        cin>>n;
        printReverseCounting(n);
    */

    /*// print counting from 1 to n
        int n;
        cin>>n;
        printCounting(n);
    */

    /*// fibonacci number      starts from 0
        int n;
        cin>>n;
        int ans = fib(n);
        cout << ans << '\n';
    */

    return 0;
}