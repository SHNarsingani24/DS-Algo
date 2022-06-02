#include<bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int n){
	int s = 0, e = n-1;
	// Loop runs for n/2 times.
	// Time Complexity: O(n) - ignoring the constants.
	// Space Complexity: O(1)
	while ( s < e ){
		swap(arr[s], arr[e]);  // Swapping two elements of array using in-built function.
		s++, e--;
	}
	return;
}

int main(){
    
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr)/sizeof(int);

    // Printing array as it is.
    for(int i = 0; i < n; i++){
    	cout << arr[i] << " " ; 
    }
    cout << endl;

    reverse_array(arr, n);

    // Printing reversed array.
    for(int i = 0; i < n; i++){
    	cout << arr[i] << " " ; 
    }
    cout << endl;

    return 0;
}