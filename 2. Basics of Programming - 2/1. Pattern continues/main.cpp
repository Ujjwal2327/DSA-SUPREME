#include<iostream>
using namespace std;

int main(){

    /*// pattern 1
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            // spaces
            for(int j=0; j<n-(i+1); j++){
                cout<<" ";
            }

            // stars
            for(int j=0; j<i+1; j++){
                cout<<"* ";
            }
            cout<<'\n';
        }
    */
    
    /*// pattern 2
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            // spaces
            for(int j=0; j<i; j++){
                cout<<' ';
            }

            // stars
            for(int j=0; j<n-i; j++){
                cout<<"* ";
            }
            cout<<'\n';
        }
    */

    /*// pattern 3    solid diamond
        int n;
        cin>>n;
        // upper half
        for(int i=0; i<n; i++){
            // spaces
            for(int j=0; j<n-(i+1); j++){
                cout<<' ';
            }

            // stars
            for(int j=0; j<i+1; j++){
                cout<<"* ";
            }
            cout<<'\n';
        }
        // lower half
        for(int i=0; i<n; i++){
            // spaces
            for(int j=0; j<i; j++){
                cout<<' ';
            }
            for(int j=0; j<n-i; j++){
                cout<<"* ";
            }
            cout<<'\n';
        }
    */

    // pattern 4    hollow diamond
        /*// method 1
            int n;
            cin>>n;
            // upper half
            for(int i=0; i<n; i++){
                // spaces
                for(int j=0; j<n-(i+1); j++){
                    cout<<' ';
                }
                // stars and spaces
                for(int j=0; j<i+1; j++){
                    // stars
                    if(j==0 || j==i){
                        cout<<"* ";
                    }
                    // spaces
                    else{
                        cout<<"  ";
                    }
                }
                cout<<'\n';
            }
            // lower half
            for(int i=0; i<n; i++){
                // spaces
                for(int j=0; j<i; j++){
                    cout<<' ';
                }
                // ṣtars and spaces
                for(int j=0; j<n-i; j++){
                    // stars
                    if(j==0 || j==n-i-1){
                        cout<<"* ";
                    }
                    // spaces
                    else{
                        cout<<"  ";
                    }
                }
                cout<<'\n';
            }
        */

        /*// method 2
            int n;
            cin>>n;
            // upper half
            for(int i=0; i<n; i++){
                // spaces
                for(int j=0; j<n-(i+1); j++){
                    cout<<' ';
                }
                // stars and spaces
                for(int j=0; j<2*i+1; j++){
                    // stars
                    if(j==0 || j==2*i){
                        cout<<'*';
                    }
                    // spaces
                    else{
                        cout<<' ';
                    }
                }
                cout<<'\n';
            }
            // lower half
            for(int i=0; i<n; i++){
                // spaces
                for(int j=0; j<i; j++){
                    cout<<' ';
                }
                // stars and spaces
                for(int j=0; j<2*n-(2*i+1); j++){
                    // stars
                    if(j==0 || j==2*n-(2*i+1)-1){
                        cout<<'*';
                    }
                    // spaces
                    else{
                        cout<<' ';
                    }
                }
                cout<<'\n';
            }
        */

    /*// pattern 5  flipped solid diamond
        int n;
        cin>>n;
        // upper half
        for(int i=0; i<n; i++){
            // left stars
            for(int j=0; j<n-i; j++){
                cout<<'*';
            }
            // spaces
            for(int j=0; j<2*i+1; j++){
                cout<<' ';
            }
            // right stars
            for(int j=0; j<n-i; j++){
                cout<<'*';
            }
            cout<<'\n';
        }
        // lower half
        for(int i=0; i<n; i++){
            // left stars
            for(int j=0; j<i+1; j++){
                cout<<'*';
            }
            // spaces
            for(int j=0; j<2*n-(2*i+1); j++){
                cout<<' ';
            }
            // right stars
            for(int j=0; j<i+1; j++){
                cout<<'*';
            }
            cout<<'\n';
        }
    */

    /*// pattern 6    fancy pattern #2
        int n;
        cin>>n;
        // upper half
        for(int i=0; i<n; i++){
            for(int j=0; j<i+1; j++){
                cout<<i+1;
                // * not print for last char
                if(j!=i){
                    cout<<'*';
                }
            }
            cout<<'\n';
        }
        // lower half
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i; j++){
                cout<<n-i;
                // * not print for last char
                if(j!=n-i-1){
                    cout<<'*';
                }
            }
            cout<<'\n';
        }
    */

    /*// pattern 7    alphabet palindrome pattern
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            // counting
            for(int j=0; j<i+1; j++){
                cout << (char) ('A'+j);
            }
            // reverse counting
            for(int j=0; j<i; j++){
                cout << (char) ('A'+i-1-j);
            }
            cout<<'\n';
        }
    */

    return 0;
}