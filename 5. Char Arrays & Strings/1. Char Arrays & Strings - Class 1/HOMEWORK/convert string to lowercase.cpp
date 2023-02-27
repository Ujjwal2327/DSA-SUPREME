#include<iostream>
using namespace std;

// TC-O(n)    SC-O(1)
int getLength(char ch[]){

    int length = 0;
    int i=0;
    while(ch[i]!='\0'){
        length++;
        i++;
    }

    return length;
}

// TC-O(n)    SC-O(1)
void toLowerCase(char ch[]){

    int n = getLength(ch);

    for(int i=0; i<n; i++){
        if(ch[i]>='A' && ch[i]<='Z')
            ch[i] = ch[i] - 'A' + 'a';
    }

}

int main(){

    char ch[100];
    cin>>ch;
    toLowerCase(ch);
    cout<<ch<<'\n';

    return 0;
}

/*INPUTS
UJJwAL123
*/