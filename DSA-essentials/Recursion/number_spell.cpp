#include<bits/stdc++.h>
using namespace std;

// print the spell for given number.
// e.g., 2411 - two four one one.

// Global array.
string spells[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void num_spell(int n){
	// base case.
	if(n==0) return;

	// recursive case.
	int last_dig = n%10;
	num_spell(n/10);
	cout << spells[last_dig] << " ";
}

int main(){
        
    int n;
    cin >> n;

    num_spell(n);

    return 0;
}