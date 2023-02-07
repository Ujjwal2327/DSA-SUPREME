#include<iostream>
using namespace std;

int main(){

    // conditionals
        /*// if 
            int score;
            cout<<"Enter the score"<<'\n';
            cin>>score;
            if(score<300){
                cout<<"India wins\n";
            }
            cout<<"Pakistan wins\n";
        */

        /*// if-else
            int score;
            cout<<"Enter the score"<<'\n';
            cin>>score;
            if(score<300){
                cout<<"India wins\n";
            }
            else{
                cout<<"Pakistan wins\n";
            }
        */

        // multiple conditions
            // int marks;
            // cin>>marks;
            
            /*// nested if-else
                if(marks>=90){
                    cout<<"A grade";
                }
                else{
                    if(marks>=80){
                        cout<<"B grade";
                    }
                    else{
                        if(marks>=60){
                            cout<<"C grade";
                        }
                        else{
                            if(marks>=40){
                                cout<<"D grade";
                            }
                            else{
                                cout<<"F grade";
                            }
                        }
                    }
                }
            */
            
            /*// if-else if-else
                if(marks>=90){
                    cout<<"A grade";
                }
                else if(marks>=80){
                    cout<<"B grade";
                }
                else if(marks>=60){
                    cout<<"C grade";
                }
                else if(marks>=40){
                    cout<<"D grade";
                }
                else{
                    cout<<"F grade";
                }
            */
        
        /*// example
            int broNum;
            cin>>broNum;
            if(broNum==0){
                cout<<"Baat ban jayegi\n";
            }
            else{
                cout<<"Baat nahi banegi\n";
            }
        */

    // loops
    // for loop
        /*
        for(int i=0; i<5; i++){
            cout << "Love Babbar" <<'\n';
        }
        */

        /*
        for(int i=0; i<5; i++){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=5; i>0; i--){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=1; i<=10; i++){
            cout << 2*i <<'\n';
        }
        */
        
        /*
        for(int i=0; i<=5; i=i+2){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=1; i<=5; i=i+2){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=1; i<10; i=i*2){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=100; i>0; i=i/2){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=5; (i>=0 && i<=10); i++){
            cout << i <<'\n';
        }
        */

        // what terms are necessary
            /*for(int i=0; i<5; i++){
                cout << i <<'\n';
            }
            */

            /*// removing initialization
            int i=0;
            for( ; i<5; i++){
                cout << i <<'\n';
            }
            */

            /*// removing condition
            int i=0;
            for( ; ; i++){
                if(i<5){
                    cout << i <<'\n';
                }
            }
            */
            
            /*// removing updatation
                // unlimited loop if break is not used
                int i=0;
                for( ; ; ){
                    if(i<5){
                        cout << i <<'\n';
                        i++;
                    }
                }
                */

    // patterns
        /*// pattern 1
            for(int row=0; row<3; row++){
                for(int col=0; col<5; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */
        
        /*// pattern 2
            int n;
            cin>>n;
            for(int row=0; row<n; row++){
                for(int col=0; col<n; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */

        /*// pattern 3
            int n;
            cin>>n;
            for(int row=0; row<3; row++){
                for(int col=0; col<5; col++){
                    if(row==0 || row==n-1){
                        cout<<"*";
                    }
                    else{
                        if(col==0 || col==4){
                            cout<<"*";
                        }
                        else{
                            cout<<" ";
                        }
                    }
                }
                cout<<'\n';
            }
        */
                
        /*// pattern 4
            int rowCount;
            int colCount;
            cin>>rowCount;
            cin>>colCount;
            for(int i=0; i<rowCount; i++){
                for(int j=0; j<colCount; j++){
                    if(i==0 || i==rowCount-1){
                        cout<<"*";
                    }
                    else{
                        if(j==0 || j==colCount-1){
                            cout<<"*";
                        }
                        else{
                            cout<<" ";
                        }
                    }
                }
                cout<<'\n';
            }
        */

        /*// pattern 4    half pyramid
            int n;
            cin>>n;
            for(int row=0; row<n; row++){
                for(int col=0; col<row+1; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */
        
        /*// pattern 5    inverted half pyramid
            int n;
            cin>>n;
            for(int row=0; row<n; row++){
                for(int col=0; col<n-row; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */

        /*// pattern 6    half pyramid with numbers
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                for(int j=0; j<i+1; j++){
                    cout<<j+1;
                }
                cout<<'\n';
            }
        */

        /*// pattern 7
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                for(int j=0; j<n-i; j++){
                    cout<<j+1;
                }
                cout<<'\n';
            }
        */

    return 0;
}