// Given an array find minimum number of swaps to sort that array.

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Time Complexity: O(NlogN)
int min_swaps(vector<int> arr){
    vector<pair<int, int>> pairs;
    
    // making pairs of element and it's current index
    int n=arr.size(), swaps=0;
    for(int i=0; i<n; i++){
        pairs.push_back({arr[i], i});
    }

    // O(NlogN): sorting all the pairs (based on their first element: which is arr[i])
    sort(pairs.begin(), pairs.end());

    // now all pairs are at their right positions and it also contain their previous indices.

    // if element is visited it means that it is already considered for swapping.
    vector<bool> visited(n, false);
    // O(N)
    for(int i=0; i<n; i++){
        // if element is already considered for swapping or there is no need to swap it.
        if(visited[i] or pairs[i].second==i){
            continue;
        }

        // considering current node we are counting the length of the cycle we can make from this node.
        int cycle=0, node=i;
        while(!visited[node]){  // condition false if we are coming back to the same element.
            visited[node] = true;
            node = pairs[node].second;  // moving to next node.
            cycle++;
        }

        // if cycle contains N elements we will require to make N-1 swaps.
        swaps = swaps + (cycle-1);
    }

    return swaps;
}

int main(){
    vector<int> arr = {2, 5, 4, 6, 1, 3};
    cout << min_swaps(arr);
    return 0;
}