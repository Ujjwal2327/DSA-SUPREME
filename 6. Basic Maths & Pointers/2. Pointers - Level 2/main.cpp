#include<iostream>
using namespace std;

void func(int arr[]){
    cout << "inside function func\n";
    cout << arr << ' ' << *arr << ' ' << &arr << ' ' << sizeof(arr) << "\n\n";
}

void func2(int *arr){
    cout << "inside function func2\n";
    cout << arr << ' ' << *arr << ' ' << &arr << ' ' << sizeof(arr) << "\n\n";
}

void update(int * p){
    *p = *p + 10;
}

int main(){

    /*// arrays
        int arr[] = {10,20,30,40,50};
        cout << arr[0] << '\n';
        cout << &arr[0] << '\n';
        cout << arr << '\n';
        cout << &arr << '\n';
        cout << *arr << '\n';
        cout << *arr + 1 << "\n\n";

        cout << arr[1] << '\n';
        cout << *(arr + 1) << '\n';
        cout << 1[arr] << '\n';
    */

    /*// difference in arrays and pointers
        int arr[] = {10,20,30,40,50};
        int *ptr = arr;
        cout << arr << ' ' << &arr << '\n';
        cout << ptr << ' ' << &ptr << '\n';
        cout<<'\n';

        // arr++;       // will give error
        ptr++;

        cout << sizeof(arr) << ' ' << sizeof(ptr) << '\n';
        cout << sizeof(arr) << ' ' << sizeof(ptr2) << '\n';
    */

    /*// why is it giving ERROR??
        int arr[] = {10,20,30,40,50};
        int *ptr = arr;
        // int *ptr2 = &arr;    // will give error
        int *ptr3 = &arr[0];
    */

    /*// char arrays and pointers
        char ch[] = "Sherbano";
        char *ptr = ch;
        cout << ch << '\n';
        cout << *ch << '\n';
        cout << &ch << '\n';
        cout << *(ch+3) << '\n';
        cout << ptr << '\n';
        cout << &ptr << '\n';
        cout << *(ptr+3) << '\n';
        cout << ptr+2 << '\n';
        cout << *ptr << '\n';
        cout << ptr+8 << '\n';
        cout << ptr+9 << '\n';
        cout << ch[0] << '\n';
        cout << &ch[0] << '\n';
        cout << &(*ch) << '\n';
    */

    /*// char and char pointer
        char ch = 'k';
        char * ptr = &ch;
        cout << ch << '\n';
        cout << &ch << '\n';
        cout << ptr << '\n';
        cout << &ptr << '\n';
        cout << *ptr << '\n';
    */

    /*// bad practice
        char ch[] = "Babbar";
        cout << ch << '\n';

        char *ch2 = "Babbar";       // BAD PRACTICE
        cout << ch2 << '\n';
    */

    /*// pointers with functions
        int arr[10] = {10,20};
        for(int i=0; i<5; i++)
            cout << arr[i] << ' ';
        cout<<'\n';
        cout << "outside function\n";
        cout << arr << ' ' << *arr << ' ' << &arr << ' ' << sizeof(arr) << "\n\n";
        func(arr);
        func2(arr);
    */

    /*// pointers with functions 2
        int a = 5;
        int *ptr = &a;
        update(ptr);
        cout << a << '\n';
    */

    return 0;
}