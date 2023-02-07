// Print hollow full pyramid pattern.
//     *
//    * *
//   *   *
//  *     *
// *********

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; ++i) {
		int k=0;
        for (int j=0; j<n+i; ++j) {
            // left spaces
            if(j<n-i-1){
                cout<<" ";
            }
            // middle stars and spaces
            else if(k < 2*i+1){
                if(k==0 || k == 2*i || i == n - 1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
                k++;
            }
            // right spaces (no need to implement)
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}