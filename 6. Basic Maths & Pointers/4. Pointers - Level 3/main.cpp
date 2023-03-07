#include<iostream>
using namespace std;

void solve(int **p){
    (**p)++;
    (*p)++;
    p++;
}

void update(int &a){
    a++;
}

void update2(int* &p){
    (*p)++;
}

int* solve(){
    int a = 5;
    int *ptr = &a;
    cout << ptr<<'\n';
    return ptr;
}

int main(){

    /*// multilevel pointers
        int a = 5;
        int *ptr = &a;
        int **ptr2 = &ptr;
        int ***ptr3 = &ptr2;
        cout << &a << ' ' << a << '\n';
        cout << &ptr << ' ' << ptr << ' ' << *ptr << '\n';
        cout << &ptr2 << ' ' << ptr2 << ' ' << *ptr2 << ' ' << **ptr2 << '\n';
        cout << &ptr3 << ' ' << ptr3 << ' ' << *ptr3 << ' ' << **ptr3 << ' ' << ***ptr3 << '\n';
    */

    /*// pointers and functions
        int a = 5;
        int *ptr = &a;
        int **ptr2 = &ptr;
        cout << a << ' ' << ptr << ' ' << ptr2 << '\n';
        solve(ptr2);
        cout << a << ' ' << ptr << ' ' << ptr2 << "\n\n";

        a = 5;
        ptr = &a;
        ptr2 = &ptr;
        cout << a << ' ' << ptr << ' ' << ptr2 << '\n';
        solve(&ptr);
        cout << a << ' ' << ptr << ' ' << ptr2 << "\n\n";
    */

    /*// reference variable
        int a = 5;
        int &b = a;
        cout << a << ' ' << b << '\n';
        cout << &a << ' ' << &b << '\n';
        a++;
        cout << a << ' ' << b << '\n';
        b++;
        cout << a << ' ' << b << '\n';
    */

    /*// reference variables in functions
        int a = 5;
        cout << a << '\n';

        update(a);
        cout << a << '\n';

        // update2(&a);     // will give error
        int *ptr = &a;
        update2(ptr);
        cout << a << '\n';
    */

    /*
    */
    // 
        // int *ptr = solve();
        // cout << *ptr<<'\n';
        // cout << ptr<<'\n';
        

    /*
    */
    // 

    /*
    */
    // 

    return 0;
}