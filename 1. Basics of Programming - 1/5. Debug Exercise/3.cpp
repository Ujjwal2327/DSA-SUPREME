// Find perimeter of a rectangle.

#include<iostream>
using namespace std;

int main() {
	float l, b;
    cin>>l>>b;
	int P = 2*(l+b);
	printf("Perimeter=%d", P);
    
    return 0;
}