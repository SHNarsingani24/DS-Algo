#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// given a vector, find all the pairs whose sum is equal to K.
// using unordered_set or unordered_map we can solve this problem in O(N) time complexity.
void find_pairs(vector<int>v, int k){
	unordered_set<int> tracker;
	for(int i = 0; i < v.size(); i++){
		int remaining = k - v[i];
		if(tracker.find(remaining)!=tracker.end()){
			cout << "(" << remaining << ", " << v[i] << ")" << endl;
		}
		tracker.insert(v[i]);
	}
	return;
}

int main(){
	vector<int>v = {1, 4, 3, 7, -1, 0, 10, 8, 11};
	int k = 11;
	find_pairs(v, k);
	return 0;
}