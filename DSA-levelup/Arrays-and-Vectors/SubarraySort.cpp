// given an array return indices of a subarray sorting which will sort the whole array.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// Time Complexity: O(NlogN).
pair<int, int> subarray_sort(vector<int> arr){
    vector<int> b(arr);
    // O(NlogN)
    sort(b.begin(), b.end());
    int i=0, j=arr.size()-1;

    // O(N)
    while(i<arr.size() and arr[i]==b[i]){
        i++;
    }
    
    // O(N)
    while(j>=0 and arr[j]==b[j]){
        j--;
    }

    // checking if array is already sorted or not.
    if(i==arr.size()){
        return {-1, -1};
    } else {
        return {i, j};
    }
}

// Time Complexity: O(N) --- Optimized.
pair<int, int> subarray_sort_opt(vector<int> arr){
    int n = arr.size();
    
    // Find the Smallest elemenet and Largest element that are out of order.
    int smallest=INT_MAX, largest=INT_MIN;
    // corner case: first element can be only compared with second element.
    if(arr[1]<arr[0]){
        if(arr[0] < smallest) smallest = arr[0];
        if(arr[0] > largest) largest = arr[0];
    }
    // corner case: last element can be only compared with second last element.
    if(arr[n-1]<arr[n-2]){
        if(arr[n-1] < smallest) smallest = arr[n-1];
        if(arr[n-1] > largest) largest = arr[n-1];
    }
    // checking remaining elements.
    for(int i=1; i<n-1; i++){
        if(arr[i]<arr[i-1] or arr[i]>arr[i+1]){
            if(arr[i] < smallest) smallest = arr[i];
            if(arr[i] > largest) largest = arr[i];
        }
    }

    // if no smallest out of order element found, which means array is already sorted.
    if(smallest==INT_MAX){
        return {-1, -1};
    }

    // finding right position of smallest out of order element.
    int left=0;
    while(smallest > arr[left]){
        left++;
    }

    // finding right position of largest out of order element.
    int right = n-1;
    while(largest < arr[right]){
        right--;
    }

    return {left, right};
}

int main(){
    vector<int> arr = {6, 2, 3, 4, 5, 8, 1, 7, 9, 10, 11};
    pair<int, int> p = subarray_sort_opt(arr);
    cout << p.first << " " << p.second;
    return 0;
}

