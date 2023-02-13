// find the sum of 2 given numbers

#include<iostream>
using namespace std;

// function declaration
int add(int a, int b);

int main(){
    
    int a;
    cin>>a;
    int b;
    cin>>b;
    int sum = add(a, b);
    cout << sum << '\n';

    return 0;
}

// function definition
int add(int a, int b){
    int result = a + b;
    return result;
}

/*INPUTS
2 5
*/