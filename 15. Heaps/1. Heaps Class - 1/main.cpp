#include<iostream>
using namespace std;

// 1 based indexing
class Heap{
    int arr[101];

    public:
    int size;

    Heap(){
        this->size = 0;
    }

    //TC-O(logn)
    void insert(int value){
        if(size>=101){
            cout << "heap overflow\n";
            return;
        }

        size++;
        arr[size] = value;

        // place at its correct position
        int index = size;
        while(index>1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
                break;
        }
    }

    void print(){
        for(int i=1; i<=size; i++)
            cout << arr[i] << ' ';
        cout << "\n\n";
    }

    //TC-O(logn)
    int deleteNode(){
        if(size==0){
            cout << "heap underflow\n";
            return -1;
        }

        int ans = arr[1];

        // replace root node data with last node data
        swap(arr[1],arr[size]);
        size--;

        // place root node data to its correct position
        int index = 1;
        while(index<=size){
            int largest = index;
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1;
            
            if(leftIndex <= size && arr[largest] < arr[leftIndex])
                largest = leftIndex;
            
            if(rightIndex <= size && arr[largest] < arr[rightIndex])
                largest = rightIndex;
            
            if(largest != index){
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
                break;
        }

        return ans;
    }

};

void heapify(int arr[], int n, int index){

    while(index<n){
        int largest = index;
        int leftIndex = 2*index;
        int rightIndex = 2*index + 1;
        if(leftIndex < n && arr[largest] < arr[leftIndex])
            largest = leftIndex;
        
        if(rightIndex < n && arr[largest] < arr[rightIndex])
            largest = rightIndex;
        
        if(largest != index){
            swap(arr[largest], arr[index]);
            index = largest;
        }
        else
            break;
    }
}

void heapify2(int arr[], int n, int index){
    if(index>=n)
        return;

    int largest = index;
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;

    if(leftIndex < n && arr[largest] < arr[leftIndex])
        largest = leftIndex;
    
    if(rightIndex < n && arr[largest] < arr[rightIndex])
        largest = rightIndex;
    
    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify2(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    int heapSize = n-1;
    for(int i=heapSize/2; i>0; i--)
        heapify2(arr, n, i);
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << "\n\n";
}

void heapSort(int arr[], int n){

    buildHeap(arr,n);
    int index = n-1;
    while(index!=1){
        swap(arr[1], arr[index]);
        heapify(arr,index,1);
        index--;
    }
}

class DynamicHeap{
    public:
    int* arr;
    int size;

    DynamicHeap(int size){
        arr = new int[size];
        this->size = 0;
    }
    
};

int main(){

    Heap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(30);
    h1.insert(40);
    h1.insert(50);
    h1.print();

    cout << h1.deleteNode() << '\n';
    h1.print();

    cout << h1.deleteNode() << '\n';
    h1.print();

    cout << h1.deleteNode() << '\n';
    h1.print();

    cout << h1.deleteNode() << '\n';
    h1.print();

    cout << h1.deleteNode() << '\n';
    h1.print();

    cout << h1.deleteNode() << '\n';
    h1.print();

    cout << "hiiiiii\n";
   
    int arr[] = {-1,12,15,13,11,14};
    int n = 6;
    buildHeap(arr, n);
    printArray(arr,n);

    heapSort(arr,n);
    printArray(arr,n);




    return 0;
}