#include<iostream>
using namespace std;

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

int main(){

    int marks;
    cin>>marks;
    char result = getGrade(marks);
    cout << result << '\n';
    
    char result2 = getGrade2(marks);
    cout << result2 << '\n';

    return 0;
}

/*INPUTS
70
*/