#include<bits/stdc++.h>
using namespace std;

// Problem: Given a sorted array and integer x, find a pair having closest sum to x.
pair<int, int> closestSum(vector<int> v, int x){

	int diff = INT_MAX, n = v.size();
	pair<int, int> ans;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			int curr_diff = abs(x-(v[j]+v[i]));
			if(curr_diff < diff){
				ans.first = v[i];
				ans.second = v[j];
				diff = curr_diff;
			}
		}
	}
	return ans;
}

int main(){
    
    vector<int> v = {10, 22, 28, 29, 30, 40};
    int x = 54;

    pair<int, int> ans = closestSum(v, x);

    cout << "The required pair is: " << ans.first << " " << ans.second << "." << endl;

    return 0;
}