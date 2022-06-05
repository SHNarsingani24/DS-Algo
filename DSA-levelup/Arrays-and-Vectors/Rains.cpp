// You are given an array showing the height of ith building. your task is to find total trapped water between these buildings.
// https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
using namespace std;

int total_water_trapped(vector<int> arr){
    int n = arr.size();

    // corner case: water can't be trapped with 2 or less buildings.
    if(n<=2){
        return 0;
    }

    // left[i] will show max height of building from 0 to i.
    // right[i] will show max height of building from i to n-1.
    vector<int>left(n, 0);
    vector<int>right(n, 0);

    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], arr[i]);
        right[n-1-i] = max(arr[n-1-i], right[n-i]);
    }
    
    // calculating total water trapped.
    int water = 0;
    for(int i=0; i<n; i++){
        water = water + (min(left[i], right[i])-arr[i]);
    }

    return water;
}

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << total_water_trapped(arr);
    return 0;
}