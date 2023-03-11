#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

bool isPrime(int n){
    if(n<=1)
        return false;
    
    for(int i=2; i<n; i++){
        if(n%i==0)
            return false;
    }

    return true;
}

int countPrimes(int n){
    int ans = 0;
    for(int i=2; i<n; i++){
        if(isPrime(i))
            ans++;
    }

    return ans;
}

bool isPrime2(int n){
    if(n<=1)
        return false;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0)
            return false;
    }

    return true;
}

// TC-O(n*sqrt(n))    SC-O(1)
int countPrimes2(int n){
    int ans = 0;
    for(int i=2; i<n; i++){
        if(isPrime2(i))
            ans++;
    }

    return ans;
}

int countPrimes3(int n){
    if(n<=1)
        return 0;
    
    vector<bool>primes(n,true);
    int ans = 0;
    
    primes[0] = primes[1] = 0;

    for(int i=2; i<n; i++){
        if(primes[i]){
            ans++;
            for(int j=2*i; j<n; j+=i)
            // for(int j=i*i; j<n; j+=i)        // will also work
                primes[j] = false;
        }
    }

    return ans;
}

int gcd(int a, int b){
    if(a==0)
        return b;
    else if(b==0)
        return a;
    
    while(a>0 && b>0){
        if(a>b)
            a = a - b;
        else
            b = b - a;
    }

    // (a==0) ? return b : return a;    // will give error
    return (a==0) ? b : a;

}

int slowExponentiation(int a, int b){
    int ans = 1;

    for(int i=0; i<b; i++){
        ans *= a;
    }

    return ans;
}

int fastExponentiation(int a, int b){
    int ans = 1;

    while(b){
        if(b&1)
            ans = ans * a;
        a *= a;
        b = b>>1;
    }

    return ans;
}

long long int modularExponentiation(long long int a,long long int b,long long int m)
{
    // Code here
    long long ans = 1;
    
    while(b){
        if(b&1)
            ans = (ans % m) * (a % m);
        a = (a % m) * (a % m);
        b = b >> 1;
    }

    return ans % m;
}

int main(){

    /*// count primes
        int n;
        cin>>n;

        // naive approach
        int ans = countPrimes(n);
        cout << ans << '\n';

        // sqrt approach
        int ans2 = countPrimes(n);
        cout << ans2 << '\n';

        // sieve of eratosthenes theorem / seive theorem
        int ans3 = countPrimes3(n);
        cout << ans3 << '\n';
    */

    /*// gcd
        int a, b;
        cin>>a>>b;
        int ans = gcd(a,b);
        cout << ans << '\n';
    */

    /*// exponentiation
        int a,b;
        cin>>a>>b;
        int ans = slowExponentiation(a,b);
        cout << ans << '\n';

        int ans2 = fastExponentiation(a,b);
        cout << ans2 << '\n';
    */

    /*// modular exponentiation for large numbers
        long long a, b, m;
        cin >> a >> b >> m;
        long long ans = modularExponentiation(a, b, m);
        cout << ans << '\n';
    */

    return 0;
}

/*INPUTS
// count primes
100

// gcd
10 6

// exponentiation
5 4

// Modular Exponentiation for large numbers
3 2 4
*/