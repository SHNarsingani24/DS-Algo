#include<bits/stdc++.h>
using namespace std;

// problem: given a mxn grid find the number of ways in which one can reach to the right most bottom corner from the left most top corner.
// one can only move downwards or in right direction.

// time complexity: O(2^(m+n)).
int grid_ways(int i, int j, int m, int n){
	// if the target cell is reached.
	if(i == m-1 and j == n-1){
		return 1;
	}
	// if either of boundary is crossed.
	if(i >= m or j >= n){
		return 0;
	}

	return grid_ways(i+1, j, m, n) /* moving in right */ + grid_ways(i, j+1, m, n) /* moving downwards */;
}


// basically we need to move m-1 times right and n-1 times down, which is RRRR....DDDD..... Now to find the combinations of these we can use formula:
// (m-1 + n-1)!/ (m-1)!(n-1)! -- the denominator comes from the number of times particular element repeats.
// time complexity: O(m+n).
int get_fact(int x){
	int ans = 1;
	for(int i = 2; i <= x; i++){
		ans = ans * i;
	}
	return ans;
}
int get_ways(int m, int n){
	return get_fact(m+n-2)/(get_fact(m-1) * get_fact(n-1));
}

int main(){
    
    int m, n;
    cin >> m >> n;
    cout << "Ways: " << grid_ways(0, 0, m, n) << endl;
    cout << "ways: " << get_ways(m, n) << endl;
    return 0;
}