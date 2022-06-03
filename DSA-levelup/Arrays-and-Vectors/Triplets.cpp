#include <iostream>
#include <vector>
#include <utility>
#include<algorithm>
using namespace std;


// We can use solution with heap here, however it will cost us O(N) space. 
// as we are required to sort the arr anyways, using this solution will not cost us more time.
// Time Complexity: O(N)
vector<pair<int, int>> get_pairs(vector<int> arr, int target, int s, int e){
    vector<pair<int,int>> pairs;
    while(s<e){
        if(arr[s]+arr[e] < target){
            s++;
        } else if(arr[s]+arr[e] > target){
            e--;
        } else {
            pairs.push_back({arr[s], arr[e]});
            s++, e--;
        }
    }
    return pairs;
}

// Time Complexity: O(N^2)
vector<vector<int>> get_triplets(vector<int> arr, int target){

    int n = arr.size();
    vector<vector<int>> res;

    // O(NlogN)
    sort(arr.begin(), arr.end());

    // O(N^2)
    for(int i=0; i<n; i++){
        // select one element and find a pair that sums up to remaining target.
        int curr = arr[i];
        vector<pair<int, int>> pairs = get_pairs(arr, target-curr, i+1, n-1);

        // for each pair we get we are making triplet here by adding curr element in it.
        for(auto pair: pairs){
            res.push_back({curr, pair.first, pair.second});
        }

    }

    return res;
}

int main(){
    vector<int> arr = {3, 1, -6, 5, 4, 7, 9, 11, 13};
    int target = 16;
    vector<vector<int>> triplets = get_triplets(arr, target);
    for(auto i: triplets){
        cout << i[0] << " + " << i[1] << " + " << i[2] << " = " << target << endl;
    }
    return 0;
}