// Problem: Given an array, find mimimum absolute difference possible of sum of two subsets of the array.
// e.g., for array {1, 6, 5, 11} answer will be 1 (for subsets {11} and {1, 6, 5} diffeence is (12-11=1))

#include<iostream>
#include<vector>
using namespace std;

int getMinDiff(vector<int>nums){
	int sum=0, n=nums.size();
	// finding total sum of array.
	for(int num: nums){
		sum = sum + num;
	}

	// grid[i][j] will be true if sum j is possible using any elements till (i-1)th index of array.
	vector<vector<bool>>grid(n+1, vector<bool>(sum+1, false));

	for(int i=0; i<=n; i++){
		for(int j=0; j<=sum; j++){
			if(j==0) grid[i][j]=true;
			else if(i==0) grid[i][j]=false;
			else if(nums[i-1]>j) grid[i][j] = grid[i-1][j];
			else grid[i][j] = grid[i-1][j] || grid[i][j-nums[i-1]];
		}
	}

	// suppose subset 1 has sum, sum1 and subset 2 has sum sum2.
	// here lets assume that sum1 <= sum2 hence we can say sum1 <= (sum-sum1)
	// which means 2sum1 <= sum and sum1 <= sum/2.
	// hence we will search for sum1 in range of 0 to sum/2.
	int diff = INT_MAX;
	for(int i=0;i<=sum/2;i++){
		int sum1=i; 
		int sum2=sum-sum1;
		// find minimum sum possible.
		if(grid[n][i]) diff = min(diff, abs(sum2-sum1));
	}
	
	return diff;
}

int main(){
	vector<int>nums = {1, 6, 5, 11};
	cout << getMinDiff(nums);
	return 0;
}