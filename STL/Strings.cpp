#include<iostream>
using namespace std;

int main(){

    /*// str.length();
        string str = "Ujjwal";
        cout << "str.length()->  " << str.length() << "\n\n";
    */

    /*// str.empty();
        string str = "Ujjwal";
        cout << "str.empty()->  " << str.empty() << "\n\n";
    */

    /*// str.push_back('char');
        string str = "Ujjwal";
        str.push_back('@');
        cout << "str->  " << str << "\n\n";
    */

    /*// str.pop_back();
        string str = "Ujjwal";
        str.pop_back();
        cout << "str->  " << str << "\n\n";
    */

    /*// str.substr(starting index, number of elements);
        string str = "Ujjwal";
        cout << "str.substr(1,4)->  " << str.substr(1,4) << "\n";
        cout << "str->  " << str << "\n\n";
    */

    /*// str.compare(str2);         0 if equal      +ve if str[i]>str2[i]   -ve if str[i]<str2[i]
        string str = "Ujjwal";
        string str2 = "Ujjwal2327";

        cout << "str.compare(str2)->  " << str.compare(str2) << '\n';
        cout << "str2.compare(str)->  " << str2.compare(str) << "\n\n";

        str = "Ujjwal2327";
        str2 = "Ujjwal1234";
        cout << "str.compare(str2)->  " << str.compare(str2) << '\n';
        cout << "str2.compare(str)->  " << str2.compare(str) << "\n\n";
    */

    /*// str.find(str2);
        string str = "Hello Jee Kaise Ho Saare";
        string str2 = "Jee";
        cout << "str.find(str2)->  " << str.find(str2) << '\n';

        str2 = "everyone";
        cout << "str.find(str2)->  " << str.find(str2) << "\n\n";
    */

    /*// string::npos;
        string str = "Hello Jee Kaise Ho Saare";
        string str2 = "everyone";
        cout << "string::npos->  " << string::npos << '\n';
        if(str.find(str2) == string::npos)
            cout << "NOT FOUND\n\n";
    */

    /*// str.replace(starting index, number of chars, str2);
        string str = "This is my first message";
        string str2 = "second";
        cout << str.replace(11,5, str2) << '\n';
        cout << "str->  " << str << "\n\n";
    */

    /*// str.erase(starting index, number of chars);
        string str = "This is my first message";
        cout << str.erase(11,5) << '\n';
        cout << "str->  " << str << "\n\n";
    */

    /*// str.insert(strating index, str2);
        string str = "This is my first message";
        string str2 = "very ";
        cout << str.insert(11, str2) << '\n';
        cout << "str->  " << str << "\n\n";
    */

    return 0;
}