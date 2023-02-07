// heart star pattern.
//  e.g., for size=6;
//  ***   ***
// ***** *****
// ***********
//  *********
//   *******
//    *****
//     ***
//      *

//  e.g., for size=7, pattern should be this
//  ****   ****
// ****** ******
// *************
//  ***********
//   *********
//    *******
//     *****
//      ***
//       *

#include <iostream>
using namespace std;

void printUpperPart(int size, int i){
    // left spaces
    for(int j=0; j<(size-i)/2; j++){
        cout<<' ';
    }
    // left stars
    for(int j=0; j<i; j++){
        cout<<'*';
    }
    // middle spaces
    for(int j=0; j<size-i; j++){
        cout<<' ';
    }
    // right stars
    for(int j=0; j<i; j++){
        cout<<'*';
    }
    cout<<'\n';
}

int main()
{
    // heart star pattern
    int size;
    cin >> size;

    // upper part
    if(size&1){
        if(((size+1)/2)&1){
            for(int i=(size+1)/2 - 1; i<size; i+=2){
                printUpperPart(size, i);
            }
        }
        else{
            for(int i=(size+1)/2; i<size; i+=2){
                printUpperPart(size, i);
            }
        }
    }
    else{
        if(((size-1)/2) & 1){
            for(int i=(size-1)/2; i<size; i+=2){
                printUpperPart(size, i);
            }
        }
        else{
            for(int i=(size-1)/2 + 1; i<size; i+=2){
                printUpperPart(size, i);
            }
        }
    }

    // lower part
    // inverted pyramid
    for (int i = size; i > 0; i--)
    {
        for (int j = 0; j < size - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j < i * 2; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}