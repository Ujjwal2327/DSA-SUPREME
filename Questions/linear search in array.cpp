// linear search in an array

#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(key == arr[i])
            return true;
    }
    return false;
}

int main(){

    // linear search function
        int arr[]={1,6,2,3,73};
        int n=5;
        int key;
        cin>>key;
        if(linearSearch(arr, n, key)){
            cout<<"present\n";
        }
        else{
            cout<<"absent\n";
        }

    // linear search without function
        bool flag=false;
        for(int i=0; i<n; i++){
            if(key == arr[i]){
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<"present\n";
        else
            cout<<"absent\n";

    return 0;
}