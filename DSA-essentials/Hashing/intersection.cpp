#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// finding intersection of two integer vectors, using unordered map.
vector<int> getIntersection(vector<int> nums1, vector<int> nums2){
	unordered_map<int, int> um;
	vector<int> ans;
	// unordered map will have element of vector 1 as key and count of that element in vector 1 as value.
	for(int i = 0; i < nums1.size(); i++){
		if(um.find(nums1[i])!=um.end()){
			um[nums1[i]]++;
		} else {
			um.insert({nums1[i], 1});
		}
	}

	// if element of nums2 have count > 0 in unordered map, then it means that this element exists in intersection.
	for(int i = 0; i < nums2.size(); i++){
		if(um.find(nums2[i])!=um.end()){
			um[nums2[i]]--;	// decreasing count.
			// once the count of current element reaches 0, we will erase that element from the map, so that next time it won't be added in ans.
			if(um[nums2[i]]==0) um.erase(nums2[i]);
			ans.push_back(nums2[i]);
		}
	}

	// sorting answer, as it was asked.
	sort(ans.begin(), ans.end());
	return ans;
}

int main(){
	vector<int>nums1 = {1, 2, 2, 2, 1};
	vector<int>nums2 = {2, 2, 1};

	vector<int> intersection = getIntersection(nums1, nums2);

	for(int num: intersection){
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

