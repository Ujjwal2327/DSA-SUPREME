// https://www.geeksforgeeks.org/function-pointer-in-cpp/
// https://www.geeksforgeeks.org/address-function-c-cpp/

#include<iostream>
using namespace std;

void func(int a){
    a++;
}

int main(){

    int a = 5;
    func(a);
    
    cout << main << ' ' << &main << '\n';
    cout << func << ' ' << &func << '\n';
    auto *ptr = &func;
    cout << ptr << ' ' << *ptr << '\n';

    return 0;
}