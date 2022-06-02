#include<bits/stdc++.h>
using namespace std;

// kind of binary search.
pair<int, int>staircase_search(int arr[][4], int n, int m, int key){
	if(key < arr[0][0] or key > arr[n-1][m-1]){
		return {-1, -1};
	}

	int i =0, j = m-1;
	while(i < n and j > -1){
		if(arr[i][j] == key){
			return {i, j};
		} else if(arr[i][j] > key){
			j--;
		} else {
			i++;
		}
	}

	return {-1, -1};
}

int main(){
    
    // 2D array that is row and column wise sorted.
    int arr[4][4] = {
    	{12, 16, 19, 21},
    	{14, 18, 24, 26},
    	{17, 22, 27, 30},
    	{23, 25, 34, 49}
    };

    int key = 23;
    pair<int, int> coord = staircase_search(arr, 4, 4, key);

    if(coord.first != -1){
    	cout << key << " is available at (" << coord.first << ", " << coord.second << ")." << endl;
    } else {
    	cout << key << " is not present in this matrix." << endl;
    }
    
    return 0;
}