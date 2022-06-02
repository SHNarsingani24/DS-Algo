#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int key){

	int s = 0, e = n-1;
	while( s <= e ){
		int mid = (s+e)/2;
		if(arr[mid] == key){
			return mid;
		} else if(arr[mid] > key) {
			e = mid-1;
		} else{
			s = mid + 1;
		}
	}

	// if element not found in the search.
	return -1; 
}

int main(){
	int arr[100];
	int n;
	
	cout << "Enter the size of array: ";
	cin >> n;

	cout << "Enter the sorted array of size " << n << "." << endl;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int key;
	cout << "Enter the key element: ";
	cin >> key;

	int index = binary_search(arr, n, key);
	if(index != -1){
		cout << "The key element is present at " << binary_search(arr, n, key) << " index." << endl;
	} else {
		cout << "Key not found" << endl;
	}
	
    return 0;
}
