#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(N).
// Space Complexity: O(N).
int power(int a, int i){
	// base condition.
	if(i == 0) return 1;
	// recursion.
	return a*power(a, i-1);
}

// Time Complexity: O(log N).
// Space Complexity: O(log N).
// Using bitwise operators, we can implement same function in O(log N) time and O(1) space.
int power_opt(int a, int i){  // opt - optimized.
	// base condition.
	if(i == 0) return 1;

	// recursion.
	int sub_a = power_opt(a, i/2);
	if(i&1) return sub_a * sub_a * a;  // when the power is odd.
	return sub_a * sub_a;  // even power. 
}

int main(){
    int a, i;
    cin >> a >> i;
   	cout << power(a, i) << endl;
   	cout << power_opt(a, i) << endl;

    return 0;
}