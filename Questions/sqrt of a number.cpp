#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int sqrtInt(int n){
    int s=0;
    int e=n;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        long long prod = mid*mid;
        // for overflow, use mid==n/mid
        if(prod==n)
            return mid;
        else if(prod<n){
            ans = mid;
            s = mid+1;
        }
        else
            e = mid - 1;
        mid = s + (e-s)/2;
    }
    return ans;
}

double sqrtDouble(double n, int precision){
    int ans = sqrt(n);
    double step = 0.1;
    double finalAns = ans;
    for(int i=0; i<precision; i++){
        // int cnt = 0;
        // for(double j=finalAns; j*j<=n && cnt<10; j+=step){
        for(double j=finalAns; j*j<=n; j+=step){
            finalAns = j;
            // cnt++;
        }
        step = step/10;
    }
    return finalAns;
}

int main(){

    /*// sqrt of an int number
        int n;
        cin>>n;
        int ans = sqrtInt(n);
        cout<<ans<<'\n';
    */

    /*// sqrt of an double number upto given precision
        double n;
        cin>>n;
        int precision;
        cin>>precision;
        double ans = sqrtDouble(n, precision);
        cout<<ans<<'\n';
    */

    /*// using inbuilt sqrt function
        int n;
        cin>>n;
        cout << sqrt(n) << '\n';
    */

    return 0;
}

/*INPUTS
// sqrt of an int number
35

// sqrt of an double number upto given precision
35 6

// using inbuilt sqrt function
35
*/