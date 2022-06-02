#include<bits/stdc++.h>
using namespace std;

// function to rotate 2D vector 90 degree clockwise.
void rotate_vector(vector<vector<int>>&v){
	int N = v.size();

	for(int i = 0; i < N/2; i++){					// There will be total N/2 cycles that has to be rotated.
		for(int j = i; j < N-i-1; j++){

			// storing the current element as temp.
			int temp = v[i][j];

			// left column to top row.
			v[i][j] = v[N-j-1][i];

			// bottom row to left column.
			v[N-j-1][i] = v[N-i-1][N-j-1];

			// right column to bottom row.
			v[N-i-1][N-j-1] = v[j][N-i-1];

			// top row to right column.
			v[j][N-i-1] = temp;
		}
	}

	return;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> v;

    // taking 2D vector from user.
    for(int i = 0; i < n; i++){
    	vector<int> temp;
    	for(int j = 0; j < n; j++){
    		int t;
    		cin >> t;
    		temp.push_back(t);
    	}
    	v.push_back(temp);
    }

    for(vector<int> x: v){
    	for(int y: x){
    		cout << y << " ";
    	}
    	cout << endl;
    }

    rotate_vector(v);

    for(vector<int> x: v){
    	for(int y: x){
    		cout << y << " ";
    	}
    	cout << endl;
    }

    return 0;
}