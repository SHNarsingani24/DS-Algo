#include<bits/stdc++.h>
using namespace std;

// problem: given a string, print all subsets of it.

bool compare(string a, string b){
	if(a.length() == b.length()){
		return a < b;
	}

	return a.length() < b.length();
}

// function to get all possible subsets of given string.
void get_subsets(char* input, char* output, vector<string> &subsets, int i, int j){
	// base case - when all characters from input string has been considered.
	if(input[i] == '\0'){
		if(j != 0){
			output[j] = '\0';
			string temp(output);
			cout << temp << endl;
			subsets.push_back(temp);
		} else {
			subsets.push_back(" ");
		}
		return;
	}

	// taking character in subset.
	output[j] = input[i];
	get_subsets(input, output, subsets, i+1, j+1);

	// deleting the last character that was taken.
	get_subsets(input, output, subsets, i+1, j);

	return;
}

int main(){
    char input[100], output[100];
    cin >> input;
    vector<string> subsets;

    get_subsets(input, output, subsets, 0, 0);

    sort(subsets.begin(), subsets.end(), compare);

    for(string x: subsets){
    	cout << x << ", ";
    }
    return 0;
}