// cin in if(cin>>a) and cout in if(cout<<a)

#include<iostream>
using namespace std;

int main(){

    // cin in if
        int num;
        if(cin>>num){   // work on all +ve, -ve and 0
            cout<<num<<'\n';
            cout<<"cin Chl to raha hai";
        }
        else{
            cout<<"cin Nahi chl raha hai";
        }
        cout<<'\n';

    // cout in if
        cin>>num;
        if(cout<<"cout in if() condition-> "<<num<<'\n'){    // work on all +ve, -ve and 0
            cout<<num<<'\n';
            cout<<"cout Chl to raha hai";
        }
        else{
            cout<<"cout Nahi chl raha hai";
        }

    return 0;
}

/*INPUTS
// works with any +ve, -ve and 0
*/