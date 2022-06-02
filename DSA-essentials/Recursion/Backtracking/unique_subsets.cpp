#include<bits/stdc++.h>
using namespace std;

set<vector<int>> s;

bool compare(vector<int> a, vector<int> b){
	return a.size() < b.size();
}

void unique_subsets(vector<int> nums, vector<int> &ans, int i){
	// base case.
	if(i == nums.size()){
		sort(ans.begin(), ans.end());
		s.insert(ans);		// inserting in set, so that no subset is repeated.
		return;
	}

	// taking the number.
	ans.push_back(nums[i]);
	unique_subsets(nums, ans, i+1);

	// not taking number.
	ans.pop_back();
	unique_subsets(nums, ans, i+1);

	return;
}


int main(){
        
    vector<int> nums = {1, 2, 2}, ans;

    unique_subsets(nums, ans, 0);

    // once the subsets are found, then storing them in 2D vector.
    vector<vector<int>> v;
    for(auto x: s){
    	v.push_back(x);
    }

    // sorting final vector according to the length of sub-vectors(subsets).
    sort(v.begin(), v.end(), compare);

    // printing all subsets.
    for(int i = 0; i < v.size(); i++){
    	for(int j = 0; j < v[i].size(); j++){
    		cout << v[i][j] << " ";
    	}
    	cout << endl;
    }
    return 0;
}