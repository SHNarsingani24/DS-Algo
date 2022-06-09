// Given an array of integers and a target, 
// find a pair of distinct integers from that array that adds upto given target.

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// brute force approach.
// Time Complexity: O(N^2).
pair<int, int> brute_force(vector<int> arr, int target){
    for(int i=0; i<arr.size()-1; i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j]==target){
                return {arr[i], arr[j]};
            }
        }
    }

    // if there doesn't exist a solution.
    return {};
}

// Optimized approach compared to previous one.
// Time Complexity: O(NlogN).
pair<int, int> pairs(vector<int> arr, int target){
    // O(NlogN)
    sort(arr.begin(), arr.end());
    int i=0, j=arr.size()-1;
    // O(N)
    while(i < j){
        if(arr[i]+arr[j] > target){
            j--;
        } else if(arr[i]+arr[j] < target){
            i++;
        } else {
            return {arr[i], arr[j]};
        }
    }

    // if there doesn't exist a solution.
    return {};
}

// Most Optimized approach compared to previous one.
// Time Complexity: O(N).
pair<int, int> pairs_optimized(vector<int> arr, int target){
    unordered_set<int> s;   // as order doesn't matter here.
    for(int x: arr){
        if(s.find(target-x) != s.end()){    // this find function will take O(1) time as set uses hashmap.
            return {target-x, x};
        }
        s.insert(x);
    }

    // if there doesn't exist a solution.
    return {};
}

int main(){
    vector<int> arr = {10, 2, 4, -6, 5, 9 , 1};
    int target = 4;

    pair<int, int> p = pairs_optimized(arr, target);

    cout << p.first << " + " << p.second << " = " << target;
    return 0;
}