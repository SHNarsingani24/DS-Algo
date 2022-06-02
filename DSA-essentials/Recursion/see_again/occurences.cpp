#include<bits/stdc++.h>
using namespace std;

int get_first_occ(int arr[], int n, int key){
	// base cases.
	if(n==0) return -1;
	if(arr[0]==key) return 0;  // goes till key is found.

	// recursion.
	int i = get_first_occ(arr+1, n-1, key);
	if(i==-1){
		return -1;
	}
	return i+1;
}

int get_last_occ(int arr[], int n, int key){
	// base case.
	if(n==0) return -1; 		// goes till whole array is divided.

	// recursion.
	int i = get_last_occ(arr+1, n-1, key);
	if(i == -1){
		if(arr[0]==key){
			return 0;
		} else {
			return -1;
		}
	}

	return i+1;
}

void get_all_occ(vector<int> nums, int key, vector<int> &indices){
	// base case.
	if(nums.size()==0){
		return;
	}

	// recursion.
	get_all_occ(vector<int>(nums.begin()+1, nums.end()), key, indices);
	for(int i = 0; i < indices.size(); i++){
		indices[i]++;
	}
	if(nums[0] == key){
		indices.insert(indices.begin(), 0);
	}

	return;
}

int main(){

	// int arr[] = {2, 3, 5, 6, 2, 4, 6, 3};
	// int n = sizeof(arr)/sizeof(int);

	vector<int> v = {6, 1, 3, 7, 3, 4, 2};
	vector<int> i;
	get_all_occ(v, 3, i);

	for(int j = 0; j < i.size(); j++){
		cout << i[j] << " ";
	}

	// int key;
	// cin >> key;

	// cout << get_first_occ(arr, n, key) << endl;
	// cout << get_last_occ(arr, n, key) << endl;

    return 0;
}