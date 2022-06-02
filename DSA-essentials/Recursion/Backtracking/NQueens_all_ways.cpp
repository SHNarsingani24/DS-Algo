#include<bits/stdc++.h>
using namespace std;

// problem: place N queens on given NxN chess board, such that no queens can attack each other.

// printing the solution.
void print_board(int board[][20], int N){
	cout << endl;
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

int get_solution(int board[][20], int i, int N){
	// base case - when all the rows are filled.
	if(i == N){
		print_board(board, N); 
		return 1;	// will return 1 when the last row is filled.
	}

	int ways = 0;
	// will iterate through all cell(for current row) and place the queen at appropiate position.
	for(int j = 0; j < N; j++){
		if(can_place(board, i, j, N)){
			board[i][j] = 1;
			ways += get_solution(board, i+1, N);
			
			// backtracking step.
			board[i][j] = 0;

			// this loop won't stop after queens are placed, it will try all the cells.
		}
	}
	return ways;	// In case, queen can't be put in any cell.
}

int main(){
        
    int board[20][20] = {0};
    int N;
    cin >> N;

    int sol = get_solution(board, 0, N);
    cout << "Total " << sol << " ways are possible to place " << N << " queens in " << N << "x" << N << " board." << endl;

    return 0;
}