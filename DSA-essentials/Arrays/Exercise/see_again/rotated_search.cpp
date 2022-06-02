#include<bits/stdc++.h>
using namespace std;

// given a rotated sorted array, implement the binary search for the same.
// {4, 5, 6, 7, 0, 1, 2, 3} is rotated by factor 4.
// consider {4, 5, 6, 7} as one part and remaining as another.

int rotated_search(vector<int> v, int key){
	int s = 0, e = v.size()-1;
	while(s <= e){
		int mid = s+(e-s)/2;

		if(v[mid] == key) return mid;

		if(v[mid] >= v[s]){			// checking if mid and s are on the same part.
			if(key >= v[s] and key < v[mid])	// if key is on the same part as s and mid.
				e = mid - 1;
			else								// if key is on the different part.
				s = mid + 1;
		} else {
			if(key > v[mid] and key <= v[e])	// if mid and s are on different parts, but the key is on the same part as mid.
				s = mid + 1;
			else								// if key is on the same part as s.
				e = mid - 1;
		}
	}
	return -1;	// if key not found.
}

int main(){
        
    vector<int> v = {4, 5, 6, 7, 0, 1, 2, 3};
    int key;
    cin >> key;

    cout << rotated_search(v, key);

    return 0;
}