// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

#include<iostream>
#include<vector>
using namespace std;

// TC-O(n)    SC-O(1)
int totalSum(vector<int>arr){
    int n = arr.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += arr[i];
    }

    return ans;
}

// TC-O(n)    SC-O(1)
bool possibleAns(vector<int>arr, int num, int maxi){
    int n = arr.size();

    int i=0;
    while(i<n && num--){
        int curr = 0;
        while(i<n && curr+arr[i] <= maxi){
            curr += arr[i];
            i++;
        }
    }

    if(i==n && num>=0)      // num>0 if maxi is larger than needed due to which some students left without getting book
        return true;
    else
        return false;
}

// TC-O(nlogn)    SC-O(1)
int boolAllocation(vector<int>arr, int num){
    int n = arr.size();
    
    if(num>n)
        return -1;

    int s = 0;
    int e = totalSum(arr);

    int ans = 0;
    while(s<=e){
        // mid refers to maximum number of pages i can allocate (assumed ans)
        int mid = s + (e-s)/2;

        if(possibleAns(arr, num, mid)){
            ans = mid;
            e = mid - 1;        // to minimize the ans
        }
        else
            s = mid + 1;        // if mid is not a possible ans, pages lesser than mid cant too
    }

    return ans;
}

// TC-O(nlogn)    SC-O(1)
int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int students;
    cin>>students;
    int ans = boolAllocation(arr, students);
    cout<<ans<<'\n';
    return 0;
}

/*INPUTS
4
12 34 67 90
2
*/