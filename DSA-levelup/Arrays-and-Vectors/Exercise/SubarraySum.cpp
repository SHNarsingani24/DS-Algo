// Given an array find the maximum subarray sum from it. 
// Subarray means contiguous segment of array.

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N^2)
int max_subarray_sum(vector<int> arr){
    int n = arr.size();
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        int sum = arr[i];
        maxSum = max(maxSum, sum);
        for(int j=i+1; j<n;j++){
            sum = sum + arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int kadane_algo(vector<int> arr){
    int sum = 0, maxSum = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        sum = sum + arr[i];
        if(sum < 0) sum = 0;
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main(){
    vector<int> arr = {-1, 2, 3, 4, -2, 6, -8, 3};
    cout << kadane_algo(arr);
    return 0;
}