// Problem: Alice is an evil executioner, he has to execute A number of evils.
// He instead of starting from the front starts from the end.
// once he kills the last, let say ith evil, (i-1)th evil runs to the start of the line.
// Find out which one will be executed at last.

#include<iostream>
using namespace std;

// Note: From the pattern we can conclude when there are 2^x number of evils in line, 
// then the evil standing first(before execution of any evil) will be executed last.

// Function to know if given number is power of two or not.
// Time complexity: O(log X)
bool isPowerOfTwo(int X){
	if(X==0) return true;
	while(X!=1){
		if(X&1) return false;
		X = X / 2;
	}
	return true;
}

// driver function to find the last executed evil.
// Time Complexity: O(executed* Log N)
int lastExecuted(int A){
	int executed = 0;
	// if A is already in power of two.
	if(isPowerOfTwo(A)) return 1;
	// find number of evils executed before number becomes power of two.
	int temp = A;
	while(!isPowerOfTwo(temp)){
		executed++;
		temp--;
	}
	// executed = A - pow(2, floor(log2(A)))		--- functions in cmath library.
	// the element at first of the row can be found with this formula.
	return A - (2*executed) + 1;
}

int main(){
	int x;
	cin >> x;
	cout << lastExecuted(x);
}