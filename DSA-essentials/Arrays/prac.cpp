#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    return;
}

void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            } else {
                break;
            }
        }
    }
    return;
}

int main(){
    int arr[6] = {5, 2, 1, 3, 6, 4};
    for(int x: arr){
        cout << x << " ";
    }
    insertion_sort(arr, 6);
    for(int x: arr){
        cout << x << " ";
    }
    return 0;
}