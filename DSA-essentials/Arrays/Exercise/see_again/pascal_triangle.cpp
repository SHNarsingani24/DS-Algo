#include<bits/stdc++.h>
using namespace std;

int main(){

	int N = 6;

    vector<vector<int>> v;
    v.push_back({1});
    v.push_back({1, 1});
    for(int i = 1; i < N; i++){
    	vector<int> subv = {1};
    	for(int j = 0; j < int(v[i].size())-1; j++){
    		subv.push_back(v[i][j]+v[i][j+1]);
    	}
    	subv.push_back(1);
    	v.push_back(subv);
    }

    for(int i = 0; i < N; i++){
    	for(int j = 0; j < int(v[i].size()); j++){
    		cout << v[i][j] << " ";
    	}
    	cout << endl;
    }
    return 0;
}