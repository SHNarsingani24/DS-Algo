// You are given two arrays, you need to find a pair of ints 
// such that the absolute difference of this pair is closest to 0.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

// Time Complexity: O(N^2)
// Brute Force Approach
pair<int, int> get_min_diff_bf(vector<int> arr1, vector<int>arr2){
    int n=arr1.size(), m=arr2.size();
    int diff = INT_MAX, p1, p2;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(abs(arr1[i]-arr2[j]) < diff){
                diff = abs(arr1[i]-arr2[j]);
                p1 = arr1[i], p2=arr2[j];
            }
        }
    }
    return {p1, p2};
}
// Time Complexity: O((N+M)LogM)
pair<int, int> get_min_diff(vector<int> arr1, vector<int>arr2){
    // O(MLogM)
    sort(arr2.begin(), arr2.end());

    int diff=INT_MAX, p1, p2;

    // O(NlogM)
    for(int i: arr1){
        // will find index of element that is just bigger than i.
        // takes O(logM) time
        auto lb = lower_bound(arr2.begin(), arr2.end(), i) - arr2.begin();

        // using element just smaller than i.
        if(lb>0 and i-arr2[lb-1]<diff){
            diff = i - arr2[lb-1];
            p1 = i, p2 = arr2[lb-1];
        }

        // using element just larger than or equal to i.
        if(lb!=arr2.size() and arr2[lb]-i<diff){
            diff = arr2[lb]-i;
            p1 = i, p2 = arr2[lb];
        }
    }

    return {p1, p2};
}

int main(){
    vector<int> arr1 = {23, 5, 10, 17, 30};
    vector<int> arr2 = {26, 134, 135, 14, 19};
    pair<int, int> p = get_min_diff_bf(arr1, arr2);
    cout << p.first << " " << p.second;
    return 0;
}