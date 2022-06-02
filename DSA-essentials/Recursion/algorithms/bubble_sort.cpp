#include<bits/stdc++.h>
using namespace std;

// Iterative Version.
// Time Complexity: O(N^2).
// Space Complexity: O(1).
void bubble_sort(int arr[], int n){
	for(int i =0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	return;
}

// Recursive Version.
// Time Complexity: O(N^2).
// Space Complexity: O(N).
void bubble_sort(int arr[], int n, int j){   // j is the pointer, which points at arr[0] initially.
	// base condition.
	if(n==1) return;

	// recursion.
	// when pointer is reached to the end of arr, which means one iteration is over.
	if(j == n-1){
		bubble_sort(arr, n-1, 0);		// reducing the size of arr by 1 (as last element is now sorted).
		return;
	}
	// if greater number is before smaller one.
	if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
	// moving j forward...
	bubble_sort(arr, n, j+1);		
}

int main(){

	int arr[] = {24, 7, 4, 31, 49, -21, 11, 13};
	int n = sizeof(arr)/sizeof(int);

	bubble_sort(arr, n, 0);

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

    return 0;
}