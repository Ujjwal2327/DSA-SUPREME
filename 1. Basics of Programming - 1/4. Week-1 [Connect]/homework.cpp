#include<iostream>
using namespace std;
int main(){

    // add 2 short with values 32767 and 10 and store in another short and print
    // overflow case
        short s1 = 32767;
        short s2 = 10;
        short s = s1+s2;
        cout<<s;

    return 0;
}