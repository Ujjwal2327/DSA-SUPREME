#include<iostream>
using namespace std;

void swap1(int a, int b){
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<a<<' '<<b<<'\n';
}

void swap2(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout<<a<<' '<<b<<'\n';
}

void swap3(int a, int b){
    int x = a ^ b;
    int i=0;
    while(x){
        int curr = 1<<i;
        // if that bit in x is 1, then that bit is different in a and b
        if(x & curr ){
            // change that bit in a
            a = a ^ curr;
            // change that bit in b
            b = b ^ curr;
            // make that 1 bit to 0 in x
            x = x ^ curr;
        }
        i++;
    }
    cout<<a<<' '<<b<<'\n';
}

int main(){

    int a=5;
    int b=6;
    swap1(a,b);
    swap2(a,b);
    swap3(a,b);

    return 0;
}