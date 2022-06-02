#include<iostream>
#include<vector>
using namespace std;

// recursive knapsack function.
int knapsackRec(vector<int> wts, vector<int> prices, int N, int W){
	// base case - when bag is full or no item is remaining.
	if(N==0 or W==0){
		return 0;
	}

	// will move in two paths, 1) include item  2) exclude item. 
	int inc=0, exc=0;
	// weight of current item should be less than remaining capacity of the bag.
	if(W >= wts[N-1]){
		// including item.
		inc = prices[N-1] + knapsackRec(wts, prices, N-1, W-wts[N-1]);
	}
	// excluding item.
	exc = knapsackRec(wts, prices, N-1, W);

	// will return max of both paths.
	return max(exc, inc);
}

// Bottom up dynamic approach to solve knapsack problem.
// Time complexity: O(NW)
// Space Complexity: O(NW)
int knapsack(vector<int> wts, vector<int> prices, int N, int W){
	// dynamic grid, in which will store what will be max_profit for item i(considering bothe inclusion and exclusion) for weight limit j.
	vector<vector<int>> grid(N+1, vector<int>(W+1, 0));		// note that 0th row(0 weight) and 0th column(0 items) will be 0(no profit).
	// traversing through grid and updating value for each cell.
	for(int i=1; i <= N; i++){
		for(int j=1; j<=W; j++){
			int inc=0, exc=0;
			// inclusion.
			if(j >= wts[i-1]){
				inc = prices[i-1] + grid[i-1][j-wts[i-1]];
			}
			// exclusion.
			exc = grid[i-1][j];
			// will store the max profit!
			grid[i][j] = max(inc, exc);
		}
	}
	// returning final answer.
	return grid[N][W];
}

// Space Complexity Optimization.
// Time Coplexity: O(NW).
// Space Complexity: O(W).
int knapsack_opt(vector<int> wts, vector<int> prices, int N, int W){
	vector<int>curr_item(W+1, 0);
	vector<int>next_item(W+1, 0);
	for(int i=1; i <= N; i++){
		for(int j=1; j<=W; j++){
			int inc=0, exc=0;
			// inclusion.
			if(j >= wts[i-1]){
				inc = prices[i-1] + curr_item[j-wts[i-1]];
			}
			// exclusion.
			exc = curr_item[j];
			// will store the max profit!
			next_item[j] = max(inc, exc);
		}
		curr_item = next_item; 
	}
	return curr_item[W];
}
int main(){
	vector<int> wts = {2, 7, 3, 4};
	vector<int> prices = {5, 20, 20, 10};

	int N = 4;
	int W = 11;

	cout << "Max Profit: " << knapsackRec(wts, prices, N, W) << endl;
	cout << "Max Profit: " << knapsack_opt(wts, prices, N, W);
	return 0;
}