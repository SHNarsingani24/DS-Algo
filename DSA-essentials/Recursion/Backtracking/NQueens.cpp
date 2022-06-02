#include<bits/stdc++.h>
using namespace std;

// problem: place N queens on given NxN chess board, such that no queens can attack each other.

// printing the solution.
void print_board(int board[][20], int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

bool can_place(int board[][20], int i, int j, int N){
	// checking the part of column that is on upper side of current position. 
	for(int x = 0; x < i; x++){
		if(board[x][j]){
			return false;
		}
	}

	// checking the part of left diagonal, on the upper side of current position.
	int x = i, y = j;
	while(x >= 0 and y >= 0){
		if(board[x--][y--]){
			return false;
		}
	}

	// checking the part of right diagonal, on the upper side of current position.
	x = i, y = j;
	while(x >= 0 and y <= N){
		if(board[x--][y++]){
			return false;
		}
	}

	// the below part from current position, is not required to be checked as it is yet to be filled.
	// also as the queens are placed row by row, rows are also not required to be checked.
	return true;
}

bool get_solution(int board[][20], int i, int N){
	// base case - when all the rows are filled.
	if(i == N){
		print_board(board, N);
		return true;
	}
	// will iterate through all cell(for current row) and place the queen at appropiate position.
	for(int j = 0; j < N; j++){
		if(can_place(board, i, j, N)){
			board[i][j] = 1;
			bool is_possible = get_solution(board, i+1, N);
			// if child rows can't be solved, queen is removed from current cell and next cell will be tried.
			if(!is_possible){
				// backtracking step.
				board[i][j] = 0;
			} else {	
				return true;
			}
		}
	}
	return false;	// In case, queen can't be put in any cell.
}

int main(){
        
    int board[20][20] = {0};
    int N;
    cin >> N;

    bool sol = get_solution(board, 0, N);
    if(!sol){
    	cout << "No solution possible for N = " << N << endl;
    }

    return 0;
}