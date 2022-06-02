#include<bits/stdc++.h>
using namespace std;

// always mention size of each dimention, except first one.
void print(int arr[][100], int n, int m){
	for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cout << arr[i][j] << " ";
    	}
    	cout << endl;
    }
}

// printing array in spiral pattern.
void spiral_print(int arr[][100], int n, int m){

	int start_row = 0, start_col = 0;
	int end_row = n -1, end_col = m-1;

	while(start_row <= end_row and start_col <= end_col){
		for(int col = start_col; col <= end_col; col++){
			cout << arr[start_row][col] << " ";
		}
		for(int row = start_row+1; row <= end_row; row++){
			cout << arr[row][end_col] << " ";
		}
		for(int col = end_col-1; col >= start_col; col--){
			if(start_row == end_row){
				break;
			}
			cout << arr[end_row][col] << " "; 
		}
		for(int row = end_row-1; row > start_row; row--){
			if(start_col == end_col){
				break;
			}
			cout << arr[row][start_col] << " ";
		}
		start_row++, start_col++;
		end_row--, end_col--;
	}

	cout << endl;
	return;
}

// Printing array in wave form, starting from the element at first row & last column.
void wave_print(int arr[][100], int n, int m){
	int direction = -1, j = 0;
	for(int i = m-1; i >= 0; i--){
		if(direction == -1){
			for(int j = 0; j < n; j++){
				cout << arr[j][i] << " ";
			}
			direction = 1;
		} else if(direction == 1){
			for(int j = n-1; j >= 0; j--){
				cout << arr[j][i] << " ";
			}
			direction = -1;
		}
	}
}

int main(){       
    int arr[100][100];
    int n, m;
    cin >> n >> m;

    // taking input in 2D array.
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> arr[i][j];
    	}
    }

    // printing the 2d array.
    print(arr, n, m);

    // printing in spiral patter.
    spiral_print(arr, n, m);

    // wave printing the matrix.
    wave_print(arr, n, m);

    return 0;
}