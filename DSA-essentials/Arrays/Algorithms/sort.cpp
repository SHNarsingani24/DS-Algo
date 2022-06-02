#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2).
// Space Complexity: O(1).
void bubble_sort(int arr[], int n){
	for(int i =0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	return;
}

// Time Complexity: O(N^2)
// Space Complexity: O(1)
void insertion_sort(int arr[], int n){
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0; j--){
			if(arr[j] < arr[j-1]){
				swap(arr[j], arr[j-1]);
			} else {
				break;
			}
		}
	}
	return;
}

// Time Complexity: O(N^2)
// Space Complexity: O(1)
void selection_sort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i; j < n; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		swap(arr[min], arr[i]);
	}
	return;
}

// Time Complexity: O(N+range)
// Space Complexity: O(range)
void count_sort(int arr[], int n, int range){
	int count[range] = {0};
	for(int i = 0; i < n; i++){
		count[arr[i]]++;
	}
	int j = 0;
	for(int i = 0; i < range; i++){
		while(count[i]!=0){
			arr[j] = i;
			count[i]--;
			j++;
		}
	}
	return;
}

int main(){
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr)/sizeof(int);
    
    for(int i = 0; i < n; i++){
    	cout << arr[i] << " ";
    }
    cout << endl;
    

    // bubble_sort(arr, n);
    // insertion_sort(arr, n);
    // selection_sort(arr, n);
    sort(arr, arr+n); // Inbuit sort function of C++. we can add third argument as comparator to make it revrse sort, default is greater<int>().
    // sort(arr, arr+n, function_name) - here function will tell how to compare two numbers. just name not ()!!!

    for(int i = 0; i < n; i++){
    	cout << arr[i] << " ";
    }
    cout << endl;

    // For count sort only.
    // int arr1[] = {2, 3, 6, 3, 1, 2, 5, 7, 6, 9};
    // int n = sizeof(arr1)/sizeof(int);

    // for(int i = 0; i < n; i++){
    // 	cout << arr1[i] << " ";
    // }
    // cout << endl;

    
    // count_sort(arr1, n, 10);

    // for(int i = 0; i < n; i++){
    // 	cout << arr1[i] << " ";
    // }
    // cout << endl;

    return 0;
}