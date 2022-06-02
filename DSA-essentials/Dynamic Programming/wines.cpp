// Problem: You are given an array containing prices of wine bottel, in year y bottle will have y*price. Each year you can only sell
// one bottel that to from corners (rightmost or leftmost). Find maximum possible profit.
// e.g., {2, 3, 5, 1, 4} will have max profit of 50(1*2 + 2*4 + 3*1 + 4*3 + 5*5 --- year*price).

#include<iostream>
#include<vector>
using namespace std;

// top down dynamic programming approach.
int wines(vector<vector<int>>&grid, vector<int> prices, int L, int R, int y){
	// base case.
	if(L>R){
		return 0;
	}

	// if solution already exists.
	if(grid[L][R]!=0){
		return grid[L][R];
	}

	// profit by selling leftmost bottle.
	int pick_left = y*prices[L] + wines(grid, prices, L+1, R, y+1);
	// profit by selling rightmost bottle.
	int pick_right = y*prices[R] + wines(grid, prices, L, R-1, y+1);

	// storing max profit in dynamic grid.
	grid[L][R] = max(pick_left, pick_right);

	return grid[L][R];
}

// bottom down dynamic programming approach.
int wines_bottom_up(vector<int>prices){
	int n = prices.size();
	// dynamic grid to store solutions.
	vector<vector<int>>grid(n, vector<int>(n, 0));
	// iterating grid, at the end we will have our solution at top-right corner.
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<n; j++){
			// on the diagonal we are considering that only one bottle is left to sell, which will be sold in Nth year.
			if(i==j){
				grid[i][j] = n*prices[i];
			}

			// else there are more than 1 bottle.
			if(i < j){
				// find current year, total bottles - current bottles.
				int y = n - (j-i);
				// sell the left-most now and remainings will be sold in upcoming years.
				int pick_left = y*prices[i] + grid[i+1][j];
				// sell the right-most now and remainings will be sold in upcoming years.
				int pick_right = y*prices[j] + grid[i][j-1];
				// store max of both.
				grid[i][j] = max(pick_left, pick_right);
			}
		}
	}

	return grid[0][n-1];
}

int main(){
	vector<int> prices = {2, 3, 5, 1, 4};
	int n = prices.size();
	vector<vector<int>>grid(n, vector<int>(n, 0));

	cout << wines_bottom_up(prices);
	return 0;
}
