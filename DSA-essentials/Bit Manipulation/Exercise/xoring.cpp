#include<bits/stdc++.h>
using namespace std;

// Problem: find the only non-repeating number from the array in which all other number repeats twice(or even number of times).
int get_non_repeating_num(vector<int> nums){
	int ans = 0;
	// Time Complexity: O(N).
	// Space Complexity: O(1).
	for(int i = 0; i < nums.size(); i++){
		ans = (ans ^ nums[i]);
	}
	return ans;
}

// Problem: find two non-repeating numbers from the array in which all other number repeats twice(or even number of times).
// Time Complexity: O(N).
// Space Complexity: O(1).
pair<int, int> get_two_non_repeating_nums(vector<int> nums){
	int x = 0; // x - xor of array.
	// calculating xor of whole array.
	for(int i = 0; i < nums.size(); i++){
		x = (x ^ nums[i]);
	}

	// finding the right most set bit.
	int j = 0, mask, temp = x;
	while(true){
		mask = (1<<j);
		if(x&mask){
			break;
		}
		j++;
	}

	// xoring the elements that has set bit at position j.
	for(int i = 0; i < nums.size(); i++){
		if(nums[i]&mask){
			x = (x ^ nums[i]);
		}
	}

	return {x, (x^temp)};
}


// Problem: find the non repeating element from the array in which all other number repeats thrice(or odd number of times).
// Time Complexity: O(N).
// Space Complexity: O(1). -- bitstring array is of constant size.
int get_unique_num(vector<int>nums){
	int temp, mask, j;
	vector<int>bitstring(32, 0);
	for(int i = 0; i < nums.size(); i++){
		temp = nums[i], j = 0;
		while(temp){
			if(temp&1){
				bitstring[j]++;
			}
			j++;
			temp = temp >> 1;
		}
	}

	int p = 1, ans = 0;
	for(int i = 0; i < bitstring.size(); i++){
		if(bitstring[i]%3){
			ans += p;
		}
		p = p*2;
	}

	return ans;
}

int main(){
    
	vector<int> v = {1, 2, 9, 1, 2, 1, 2, 4, 9, 9};

	// cout << get_non_repeating_num(v) << endl;

	// pair<int, int> p = get_two_non_repeating_nums(v);
	// cout << "(" << p.first << ", " << p.second << ")." << endl;

	cout << get_unique_num(v) << endl;
    return 0;
}