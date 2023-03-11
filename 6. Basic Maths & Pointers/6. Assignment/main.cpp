#include<iostream>
using namespace std;

int main(){

    /*
    // 
        int *ptr = 0;
        int a = 10;
        cout<<ptr<<'\n';
        *ptr = a;           // runtime error
        cout<<ptr<<'\n';
    */

    /*
    // 
        char ch = 'a';
        char *ptr = &ch;
        ch++;
        cout<<*ptr<<'\n';
    */

    /*
    // 
        int arr[] = {1,2,3,4,5};
        int *ptr = arr++;       // error
        cout<<*ptr;
    */

    /*
    // 
        char s[] = "hello";
        cout<<s<<'\n';
        s++;        // error
        cout<<s<<'\n';
    */

    /*
    // 
        double arr[] = {1,2,3,4,5};
        double *ptr = arr;
        cout<<ptr;
        ptr +=0.25;
        cout<<ptr;
    */

    /*
    // 
        int arr[] = {1,2,3,4,5};
        int * ptr1 = arr;
        int * ptr2 = arr+3;
        cout << ptr2 - ptr1 << '\n';
    */

    /*
    // 
        int a = 5;
        int *ptr = &a;
        int ** ptr2 = &ptr;
        ptr2 = &a;  // error
    */

    return 0;
}