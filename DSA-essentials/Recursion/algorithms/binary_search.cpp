#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v, int l, int r, int x){
	if(l <= r){
		int mid = l + (r - l) / 2;

		if(v[mid] == x) return mid;
		else if(x < v[mid]){
			return binary_search(v, l, mid-1, x);
		} else {
			return binary_search(v, mid+1, r, x);
		}
	}
	return -1; // when element is not present in array.
}

int main(){
    vector<int> v = {1, 4, 7, 9, 14, 19, 24, 36, 48, 51};

    cout << binary_search(v, 0, v.size()-1, 24);
    

    return 0;
}