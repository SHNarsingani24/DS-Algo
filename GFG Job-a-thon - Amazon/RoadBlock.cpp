// Problem: https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems#
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> eulerTour;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> startIndex;
unordered_map<int, int> endIndex;
vector<int> visited(100005, 0);
vector<int> height(100005, 0);

void getEulerTour(int i, int h){
    height[i] = h;
    visited[i]=1;
    eulerTour.push_back(i);
    startIndex[i] = eulerTour.size()-1;
    for(int next: graph[i]){
        if(!visited[next]){
            getEulerTour(next, h+1);
        }
    }
    eulerTour.push_back(i);
    endIndex[i] = eulerTour.size()-1;
    return;
}

// Time Complexity - (Max(Q, N)).
// Space Complexity - O(N).
vector<int> ResolveQueries(int N, int Q, vector<vector<int>> Edge, vector<vector<int>> query){
    for(auto i: Edge){
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }

    getEulerTour(0, 0);

    vector<int> prefix, suffix;
    suffix.push_back(height[0]);
    prefix.push_back(height[0]);
    for(int i=1; i<(2*N); i++){
        prefix.push_back(max(prefix[i-1], height[eulerTour[i]]));
        suffix.push_back(max(suffix[i-1], height[eulerTour[(2*N-1)-i]]));
    }

    vector<int> ans;
    for(auto q: query){
        int s = startIndex[q[1]] - 1;
        int e =(2*N-1) - (endIndex[q[1]] + 1);
        if(s<0 and e<0)
            ans.push_back(0);
        else if(s<0)
            ans.push_back(suffix[e]);
        else if(e<0)
            ans.push_back(prefix[s]);
        else
            ans.push_back(max(suffix[e], prefix[s]));
    }

    return ans;
}

int main(){
    int N=3;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2}
    };

    vector<vector<int>> query = {
        {0, 1}
    };

    vector<int> ans = ResolveQueries(N, query.size(), edges, query);
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}