#include<bits/stdc++.h>
using namespace std;

void print_mat(int mat[][9], int n){
	cout << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool can_place(int mat[][9], int i, int j, int k, int n){
	// cheking the row and column.
	for(int l = 0; l < n; l++){
		if(mat[i][l] == k or mat[l][j] == k){
			return false;
		}
	}

	// checking the 3x3 grid.
	int sx = (i/3)*3, sy = (j/3)*3;		// getting the starting index of 3x3 grid in which current (i, j) are.
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			if(mat[sx+x][sy+y]==k){
				return false;
			}
		}
	}

	return true;
}

bool solve_sudoku(int mat[][9], int i, int j, int n){
	// base case - when all rows are filled.
	if(i == n){
		print_mat(mat, n);
		return true;
	}

	// when one row is filled.
	if(j == n){
		return solve_sudoku(mat, i+1, 0, n);
	}

	// when the cell is pre-filled.
	if(mat[i][j]){
		return solve_sudoku(mat, i, j+1, n);
	}

	// try each number from 1 to 9 for current cell.
	for(int k = 1; k < 10; k++){
		if(can_place(mat, i, j, k, n)){
			mat[i][j] = k;
			bool is_possible = solve_sudoku(mat, i, j+1, n);
			if(is_possible){
				return true;
			}
		}
	}

	// when there is no possible answer.
	mat[i][j] = 0;
	return false;
}

int main(){ 
    int n = 9;  
    int mat[9][9] = {
    	{5, 3, 0, 0, 7, 0, 0, 0, 0},
    	{6, 0, 0, 1, 9, 5, 0, 0, 0},
    	{0, 9, 8, 0, 0, 0, 0, 6, 0},
    	{8, 0, 0, 0, 6, 0, 0, 0, 3},
    	{4, 0, 0, 8, 0, 3, 0, 0, 1},
    	{7, 0, 0, 0, 2, 0, 0, 0, 6},
    	{0, 6, 0, 0, 0, 0, 2, 8, 0},
    	{0, 0, 0, 4, 1, 9, 0, 0, 5},
    	{0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    bool sol = solve_sudoku(mat, 0, 0, n);
    if(!sol){
    	cout << "No solution possible." << endl;
    }
    return 0;
}