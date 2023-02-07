// Reverse Pyramid star pattern.
// e.g., N=5
// *********
//  *******
//   *****
//    ***
//     *

#include <iostream>
using namespace std;

int main()
{
    // size of the pyramid
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        // print spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // print stars
        for (int k = 0; k < 2 * size -2*i - 1; k++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}