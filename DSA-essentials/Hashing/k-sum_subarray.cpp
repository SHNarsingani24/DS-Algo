// Problem: Given an array and integer K, find a maximum lenght of subarray whose sum is K
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// will return maximum subarray -- O(N).
int getKSumSubArray(vector<int> array, int k){
	// map that will store prefix sum(key) and index till which sum is done(value).
	unordered_map<int, int> prefix;
	int sum = 0, len = 0;
	for(int i = 0; i < array.size(); i++){
		sum = sum + array[i];
		// if prefix sum is equal to K, then we will take maximum of current length and length till i.
		if(sum==k){
			len = max(len, i+1);
		} else if(prefix.find(sum-k)!=prefix.end()){	// if current sum - k already exist in map, 
			len = max(len, i - prefix[sum-k]);			// then sum of elements between value of map[sum-k] to i will be K
		}												// hence, we will concider this length to get maximum length.

		prefix[sum] = i;	// storing prefix sum and index in the map.
	}
	return len;
}

int main(){
	vector<int> v = {0, -2, 1, 2, 3, 4, 5, 15, 10, 5};
	int k = 15;
	cout << getKSumSubArray(v, k) << endl;
	return 0;
}