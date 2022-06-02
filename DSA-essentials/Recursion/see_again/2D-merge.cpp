#include<bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>> &v, pair<int, int> s, pair<int, int> e){

	// sorting given range of the array row wise (based on mergesort algorithm).
	int mid_row = (s.second + e.second)/2, j, k;
	for(int i = s.first; i <= e.first; i++){
		vector<int> temp;
		j = s.second, k = mid_row + 1;
		while(j <= mid_row and k <= e.second){
			if(v[i][j] > v[i][k]){
				temp.push_back(v[i][k++]);
			} else {
				temp.push_back(v[i][j++]);
			}
		}
		while(j <= mid_row){
			temp.push_back(v[i][j++]);
		}
		while(k <= e.second){
			temp.push_back(v[i][k++]);
		}

		int l = 0;
		for(int m = s.second; m <= e.second; m++){
			v[i][m] = temp[l++];
		}
	}

	// sorting given range of the array column wise (based on mergesort algorithm).
	int mid_col = (s.first + e.first)/2;
	for(int i = s.second; i <= e.second; i++){
		vector<int> temp;
		j = s.first, k = mid_col + 1;
		while(j <= mid_col and k <= e.first){
			if(v[j][i] > v[k][i]){
				temp.push_back(v[k++][i]);
			} else {
				temp.push_back(v[j++][i]);
			}
		}
		while(j <= mid_col){
			temp.push_back(v[j++][i]);
		}
		while(k <= e.first){
			temp.push_back(v[k++][i]);
		}
		int l = 0;
		for(int m = s.first; m <= e.first; m++){
			v[m][i] = temp[l++];
		}
	}

	return;
}

void mergesort(vector<vector<int>> &v, pair<int, int> s, pair<int, int> e){  // instead of point, in 2D merge we take tuples.
	// base case - when we get only one single cell.
	if(s.first >= e.first and s.second >= e.second) return;

	pair<int, int> mid = {(s.first+e.first)/2, (s.second+e.second)/2};
	// dividing the array.
	mergesort(v, s, mid);
	mergesort(v, {mid.first+1, s.second}, {e.first, mid.second});
	mergesort(v, {s.first, mid.second+1}, {mid.first, e.second});
	mergesort(v, {mid.first+1, mid.second+1}, e);

	return merge(v, s, e);
}

int main(){
        
    vector<vector<int>> v = {
    	{18, 4, 16, 8},
    	{23, 13, 20, 11},
    	{28, 24, 26, 25},
    	{1, 30, 15, 19}
    };

    pair<int, int> s = {0, 0};
    pair<int, int> e = {v.size()-1, v[0].size()-1};

    mergesort(v, s, e);

    // printing the col and row wiase sorted array.
    for(int i = 0; i < 4; i++){
    	for(int j = 0; j < 4; j++){
    		cout << v[i][j] << " ";
    	}
    	cout << endl;
    }

    return 0;
}