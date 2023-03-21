#include<iostream>
using namespace std;

int lastOcc(string &s, char &ch, int i){
    if(i<0)
        return -1;
    
    if(s[i]==ch)
        return i;
    else
        return lastOcc(s, ch, i-1);
}

int main(){

    string s = "babbar";
    char ch = 'r';
    int i=s.length();
    int ans = lastOcc(s, ch, i);
    cout << ans << '\n';

    return 0;
}