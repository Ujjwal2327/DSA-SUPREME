#include<iostream>
using namespace std;
int main(){

    // patterns
        /*// pattern 1 numeric full pyramid
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                // spaces
                for(int j=0; j<n-(i+1); j++){
                    cout<<' ';
                }
                // counting
                for(int j=0; j<i+1; j++){
                    cout<<i+1+j;
                }
                // reverse counting
                int start = 2*i;
                for(int j=0; j<i; j++){
                    cout<<start;
                    start--;
                }
                cout<<'\n';
            }
        */

        /*// pattern 2 numeric hollow pyramid
            int n;
            cin>>n;
            // all except last rows
            for(int i=0; i<n-1; i++){
                // spaces
                for(int j=0; j<n-(i+1); j++){
                    cout<<' ';
                }
                // number and spaces
                for(int j=0; j<2*i+1; j++){
                    if(j==0)
                        cout << 1;
                    else if(j==2*i)
                        cout << i+1;
                    else
                        cout<<' ';
                }
                cout<<'\n';
            }
            // last row
            for(int j=0; j<n; j++){
                cout<<j+1<<' ';
            }
        */

    /*// bitwise operators
        bool a = true;
        bool b = false;
        cout<<(a&b)<<'\n';
        cout<<(a|b)<<'\n';
        cout<<(~a)<<'\n';
        cout<<(a^b)<<"\n\n";

        cout<<(2&3)<<'\n';
        cout<<(5&10)<<'\n';
        cout<<(3|4)<<'\n';
    */

    // left and right shift operators
        /*// left shift operator
            int a=5;
            a = a << 1;
            cout << a << '\n';
            a=5;
            a = a << 2;
            cout << a << '\n';
            a=5;
            a = a << 3;
            cout << a << '\n';
            
            // when MSB is 1 and 2nd MSB is 0
            a=-2147483640;
            a = a << 1;
            cout << a << '\n';
        */
        
        /*// right shift operator
            int b=25;
            b = b >> 1;
            cout << b << '\n';
            b=25;
            b = b >> 2;
            cout << b << '\n';
            b=25;
            b = b >> 3;
            cout << b << '\n';

            // for negative numbers     compiler is smart so shows divide by 2
            b=-12;
            b = b >> 1;
            cout << b << '\n';
        */

    // pre / post -> increament / decreament operators
        /*int a = 11;
        cout << a << '\n';
        */

        /*// pre increament
            int a = 11;
            cout << ++a << '\n';
            cout << a << '\n';
        */

        /*// pre increament
            int a = 11;
            cout << a++ << '\n';
            cout << a << '\n';
        */

        // examples
            /*
            int a = 6;
            int c = ++a + 1;
            cout << c <<'\n';
            */

            /*
            int a = 6;
            int c = a++ + 1;
            cout << c <<'\n';
            */

            /*
            int a=3;
            int b=4;
            int c = (++a) * (--b);
            cout << c<< '\n';
            */

            /*
                int a=3;
                int b=4;
                int c = (--a) * (b++);
                cout << c<< '\n';
            */

            /*
                int a=5;
                cout << (++a) * (++a) <<'\n';
            */

    // break and continue
        /*// break
            int n = 5;
            for(int i=0; i<n; i++){
                cout << "Babbar" <<'\n';
                break;
            }
            cout << "Love" << '\n';
        */

        /*// continue
            int n = 5;
            for(int i=0; i<n; i++){
                if(i==2)
                    continue;
                cout << i <<'\n';
            }
        */

    /*// variable scoping
        // declaration
        int a;

        // initialization
        int b = 5;

        // updatation
        b=10;

        // redefination is not allowed
        // int b = 15;

        if(true){
            int b = 15;
            cout << b << '\n';
        }
        cout << b << '\n';
    */

    /*// switch case
        int val;
        cin>>val;
        switch(val+1){
            case 2:
                cout << "Love" <<'\n';
                break;
            case 4:
                cout << "Babbar" <<'\n';
                break;
            case 5:
                cout << "Ramesh" <<'\n';
                // continue;
                cout << "Keshav" <<'\n';
            case 8:
                cout << "Suresh" <<'\n';
                break;
            default:
                cout << "Ujjwal" <<'\n';
        }
    */

    return 0;
}