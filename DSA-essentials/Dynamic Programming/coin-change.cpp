#include<iostream>
#include<vector>
using namespace std;

// Bottom up dynamic programming approach to find minimum number of coins for change of given number m.
int get_change(int m, vector<int> coins, vector<int> &change){
	// base case.
	if(m==0){
		return 0;
	}

	// if solution already exists.
	if(change[m]!=INT_MAX){
		return change[m];
	}

	// take each coin(if possible) for given value of and make recursive call on m-coin.
	for(int coin: coins){
		if(m-coin >= 0){
			change[m] = min(change[m], get_change(m-coin, coins, change) + 1);
		}
	}

	// if change of m is not possible, INT_MAX will be return as change vector is initialized with INT_MAX.
	return change[m];
}

// Bottom up dynamic programming approach to find minimum number of coins for change of given number m.
int getChange(int m, vector<int> coins){
	// vector to store solutions.
	vector<int> change(m+1, 0);

	// Iterating through 1 to m and will ad solution for possible ones.
	// e.g., coins - [5, 7], m=7, here change for some positions like 1 to 4 and 6, is not possible
	for(int i = 1; i <= m; i++){
		change[i] = INT_MAX;	// store max value initially.
		for(int coin: coins){	// use each coin for current position and find the minimum solution for the same.
			if(i-coin >= 0 and change[i-coin]!=INT_MAX){
				change[i] = min(change[i], change[i-coin]+1);
			}
		}
	}
	// if change is not possible return -1.
	return (change[m]!=INT_MAX)?change[m]:-1;
}

int main(){
	vector<int> coins = {1, 3, 7, 10};
	int m;
	cin >> m;
	vector<int> change(m+1, INT_MAX);
	cout << get_change(m, coins, change) << endl;
	return 0;
}
