#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// TC-O(n)    SC-O(1) at max q has 27 chars
string firstNonRepeating(string &stream){
    int n = stream.size();
    string ans;
    vector<int>cnts(26,0);
    queue<char>q;

    for(int i=0; i<n; i++){
        char ch = stream[i];
        q.push(ch);
        cnts[ch-'a']++;
        
        while(!q.empty() && cnts[q.front()-'a'] > 1)
            q.pop();

        if(q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
    }
    return ans;
}

int main(){

    /*// first non repeating character in a stream
        string s = "zarcaazrd";
        string ans = firstNonRepeating(s);
        cout << ans << '\n';
    */

    /*
    */
    // circular tour / gas station (VVImp)
        

    /*
    */
    // 

    /*
    */
    // 

    /*
    */
    // 

    /*
    */
    // 

    /*
    */
    // 

    return 0;
}