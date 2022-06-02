#include<bits/stdc++.h>
using namespace std;

// problem: given N tiles of size 1xM, find the total possible ways to fit these tiles in NxM board. 

int get_possible_ways(int n, int m){
	if(n < m) return 1;  // when one length is less than height, we can't place any tile horizontally. Only vertical pllacement possible.
	return get_possible_ways(n-m, m) + get_possible_ways(n-1, m);
	// n-m means m tiles of size 1xm are horizontally placed in the grid.
	// n-1 means 1 tile of size 1xm are vertically placed in the grid.
}

int main(){
	int n, m;
	cin >> n >> m;

	cout << get_possible_ways(n, m);
   
    return 0;
}