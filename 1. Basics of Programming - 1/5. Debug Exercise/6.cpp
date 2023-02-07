// Print Numeric Hollow Inverted Half Pyramid (Click the hyper link to understand the output)
// https://mycareerwise.com/storage/editor/images/Inverted%20Hollow%20Right%20Number%20Triangle.png

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<=n;j++){
            if(j==i+1 || j == n || i == 0){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}