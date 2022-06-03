// Given an array of integers, we have to find a maximum width of a mountain.
// mountain is created if there is an element which has decreasing elements before and after it.
// e.g., 1 2 3 4 5 4 3 2 1

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N)
int get_mountain(vector<int> arr){
    int n = arr.size(), max_width = -1;
    // atleast 3 elements are required to make a mountain.
    if(n < 3) return -1;
    // O(2*N) => O(N) : as we will traverse all element for 2 times.
    for(int i=1; i<n-1; i++){
        // finding a peak.
        int curr = arr[i], prev = arr[i-1], next = arr[i+1];
        if((curr > prev) and (curr > next)){
            // once a peak is found
            int width = 1, j=i-1, k=i;
            // checking previous elements.
            while(j>=0){
                if(arr[j]<arr[k]){
                    width++;
                    j--, k--;
                } else {
                    break;
                }
            }
            // checking next elements.
            j=i+1, k=i;
            while(j<n){
                if(arr[j]<arr[k]){
                    width++;
                    j++, k++;
                } else {
                    // as from i to j all elements were decreasing, there can't be a peak in this range. 
                    i=j; 
                    break;
                }
            }
            // finding maximum one.
            if(width > max_width){
                max_width = width;
            }
        }
    }

    return max_width;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,4,3,2,1};
    cout << get_mountain(arr) << endl;
    return 0;
}