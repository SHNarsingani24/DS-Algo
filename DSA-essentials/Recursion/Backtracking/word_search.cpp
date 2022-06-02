#include<bits/stdc++.h>
using namespace std;

// checks if next coordinate is valid or not and moves if valid.
bool can_move(char board[][4], int i, int j, char k, bool visited[][4]){
	if((i >= 0 and i < 3) and (j >= 0 and j < 4) and !visited[i][j] and board[i][j] == k){
		return true;
	}
	return false;
}

bool word_search(char board[][4], int i, int j, int k, string word, bool visited[][4]){
	// base case -- when the word is found.
	if(k == word.length()){
		visited[i][j] = true;	// can be eliminated.
		return true;
	}

	visited[i][j] = true;	// marking current element as visited, as we can't take one letter for 2 times.

	// will only move in direction where next letter is present.
	if(can_move(board, i, j+1, word[k], visited)){
		return word_search(board, i, j+1, k+1, word, visited);
	}
	if(can_move(board, i, j-1, word[k], visited)){
		return word_search(board, i, j-1, k+1, word, visited);
	}
	if(can_move(board, i+1, j, word[k], visited)){
		return word_search(board, i+1, j, k+1, word, visited);
	}
	if(can_move(board, i-1, j, word[k], visited)){
		return word_search(board, i-1, j, k+1, word, visited);
	}

	// if next letter is not present in any direction.
	return false;
}

int main(){
    
    char board[3][4] = {
    	{'A', 'B', 'C', 'E'},
    	{'S', 'F', 'C', 'S'},
    	{'A', 'D', 'E', 'E'}
    };

    bool visited[3][4] = {false};
    string word = "ABCED";

    // if the first letter of grid and word are same then we can pass word without first letter, as the code will never look at (0,0) coordinate.
    if(word[0] == board[0][0]){
    	cout << word_search(board, 0, 0, 0, word.substr(1, word.length()), visited) << endl;
    } else {
    	cout << word_search(board, 0, 0, 0, word, visited) << endl;
    }
    
    // just to see the path.
    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 4; j++){
    		cout << visited[i][j] << " ";
    	}
    	cout << endl;
    }
    return 0;
}