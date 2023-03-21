#include<iostream>
using namespace std;

void reverse(string &s, int i){
    if(i == s.length()/2)
        return;
    
    swap(s[i], s[s.length()-1-i]);
    reverse(s, i+1);

    // both head and tail recursion give correct result
}

int main(){

    string s = "Ujjwal2027";
    int i = 0;
    reverse(s, i);
    cout << s << '\n';

    return 0;
}