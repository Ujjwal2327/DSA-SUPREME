// https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/

#include<iostream>
#include<vector>
using namespace std;

int inplaceMerge(vector<int>&arr, int s, int e){
    int mid = s + (e-s)/2;

    int i = s;
    int j = mid+1;
    int ans = 0;

    if(arr[j]>=arr[mid])
        return 0;

    while(i<=e && j<=e && i!=j){
        if(arr[i]<=arr[j]){
            i++;
        }
        else{
            int temp = arr[j];
            int k = j;
            while(k>i){
                arr[k] = arr[k-1];
                k--;
                ans++;
            }
            arr[i] = temp;
            i++;
            j++;
        }
    }

    return ans;
}

int inversionCount(vector<int>&arr, int s, int e){
    if(s>=e)
        return 0;
    
    int mid = s + (e-s)/2;
    int ans1 = inversionCount(arr, s, mid);
    int ans2 = inversionCount(arr, mid+1, e);

    int ans3 = inplaceMerge(arr, s, e);

    return ans1 + ans2 + ans3;
}

int merge(vector<int>&arr, int s, int e){
    int mid = s + (e-s)/2;
    int ans = 0;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int>left(len1);
    vector<int>right(len2);

    int i=0, j=0, k=s;
    for(; i<len1; i++)
        left[i] = arr[k++];
    
    for(; j<len2; j++)
        right[j] = arr[k++];

    i=0, j=0, k=s;

    while(i<len1 && j<len2){
        if(left[i]<=right[j])
            arr[k++] = left[i++];
        else{
            arr[k++] = right[j++];
            ans += len1-i;      // only remaining left subarray elements are greater than arr[j] that are need to be place after arr[j]
        }
    }

    while(i<len1)
        arr[k++] = left[i++];
    
    while(j<len2)
        arr[k++] = right[j++];
    
    return ans;
}

int inversionCount2(vector<int>&arr, int s, int e){
    if(s>=e)
        return 0;
    
    int mid = s + (e-s)/2;
    int ans1 = inversionCount(arr, s, mid);
    int ans2 = inversionCount(arr, mid+1, e);

    int ans3 = merge(arr, s, e);

    return ans1 + ans2 + ans3;
}

int main(){

    vector<int>arr{2,4,1,3,5};
    int s = 0, e = arr.size()-1;
    int ans = inversionCount(arr, s, e);
    cout << ans << '\n';

    vector<int>arr2{2,4,1,3,5};
    int s2 = 0, e2 = arr2.size()-1;
    int ans2 = inversionCount2(arr2, s2, e2);
    cout << ans2 << '\n';

    return 0;
}