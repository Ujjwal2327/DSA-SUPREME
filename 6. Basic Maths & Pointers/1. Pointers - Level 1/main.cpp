#include<iostream>
using namespace std;

int main(){

    /*// creating a pointer
        int a = 5;
        int b = 5;
        cout << a << ' ' << &a << '\n';
        cout << b << ' ' << &b << '\n';
    */

    /*// access the value pointer is pointing to
        int a = 5;
        int *ptr = &a;
        cout << "a-> " << a << '\n';
        // cout << "*a-> " << *a << '\n';   // will give error
        cout << "&a-> " << &a << '\n';
        cout << "ptr-> " << ptr << '\n';
        cout << "*ptr-> " << *ptr << '\n';
        cout << "&ptr-> " << &ptr << '\n';
    */

    /*// size of pointer
        int i = 5;
        int *p1 = &i;
        char ch = 'a';
        char *p2 = &ch;
        bool b = true;
        bool *p3 = &b;
        string s = "Ujjwal";
        string * p4 = &s;
        cout << sizeof(p1) << ' ' << sizeof(p2) << ' ' << sizeof(p3) << ' ' << sizeof(p4) << "\n\n";
        cout << i << ' ' << &i << ' ' << p1 << ' ' << &p1 << ' ' << *p1 << '\n';
        cout << b << ' ' << &b << ' ' << p3 << ' ' << &p3 << ' ' << *p3 << '\n';
        cout << s << ' ' << &s << ' ' << p4 << ' ' << &p4 << ' ' << *p4 << '\n';
        cout << ch << ' ' << &ch << ' ' << p2 << ' ' << &p2 << ' ' << *p2 << '\n';
    */

    /*// bad practice and NULL pointer
        // bad practice
        int *p;
        cout<<p<<'\n';

        // null pointers
        int *ptr = 0;
        cout << ptr << '\n' << *ptr << "\n\n";

        int *ptr2 = NULL;
        cout << ptr2 << '\n' << *ptr2 << "\n\n";

        int *ptr3 = nullptr;
        cout << ptr3 << '\n' << *ptr3 << "\n\n";
    */

    /*// pointer only stores address
        int a = 5;
        // int *ptr = a;    // will give error
        int *ptr = &a;
    */

    /*// copying a pointer
        int a = 5;
        int *ptr = &a;
        int *ptr2 = ptr;
        int *ptr3 = 0;
        ptr3 = ptr;
        cout << *ptr << ' ' << *ptr2 << ' ' << *ptr3 << '\n';
        cout << ptr << ' ' << ptr2 << ' ' << ptr3 << '\n';
        cout << &ptr << ' ' << &ptr2 << ' ' << &ptr3 << '\n';
    */

    return 0;
}