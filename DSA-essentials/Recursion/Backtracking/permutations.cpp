#include<bits/stdc++.h>
using namespace std;

void get_permutations(string input, int i){
	if(input.length() == i){
		cout << input << endl;
		return;
	}

	// swapping current element with each one that appears after that.
	for(int j = i; j < input.length(); j++){
		swap(input[i], input[j]);	// in the 1st iteration element will swapped by itself.
		get_permutations(input, i+1);
		swap(input[i], input[j]);	// restoring the string as it was before -- backtracking.
	}

	return;
}

int main(){
        
   	string input;
   	cin >> input;

   	get_permutations(input, 0);

    return 0;
}