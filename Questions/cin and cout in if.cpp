#include<iostream>
using namespace std;

int main(){

    // cin in if
        int num;
        if(cin>>num){
            cout<<num<<'\n';
            cout<<"Chl to raha hai";
        }
        else{
            cout<<"Nahi chl raha hai";
        }

    // cout in if
        int num=0;
        if(cout<<num<<'\n'){
            cout<<num<<'\n';
            cout<<"Chl to raha hai";
        }
        else{
            cout<<"Nahi chl raha hai";
        }



    return 0;
}