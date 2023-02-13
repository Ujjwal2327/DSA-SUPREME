// linear search in an array

#include<iostream>
using namespace std;

void inputArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

bool linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(key == arr[i])
            return true;
    }
    return false;
}

int main(){

    // linear search function
        int arr[500];
        int n;
        cin>>n;
        inputArray(arr, n);
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

/*INPUTS
5
1 6 2 3 73
6
*/