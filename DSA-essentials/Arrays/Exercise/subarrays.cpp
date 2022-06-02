#include<bits/stdc++.h>
using namespace std;

// Problem: print all unique subarrays from given array.

void print_all_subarrays(int arr[], int n){
	// Time Complexity: O(n^3).
	// Space Complexity: O(1).
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			cout << "[ " ;
			for(int k = i; k < j; k++){
				cout << arr[k] << ", " ;
			}
			cout << arr[j] << " ]" << endl;
		}
	}
	return;
}

int main(){
    
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr)/sizeof(int);

    print_all_subarrays(arr, n);

    return 0;
}