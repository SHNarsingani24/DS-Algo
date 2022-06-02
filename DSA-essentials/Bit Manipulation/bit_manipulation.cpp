#include<bits/stdc++.h>
using namespace std;

// tells if a number is odd or even.
void odd_or_even(int n){
	// mask: 1 (00000001).
	if(n&1){
		cout << n << " is an odd number." << endl;
	} else {
		cout << n << " is an even number." << endl;
	}
	return;
}

// will tell value of ith bit(0 or 1).
void get_ith_bit(int n, int i){
	int mask = (1 << i);  // will only have 1 at ith position.
	if((n&mask) > 0){
		cout << "bit at position " << i << " is 1." << endl;
	} else {
		cout << "bit at position " << i << " is 0." << endl;
	}
	return;
}

void clear_ith_bit(int &n, int i){
	int mask = ~(1 << i);  // will only have 0 at ith position.
	n = (n&mask); // unsetting ith bit.
	return;
}

void set_ith_bit(int &n, int i){
	int mask = (1 << i);  // will only have 1 at ith position.
	n = (n|mask);
	return;
}

void clear_last_i_bits(int &n, int i){
	int mask = (~0) << i; // ~0 is same as -1.
	// this mask will have last i bits as 0.
	n = (n&mask);
	return;
}

void clear_range(int &n, int i, int j){
	int a = (~0) << j+1;  // setting bits 1 till j.
	int b = (1 << i) -1;  // setting last i bits as 1. 
	int mask = (a|b); // all 0s between i and j, others 1.
	n = (n&mask);
	return;
}

void is_power_of_two(int n){
	// mask: (n-1).
	if(!(n&(n-1))){
		cout << n << " is power of 2." << endl;
	} else {
		cout << n << " is not power of 2." << endl;
	}
	return;
}

// function to count total number of set bits in given number.
void count_bits(int n){

	// Time Complexity: O(log N).
	int cnt = 0, temp = n;
	while(n > 0){
		cnt = cnt + (n&1);
		n = n >> 1;
	}
	cout << "Number of set bits is: " << cnt << endl;

	// Time Complexity: O( No. of set bits in n ) -- more faster. 
	cnt = 0, n = temp;
	while(n > 0){
		n = n&(n-1); // will cancel out the last set bit.
		cnt++;
	}
	cout << "Number of set bits is: " << cnt << endl;

	return;
}

void in_binary(int n){
	int p = 1, bin = 0;
	while(n > 0){
		bin += p*(n&1);
		n = n >> 1;
		p = p*10;
	}
	cout << "Binary Representation: " << bin << endl;
	return;
}

// Using bitwise operators we can do exponentiation much faster.
void fast_exponentiation(int n, int i){
	int ans = 1;
	while(i > 0){
		// taking in the exponent for which corresponding bit is 1.
		// for i = 5, (n^4) * (n^1)
		// for i = 7. (n^1) * (n^2) * (n^4)
		if(i&1){
			ans = ans * n;
		}
		n = n*n;
		i = i >> 1;
	}

	cout << "Answer is: " << ans << endl;
	return;
}

// puts m inside n, in the given range.
void replace_bits(int n, int m, int i, int j){
	clear_range(n, i, j);
	n = (n|(m << i));
	cout << "Final result: " << n << endl;
	return;
}

int main(){
        
    int n, i, j;
    cout << "Enter the number: ";
    cin >> n >> i >> j;

    // odd_or_even(n);
    // get_ith_bit(n, i);
    // clear_ith_bit(n, i);
    // set_ith_bit(n, i);
    // clear_last_i_bits(n, i);
    // clear_range(n, i, j);
    // is_power_of_two(n);
    // count_bits(n);
    // in_binary(n);
    // fast_exponentiation(n, i);
    replace_bits(n, 5, i, j);
    cout << n ;
    return 0;
}