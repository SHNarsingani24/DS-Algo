#include<bits/stdc++.h>
using namespace std;

// checking if we can move to (i, j) coordinate.
bool is_safe(int i, int j, char maze[][4], int m, int n, bool visited[][4]){
	if((i <= m and i > -1) and (j <= n and j > -1) and maze[i][j] == 'O' and !visited[i][j]){
		return true;
	}
	return false;
}

bool get_path(char maze[][4], int m, int n, int path[][4], int i, int j, bool visited[][4]){
	// base case - if we reached to (m, n).
	if(i == m-1 and j == n-1){
		path[i][j] = 1;
		return true;
	}

	visited[i][j] = true;
	path[i][j] = 1;

	// going down if possible.
	if(is_safe(i+1, j, maze, m, n, visited)){
		if(get_path(maze, 5, 4, path, i+1, j, visited)){
			return true;
		}
		// backtracking.
		path[i+1][j] = 0;
	}

	// going up, if possible.
	if(is_safe(i-1, j, maze, m, n, visited)){
		if(get_path(maze, 5, 4, path, i-1, j, visited)){
			return true;
		}
		// backtracking.
		path[i-1][j] = 0;
	} 

	// going right, if possible.
	if(is_safe(i, j+1, maze, m, n, visited)){
		if(get_path(maze, 5, 4, path, i, j+1, visited)){
			return true;
		}
		// backtracking.
		path[i][j+1] = 0;
	}

	// going left, if possible.
	if(is_safe(i, j-1, maze, m, n, visited)){
		if(get_path(maze, 5, 4, path, i, j-1, visited)){
			return true;
		}
		// backtracking.
		path[i][j-1] = 0;
	}

	// if blocked, then the parent will change the path.
	return false;
}

int main(){
        
    char maze[5][4] = {
    	{'O', 'O', 'O', 'O'},
    	{'O', 'X', 'O', 'X'},
    	{'X', 'X', 'O', 'O'},
    	{'X', 'O', 'O', 'X'},
    	{'X', 'X', 'O', 'O'}
    };

    int path[5][4] = {0};

    bool visited[5][4] = {false};

    get_path(maze, 5, 4, path, 0, 0, visited);

    for(int i = 0; i < 5; i++){
    	for(int j = 0; j < 4; j++){
    		cout << path[i][j] << " ";
    	}
    	cout << endl;
    }

    return 0;
}