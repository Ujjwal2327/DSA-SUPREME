// Left Triangle star Pattern
// E.g., For N = 5
// *
// **
// ***
// ****
// *****

#include <iostream>
using namespace std;

int main() {
  // size of the triangle
  int size;
  cin>>size;
  // loop to print the pattern
  for (int i = 0; i < size; i++) {
    // print column
    for (int j = 0; j <= i; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}