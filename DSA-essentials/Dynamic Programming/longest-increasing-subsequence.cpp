#include<iostream>
#include<vector>
using namespace std;

// method to find longest increasing subsequence.
int lis(vector<int> sequence){
	int n = sequence.size();
	// vector to store maximum size of increasing subsequence till ith element.
	vector<int> subseqLens(n, 1);
	int maxLen = 1;
	for(int i = 1; i < n; i++){
		// for each element we will traverse through all previous elements.
		for(int j = 0; j < i; j++){
			// if previous element is less than current element.
			if(sequence[j] <= sequence[i]){
				// maximum of sub-seq len that has been built till yet and sub-seq that can be made from current jth element.
				subseqLens[i] = max(subseqLens[i], subseqLens[j]+1);
				// keeping track of max length till know.
				maxLen = max(maxLen, subseqLens[i]);
			}
		}
	}
	return maxLen;
}

int main(){
	cout << lis({50, 4, 10, 1, 1, 100}) << endl;
	return 0;
}