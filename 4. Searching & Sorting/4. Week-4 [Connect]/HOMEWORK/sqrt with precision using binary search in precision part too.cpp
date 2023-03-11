#include<iostream>
using namespace std;

int intSqrt(int n){
    int s = 0;
    int e = n;
    int ans = 0;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(mid*mid<=n){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    return ans;
}

double sqrt(double n, int precision){
    double ans = intSqrt(n);

    double step = 1;
    while(precision--){
        step = step / 10;
        int s = 1;
        int e = 9;
        int correct = 0;

        while(s<=e){
            int mid = s + (e-s)/2;

            if( (ans + mid*step) * (ans + mid*step) <=n ){
                correct = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        
        ans = ans + correct*step;
    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    int ans1 = intSqrt(n);
    cout << ans1 << '\n';

    double m;
    int precision;
    cin>>m>>precision;
    double ans2 = sqrt(m, precision);
    cout << ans2 << '\n';

    return 0;
}

/*INPUTS
24
24 5
*/