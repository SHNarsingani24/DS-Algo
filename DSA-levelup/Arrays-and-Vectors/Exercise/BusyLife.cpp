// https://www.spoj.com/problems/BUSYMAN/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> parent, pair<int, int> child){
    return child.second > parent.second;
}

int MaxActivity(vector<pair<int, int>> arr){

    // sorting based on the finishing time of activities.
    sort(arr.begin(), arr.end(), compare);

    // we start from activity that will finish fastest.
    int f = arr[0].second, cnt=1;

    for(int i=1; i<arr.size(); i++){
        // finding next activity that can be done.
        if(arr[i].first >= f){
            f = arr[i].second;
            cnt++;
        }
    }

    return cnt;
}

int main(){
    cout << MaxActivity({{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}});
    return 0;
}