#include<iostream>
using namespace std;

// function declaration and definition
void printName(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cout << "Babbar" << '\n';
    }
}

void printNumber(int n){
    cout << n << '\n';
    n++;
    cout << n << '\n';
}

// function declaration
int add(int a, int b);

int findMax(int num1, int num2, int num3){
    if(num1 >= num2 && num1 >= num3)
        return num1;
    if(num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

void printCounting(int n){
    for(int i=1; i<=n; i++){
        cout<<i<<' ';
    }
}

char getGrade(int marks){
    if(marks>=90)
        return 'A';
    else if(marks>=80)
        return 'B';
    else if(marks>=70)
        return 'C';
    else if(marks>=60)
        return 'D';
    else
        return 'F';
}

char getGrade2(int marks){
    switch(marks/10){
        case (10):
            return 'A';
        case (9):
            return 'A';
        case (8):
            return 'B';
        case (7):
            return 'C';
        case(6):
            return 'D';
        default:
            return 'F';
    }
}

int getSum(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}

int getEvenSum(int n){
    int sum = 0;
    for(int i=2; i<=n; i+=2){
        sum += i;
    }
    return sum;
}

int main(){

    /*// printing Babbar n times
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cout << "Babbar" << '\n';
        }
    */
    
    /*// funtion call
        printName();
    */
    
    /*// pass by value concept
        int a = 5;
        printNumber(a);
        cout << a << '\n';
    */

    /*// declaration and definition
    // add 2 numbers
        int a;
        cin>>a;
        int b;
        cin>>b;

        int sum = add(a, b);
        cout << sum << '\n';
    */

    /*// maximum number from 3 numbers
        int a, b, c;
        cin >> a >> b >> c;
        int maxNumber = findMax(a,b,c);
        cout << maxNumber << '\n';
    */

    /*// counting from 1 to n
        int n;
        cin>>n;
        printCounting(n);
    */

    /*// function of student and grade problem
        int marks;
        cin>>marks;
        char result = getGrade(marks);
        cout << result << '\n';
        
        char result2 = getGrade2(marks);
        cout << result2 << '\n';
    */
    
    /*// sum of all numbers upto n
        int n;
        cin >> n;
        int ans = getSum(n);
        cout << ans;
    */

    /*// sum of even numbers upto n
        int n;
        cin >> n;
        int ans = getEvenSum(n);
        cout << ans;
    */
    
    return 0;
}

// function definition
int add(int a, int b){
    int result = a + b;
    return result;
}