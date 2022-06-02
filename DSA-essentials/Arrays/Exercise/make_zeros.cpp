#include<bits/stdc++.h>
using namespace std;

// problem: if there is 0 in the 2d vector make whole row and column 0.

void make_zero(vector<vector<int>> &v){
	int n = v.size();
	vector<pair<int, int>> coords;	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(v[i][j]==0){
				coords.push_back({i, j});
			}
		}
	}

	for(int i = 0; i < int(coords.size()); i++){
		for(int j = 0; j < n; j++){
			v[coords[i].first][j] = 0;
			v[j][coords[i].second] = 0;
		}
	}
	return;
}
int main(){

	vector<vector<int>> v ={
		{1, 4, 5, 7},
		{2, 6, 0, 6},
		{0, 1, 2, 4},
		{2, 3, 4, 5}
	};

	int n = v.size();	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	make_zero(v);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}