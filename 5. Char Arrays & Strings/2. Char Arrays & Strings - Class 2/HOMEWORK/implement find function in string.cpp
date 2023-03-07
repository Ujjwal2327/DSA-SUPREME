#include<iostream>
using namespace std;

unsigned int find(string s, string part){
    int n = s.length();
    int m = part.length();
    int j=0;

    if(m>n)
        return string::npos;

    for(int i=0; i<n; i++){
        if(j==m)
            return i-m;

        if(s[i] == part[j])
            j++;
        else
            j = 0;
    }
    if(j==m)
        return n-m;

    return string::npos;
}

int main(){

    string s;
    getline(cin, s);
    string part;
    getline(cin, part);

    unsigned int ans = find(s, part);
    cout<<ans<<'\n';

    if(ans == string::npos)
        cout<<"not found\n";

    return 0;
}

/*INPUTS
This is my first para
first

This is my first para
second
*/