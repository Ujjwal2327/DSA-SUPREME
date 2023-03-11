#include<iostream>
using namespace std;

int* solve(){
    int a = 5;
    int *ptr = &a;
    cout << *ptr<<' ' << ptr<<'\n';
    return ptr;
}

int main(){

    int *ptr = solve();     // remember here pointer is pointing to temporary memory
    cout << *ptr<<' ' << ptr<<'\n';

    return 0;
}