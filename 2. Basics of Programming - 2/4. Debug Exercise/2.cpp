// Print full pyramid like an Equilateral Triangle
// https://b2045649.smushcdn.com/2045649/wp-content/uploads/2021/05/image-1.png?lossy=1&strip=1&webp=1

#include <iostream>
using namespace std;
int main()
{
    int k, n;
    cout << "Enter the number of rows : ";
    cin >> n;
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n - i; j++)
            cout << ' ';

        int k = i;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j <= k)
                cout << j;
            else{
                k--;
                cout << k;
            }
        }
        cout << endl;
    }
    return 0;
}