#include<bits/stdc++.h>
using namespace std;

// Problem: find the largest subarray sum from given array.

// Brute Force Algorithm.
// Time Complexity: O(n^3).
int largest_sum(int arr[], int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int curr_subarr_sum = 0;
			for(int k = i; k < j; k++){
				curr_subarr_sum += arr[k];
			}
			
			if(curr_subarr_sum > ans){
				ans = curr_subarr_sum;
			}
		}
	}
	return ans;
}

// Prefix sum Approach (optimized).
// Time Complexity: O(n^2).
int prefix_sum(int arr[], int n){
	int ans = 0;

	int ps[n] = {0};
	ps[0] = arr[0];
	// Calculating the prefix sum array.
	for(int i = 1; i < n; i++){
		ps[i] = ps[i-1] + arr[i];
	}

	// Finding the largest sum.
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int curr_subarr_sum = 0;
			if(i>0){
				curr_subarr_sum = ps[j] - ps[i-1];
			} else {
				curr_subarr_sum = ps[j];
			}

			if(curr_subarr_sum > ans){
				ans = curr_subarr_sum;
			}
		}
	}
	return ans;
}

// Kadane's algorithm (most optimized).
// Time Complexity: O(N).
// Space Complexity: O(1).
// If all elements are negative then this algo will give us 0 only in all cases.
int kadanes_algo(int arr[], int n){
	int current_sum = 0, ans = 0;
	for (int i = 0; i < n; i++){
		current_sum += arr[i];
		if(current_sum < 0){
			current_sum = 0;
		} else if(current_sum > ans){
			ans = current_sum;
		}
	}
	return ans;
}

int main(){
    int arr[] = {1, -1, -2, 3, 5, 7, -10, 9};
    int n = sizeof(arr)/sizeof(int);

    cout << "Largest Sum of a subarray(using brute force algo) in given array is: " << largest_sum(arr, n) << endl;
    cout << "Largest Sum of a subarray(using prefix sum approach) in given array is: " << prefix_sum(arr, n) << endl;
    cout << "Largest Sum of a subarray(using kadane's algo) in given array is: " << kadanes_algo(arr, n);
    
    return 0;
}