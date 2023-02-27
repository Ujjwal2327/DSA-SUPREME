#include<iostream>
#include<vector>
using namespace std;

// TC-O(n)    SC-O(1)
void printVector(vector<int>arr){
    int n = arr.size();

    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

// TC-O(n^2)    SC-O(1)
void selectionSort(vector<int>arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[mini] > arr[j])
                mini = j;
        }
        swap(arr[mini], arr[i]);
    }

    printVector(arr);
}

// TC-O(n^2) in worst and average case    TC-O(n) in best case    SC-O(1)
void bubbleSort(vector<int>arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        bool swapping = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapping = true;
            }
        }

        if(swapping==false)
            break;
    }

    printVector(arr);
}

void insertionSort(vector<int>arr){
    int n = arr.size();

    for(int i=1; i<n; i++){
        int curr = arr[i];
        
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j] > curr)
                // shift
                arr[j+1] = arr[j];
            else{
                // break
                break;
            }
        }
        // insert
        arr[j+1] = curr;
    }

    printVector(arr);
}

int main(){

    vector<int>arr{10,1,4,8,5,6};

    selectionSort(arr);
    bubbleSort(arr);
    insertionSort(arr);

    return 0;
}