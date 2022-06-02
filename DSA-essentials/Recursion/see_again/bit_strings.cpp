#include<bits/stdc++.h>
using namespace std;

// problem: print all  binary strings without comsecutive 1's of given length n.
void get_bitstrings(string s, int i, int n){   // i - current length of bit string.
	// base case - when current length of bit string is same as n.
	if(i == n) {                 
		cout << s << " ";  // print the current string.
		return;
	}

	// when the last bit is 0, next bit can be either 0 or 1.
	if(s[i-1] == '0'){
		s.push_back('1');  // next bit as 1.
		get_bitstrings(s, i+1, n);
		s[i] = '0';  // next bit as 0.
		get_bitstrings(s, i+1, n);
	}
	// when last bit is 1, next bit can only be 0.
	if(s[i-1] == '1'){
		s.push_back('0'); // next bit as 0.
		get_bitstrings(s, i+1, n);
	}

	// when all combinations are done.
	return;
}

int main(){
        
    int n;
    cin >> n;
    
    // for bit strings starting with 0.
    string s = "0";
	get_bitstrings(s, 1, n);

	// for bit strigs starting with 1.
	s[0] = '1';
	get_bitstrings(s, 1, n);

    return 0;
}