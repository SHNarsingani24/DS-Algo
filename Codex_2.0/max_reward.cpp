// Problem: For given graph find number of unique ways from start node to end node.
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Kahn's Algorithm to find topological order.
vector<int> topological_sort(int nodes, vector<vector<int>> adj){
	vector<int> indegree(nodes, 0);
	for(auto nbrs: adj){
		for(auto nbr: nbrs){
			indegree[nbr]++;
		}
	}

	vector<int> sorted;
	queue<int> q;
	for(int i=0; i < nodes; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int front = q.front();
		sorted.push_back(front);
		q.pop();
		for(int nbr: adj[front]){
			indegree[nbr]--;
			if(indegree[nbr]==0){
				q.push(nbr);
			}
		}
	}
	return sorted;
}

// deiver function to get number of unique ways.
int getAllPaths(int nodes, vector<vector<int>> adj){
	// first we will sort nodes in topological order.
	vector<int> topological_order = topological_sort(nodes, adj);
	vector<int> ways(nodes, 0);
	ways[0] = 1;
	// if parent of a node has X number to reach till it, then child node will also have same number of ways.
	// adding number of ways to reach out all parents for each node and will return number of ways for last node.
	for(int i: topological_order){
		if(i==(nodes-1)) break;		// once we traverse all parent nodes of last node.
		for(int nbr: adj[i]){	   // after this point there won't be any node which has incoming edge in last node.
			ways[nbr] = ways[nbr] + ways[i];
		}
	}
	return ways[nodes-1];
}

int main(){
	int nodes = 5;	// number of nodes in graph.
	// Adjacency List.
	vector<vector<int>> adj= {
		{1, 2, 3},
		{2, 4},
		{4},
		{},
		{}
	};

	cout << getAllPaths(nodes, adj);
	return 0;
}