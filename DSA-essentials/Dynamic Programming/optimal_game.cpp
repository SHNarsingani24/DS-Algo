// Problem: Optimal Game Stratergy, there is a two player game, played between you and opponent.
// alternative turns. Array of coins, only 1st or last coin can be selected in a turn.
// find maximum amount you can collect if you have 1st turn.

#include<iostream>
#include<vector>
using namespace std;

int getMaxCoins(vector<int> val){
	int n = val.size();
	// grid[i][j] -- represents max coins collected by you from ith to jth coin.
	vector<vector<int>> grid (n, vector<int>(n, 0));
	// this loop will run only for elements above the diagonal of the grid.
	for(int gap = 0; gap<n; gap++){
		for(int i=0, j=gap; j<n; i++, j++){
			// there will be three unique moves that opponent can take.		
			int x = ((i+2) <= j) ? grid[i+2][j] : 0;
			int y = ((i+1) <= (j-1)) ? grid[i+1][j-1] : 0;
			int z = (i <= (j-2)) ? grid[i][j-2] : 0;
			grid[i][j] = max(			// we will select maximum amount possible.
				val[i] + min(x, y),		// opponent will move in a way that we get minimum amount in next turn.
				val[j] + min(y, z)
			);
		}
	}
	return grid[0][n-1];
}

int main(){
	vector<int> val = {20, 30, 2, 10};
	cout << getMaxCoins(val);
	return 0;
}
