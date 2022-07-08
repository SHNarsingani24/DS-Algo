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

    vector<int> prefix, suffix(2*N, height[0]);
    suffix[2*N-1] = height[0];
    prefix.push_back(height[0]);
    for(int i=1; i<(2*N); i++){
        prefix.push_back(max(prefix[i-1], height[eulerTour[i]]));
        suffix[2*N-1-i] = max(suffix[2*N-i], height[eulerTour[(2*N-1)-i]]);
    }

    vector<int> ans;
    for(auto q: query){
        int s1 = startIndex[q[0]] - 1;
        int e1 = endIndex[q[0]] + 1;
        int s2 = startIndex[q[1]] - 1;
        int e2 = endIndex[q[1]] + 1;
        
        int opt1, opt2;
        if(s1<0 and e1>=2*N)
            opt1 = 0;
        else if(s1<0)
            opt1 = suffix[e1];
        else if(e1>=2*N)
            opt1 = prefix[s1];
        else
            opt1 = max(prefix[s1], suffix[e1]);

        if(s2<0 and e2>=2*N)
            opt2 = 0;
        else if(s2<0)
            opt2 = suffix[e2];
        else if(e2>=2*N)
            opt2 = prefix[s2];
        else
            opt2 = max(prefix[s2], suffix[e2]);
        
        ans.push_back(max(opt1, opt2));
    }

    return ans;
}

int main(){
    int N=9;
    vector<vector<int>> edges = {
        {5, 7},
        {0, 2},
        {7, 8},
        {0, 8},
        {1, 2},
        {2, 6},
        {4, 8},
        {0, 3}
    };

    vector<vector<int>> query = {
        {4, 8}
    };

    vector<int> ans = ResolveQueries(N, query.size(), edges, query);
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}