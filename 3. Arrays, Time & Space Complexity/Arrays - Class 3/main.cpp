#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void inputMatrix(int arr[][500], int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }
}

void printMatrix(int arr[][500], int rows, int cols){
    cout << '\n';
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printRowWiseSum(int arr[][3], int rows, int cols){
    for(int i=0; i<rows; i++){
        int sum = 0;
        for(int j=0; j<cols; j++){
            sum += arr[i][j];
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

void printColWiseSum(int arr[][3], int rows, int cols){
    for(int j=0; j<cols; j++){
        int sum = 0;
        for(int i=0; i<rows; i++){
            sum += arr[i][j];
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

bool linearSearch(int arr[][500], int rows, int cols, int key){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(key==arr[i][j])
                return true;
        }
    }
    return false;
}

void getMinMax(int arr[][3], int rows, int cols){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(arr[i][j] > maxi)
                maxi = arr[i][j];
            if(arr[i][j] < mini)
                mini = arr[i][j];
        }
    }
    cout<<mini<<' '<<maxi<<'\n';
}

// transpose of any rectangular matrix
void transpose(int arr[][500], int rows, int cols, int ans[][500]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            ans[j][i]=arr[i][j];
        }
    }
}

// transpose of a square matrix
void transpose2(int arr[][500], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main(){

    /*// declaration of 2D array
        int arr[3][3];
    */

    /*// initialization of 2D array
        int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
        cout << arr[2][0] << '\n';
    */

    /*// row-wise access
        int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
        int rows = 3;
        int cols = 3;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    */

    /*// col-wise access
        int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
        int rows = 3;
        int cols = 3;
        for(int j=0; j<cols; j++){
            cout<<"col"<<j<<"=> ";

            for(int i=0; i<rows; i++){
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n';
        }
    */

    /*// taking row wise input
        int arr[500][500];
        int rows = 4;
        int cols = 3;
        inputMatrix(arr, rows, cols);
        printMatrix(arr, rows, cols);
    */

    /*// taking col wise input
        int arr[500][500];
        int rows = 4;
        int cols = 3;
        for(int j=0; j<cols; j++){
            for(int i=0; i<rows; i++){
                cin>>arr[i][j];
            }
        }
        printMatrix(arr, rows, cols);
    */

    /*// print row sum
        int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
        printRowWiseSum(arr, 3, 3);
    */
    
    /*// print col sum
        int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
        printColWiseSum(arr, 3, 3);
    */

    /*// linear search in a 2D array
        int arr[500][500] = { {1,2,3}, {4,5,6}, {7,8,9} };
        int rows = 3;
        int cols = 3;
        int key;
        cin>>key;
        int ans = linearSearch(arr, rows, cols, key);
        if(ans)
            cout << "present\n";
        else        
            cout << "absent\n";
    */

    /*// maximum and minimum elements in an array
        int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
        getMinMax(arr, 3, 3);
    */
   
    /*// transpose of any rectangular matrix
        int arr[500][500] = { {1,2,3}, {4,5,6}, {7,8,9}, {1,3,5}, {2,4,8} };
        int rows = 5;
        int cols = 3;
        int ans[500][500];
        cout<<"1st method\n";
        printMatrix(arr, rows, cols);
        transpose(arr, rows, cols, ans);
        printMatrix(ans, cols, rows);
    */

    /*// transpose of a square matrix
        int arr[500][500] = { {1,2,3}, {4,5,6}, {7,8,9} };
        int size = 3;
        cout<<"2nd method\n";
        printMatrix(arr, size, size);
        transpose2(arr, size);
        printMatrix(arr, size, size);
    */

    /*// 2D vector      declaration, insertion, access
        // declaration
            vector<vector<int>>arr;
            vector<int>a{1,2,3};
            vector<int>b{4,5,6};
            vector<int>c{7,8,9};

        // insetion in 2D vector
            arr.push_back(a);
            arr.push_back(b);
            arr.push_back(c);

        // row-wise access in 2D vector
            for(int i=0; i<arr.size(); i++){
                for(int j=0; j<arr[0].size(); j++){
                    cout<<arr[i][j]<<' ';
                }
                cout<<'\n';
            }
            cout<<'\n';

        // row-wise access in 2D vector if number of elements in 1D vector are different
            for(int i=0; i<arr.size(); i++){
                for(int j=0; j<arr[i].size(); j++){     // arr[i].size()
                    cout<<arr[i][j]<<' ';
                }
                cout<<'\n';
            }
            cout<<'\n';
    */

    /*// initialization
        vector<vector<int>> arr (3, vector<int>(5,101));
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[0].size(); j++){
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';

        vector<vector<int>> arr2 (5, vector<int>(5,-8));
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<arr2[0].size(); j++){
                cout<<arr2[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';

        cout<<arr2[2][3]<<'\n';

        cin>>arr2[3][4];
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<arr2[0].size(); j++){
                cout<<arr2[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
    */

    return 0;
}