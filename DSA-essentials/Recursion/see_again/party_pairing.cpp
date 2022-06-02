#include<bits/stdc++.h>
using namespace std;

// problem: given a number n, we need to return number of possible ways in which n can be paired.
// paired - n can be single or double not more than it.
// for example: if n = 3. ans: 
// 1, 2, 3 (all singles)
// 1, (2, 3)
// (1, 2), 3
// (1, 3), 2
// total possible ways: 4


int get_total_ways(int n){
	if(n < 0) return 0;
	if(n < 3) return n; // if n = 2, then only 2 ways possible, for n = 1 only one way possible.

	return get_total_ways(n-1) /*if one goes single*/ + (n-1) * get_total_ways(n-2)/*if one pairs up*/;
}

int main(){
        
   	int n;
   	cin >> n;

   	cout << get_total_ways(n) ;

    return 0;
}