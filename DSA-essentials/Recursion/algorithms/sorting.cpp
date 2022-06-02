#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(N)
void merge(vector<int> &v, int s, int e){
	int mid = (s+e)/2, i = s, j = mid+1;
	vector<int> temp;

	// main sorting logic.
	while(i <= mid and j <= e){
		if(v[i] > v[j]){
			temp.push_back(v[j++]);
		} else {
			temp.push_back(v[i++]);
		}
	}

	// remaining elements in left half.
	while(i <= mid){
		temp.push_back(v[i++]);
	}
	// remaining elements in rigth half.
	while(j <= e){
		temp.push_back(v[j++]);
	}

	// moving sorted elements from auxilary array to main array.
	int k = 0;
	for(int l = s; l <= e; l++){
		v[l] = temp[k++];
	}

	// to understand stepwise sorting.
	for(int i = 0; i < v.size(); i++){
    	cout << v[i] << " ";
    }
    cout << endl;
	return;
}

// Time Complexity: O(Nlog N).
// Space Complexity: O(N).
void mergesort(vector<int> &v, int s, int e){
	if(s >= e) return; // if there is only one or less element.

	int mid = (s+e)/2;
	// dividing the array.
	mergesort(v, s, mid);
	mergesort(v, mid+1, e);

	// merging the divided parts in sorted manner.
	return merge(v, s, e);
}


// function to make partition of array.
int partition(vector<int> &v, int s, int e){
	int pivot = v[e], i = s-1;		 // taking last element as pivot. we can also take the first or any random element as pivot.
	for(int j = s; j < e; j++){
		if(v[j] < pivot){ 	// taking elements less than pivot in one window. element greater than pivot will remain in other.
			i++;
			swap(v[i], v[j]);
		}
	}

	swap(v[i+1], v[e]); 	// taking pivot element at its right position.

	// to understand stepwise sorting.
	for(int i = 0; i < v.size(); i++){
    	cout << v[i] << " ";
    }
    cout << endl;

	return i+1;
}

// Time Complexity: O(N^2).
// Space Complexity: O(1).
void quicksort(vector<int> &v, int s, int e){
	if(s >= e) return; // if there is only one or less element.

	int p = partition(v, s, e);
	quicksort(v, s, p-1);
	quicksort(v, p+1, e);

	return;
}

int main(){       
    vector<int> v = {10, 5, 2, 0, 7, 6, 4};

    // mergesort(v, 0, v.size()-1);
    quicksort(v, 0, v.size()-1);

    for(int i = 0; i < v.size(); i++){
    	cout << v[i] << " ";
    }
    return 0;
}