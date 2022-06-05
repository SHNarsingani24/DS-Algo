// Given an array, find the largest band of consecutive numbers.
// for example, if array is [10, 11, 13, 12, 0, 1, 2, 3, 4, 5, 6, 7] then largest band is
// [0, 1, 2, 3, 4, 5, 6, 7] which has size 8 and hence we should return 8 as an answer.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Time Complexity: O(N)
// Note that the inner work will be totally done in O(N) time and hence it won't make the time complexity O(N^2).
int largest_band(vector<int> arr){
    int n = arr.size();
    int band = 1;

    // Storing All elements in unordered set.
    unordered_set<int> s;
    for(int i: arr){
        s.insert(i);
    }

    for(int i=0; i<n; i++){
        // if previous element does not exist, we will go and find length of band we can make from current element.
        int parent = arr[i]-1;
        if(s.find(parent)==s.end()){
            int cnt=1, next=arr[i]+1;
            // till consecutive elements exist.
            while(s.find(next)!=s.end()){
                next++;
                cnt++;
            }
            if(cnt > band){
                band = cnt;
            }
        }
    }
    return band;
}

int main(){
    vector<int> arr = {2, 12, 11, 10, 3, 1, 0, 7, 6, 13, 4};
    cout << largest_band(arr);
    return 0;
}