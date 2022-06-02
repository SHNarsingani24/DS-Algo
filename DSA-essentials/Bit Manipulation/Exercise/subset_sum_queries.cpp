#include<bits/stdc++.h>
using namespace std;

vector<bool> subset_sum(vector<int> num, vector<int> query){
	vector<bool> ans;
	int bitsum = 1;  // will maintain single bit string.
	// if bit is 1 than that sum is possible. Initial value is 1 -> 000001 as sum 0 is possible for any array.
	// will << each array element with previous bitstring maintained.
	for(int i = 0; i < num.size(); i++){
		bitsum = bitsum | (bitsum << num[i]);  // maintains previous bitstring and sets bits that represents sums that are possible using element num[i]
	}

	for(int i = 0; i < query.size(); i++){
		if((bitsum >> query[i])&1){
			ans.push_back(true);
		} else {
			ans.push_back(false);
		}
	}

	return ans;
}

int main(){
        
    vector<int> s = {1, 2, 3};
    vector<int> q = {5, 3, 8};

    vector<bool> a = subset_sum(s, q);

    for(int i = 0; i < a.size(); i++){
    	cout << a[i] << " ";
    }
    return 0;
}