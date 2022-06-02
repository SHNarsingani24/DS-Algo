#include<iostream>
#include<vector>
using namespace std;

// top down dynamic programming approach.
int getChangeCombinations(int rem, int n, vector<int> coins, vector<vector<int>> &combinations){
	// when we found one combination.
	if(rem==0){
		return 1;
	}

	// if we ran out of any bound.
	if(rem < 0 || n < 0) return 0;

	// dynamic grid will show using coins till nth index, in how many ways remaining amount can be made.
	if(combinations[rem][n]!=0){
		return combinations[rem][n];
	}
	
	// take coin or don't take it.
	int take = getChangeCombinations(rem-coins[n], n, coins, combinations);
	int dont = getChangeCombinations(rem, n-1, coins, combinations);
	return combinations[rem][n] = take + dont;
}

/// bottom-up dynamic approach.
int getCombinations(int m, vector<int>coins){
	int n = coins.size();
	// this vector will store number of combinations possible for each value from 0 to m.
	vector<int> combinations(m+1, 0);
	// combination of 0 is always possible, don't take any coin.
	combinations[0] = 1;

	// for each coin we will find combination possible for each 0 to m value.
	// as we are taking coin one by one this will give us combinations and not permutations.
	for(int coin: coins){
		for(int i=0; i<=m; i++){
			if(i-coin >= 0){
				combinations[i] += combinations[i-coin];
			}
		}
	}

	return combinations[m];
}

int main(){
	vector<int> coins = {4, 1, 2, 3};
	int n = coins.size();
	vector<vector<int>> combinations(n+1, vector<int>(n, 0));
	cout << getChangeCombinations(n, n-1, coins, combinations) << endl;
	cout << getCombinations(8, coins);
	return 0;
}
