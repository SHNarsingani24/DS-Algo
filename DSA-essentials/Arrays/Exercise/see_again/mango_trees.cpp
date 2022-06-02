#include<bits/stdc++.h>
using namespace std;

// Problem at: https://www.iarcs.org.in/inoi/online-study-material/topics/prefix-sums-ramus-mango-trees.php

pair<int, int> get_coords(int prefix_matrix[][6], int N){
	int max_trees = INT_MIN;
	pair<int, int> ans;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int s1 = prefix_matrix[i][j];
			int s2 = prefix_matrix[i][N-1] - s1;
			int s3 = prefix_matrix[N-1][j] - s1;
			int s4 = prefix_matrix[N-1][N-1] - s1 - s2 - s3;
			int cur_min = min({s1, s2, s3, s4});
			if(cur_min > max_trees){
				max_trees = cur_min;
				ans = {i, j};
			}
		}
	}
	return ans;
}

void get_prefix_matrix(char farm[][6], int prefix_matrix[][6], int N){
	prefix_matrix[0][0] = (farm[0][0]=='#' ? 1 : 0);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == 0 and j == 0) continue;
			if(i == 0 and j > 0){
				prefix_matrix[i][j] = prefix_matrix[i][j-1] + (farm[i][j]=='#' ? 1 : 0);
			} else if(j == 0 and i > 0){
				prefix_matrix[i][j] = prefix_matrix[i-1][j] + (farm[i][j]=='#' ? 1 : 0);
			} else {
				prefix_matrix[i][j] = prefix_matrix[i-1][j] + prefix_matrix[i][j-1] - prefix_matrix[i-1][j-1] + (farm[i][j]=='#' ? 1 : 0);
			}
		}
	}

	return;
}

int main(){
        
    char farm[6][6] = {
    	{'.', '#', '#', '.', '.', '.'},
    	{'#', '.', '.', '#', '#', '.'},
    	{'.', '#', '.', '.', '.', '.'},
    	{'.', '#', '#', '.', '.', '#'},
    	{'#', '.', '.', '#', '#', '.'},
    	{'.', '#', '.', '.', '.', '.'}
    };

    int prefix_matrix[6][6];
    get_prefix_matrix(farm, prefix_matrix, 6);
    
    pair<int, int> ans = get_coords(prefix_matrix, 6);

    cout << "The coordinates to get max trees are, (" << ans.first << ", " << ans.second << ")." << endl;
    return 0;
}