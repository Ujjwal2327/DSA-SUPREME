#include<iostream>
using namespace std;

int & ref(int &i){
    return i;
}

int g = 5;

int & ref2(){
    return g;
}

int ref3(){
    return g;
}

int & badRef(int i){
    return i;
}

int main(){

    /*// return by reference using pass by reference
        int a = 10;
        int &b = a;
        int x = 20;

        ref(a) = x;
        x++;
        cout << a << ' ' << b<< ' ' << x << "\n\n";

        ref(b) = x;
        x++;
        cout << a << ' ' << b<< ' ' << x << "\n\n";

        int c = ref(a);
        cout << a << ' ' << b << ' ' << x << ' ' << c << "\n\n";

        int &d = ref(a);
        cout << a << ' ' << b << ' ' << d << ' '  << x << ' ' << c << "\n\n";
        cout << &a << ' ' << &b << ' ' << &d << ' '  << &x << ' ' << &c << "\n\n";
    */

    /*// return by reference using passing a global variable
        cout << g << '\n';
        ref2() = 10;
        cout << g << '\n';
    */

    /*// alert with this case
        cout << g << '\n';
        // ref3() = 10;         // ERROR as ref3 function returns value, not variable
        cout << g << '\n';
        // 10=20;               // returning a same ERROR as 2 line above
    */

    /*// alert with this case (pass by value but return by refeerence)
        int a = 10;
        int &b = a;
        int x = 20;

        badRef(a) = x;
        x++;
        cout << a << ' ' << b<< ' ' << x << "\n\n";

        badRef(b) = x;
        x++;
        cout << a << ' ' << b<< ' ' << x << "\n\n";

        int c = badRef(a);
        cout << a << ' ' << b << ' ' << x << ' ' << c << "\n\n";

        int &d = badRef(a);
        cout << a << ' ' << b << ' ' << d << ' '  << x << ' ' << c << "\n\n";
        cout << &a << ' ' << &b << ' ' << &d << ' '  << &x << ' ' << &c << "\n\n";
    */

    return 0;
}