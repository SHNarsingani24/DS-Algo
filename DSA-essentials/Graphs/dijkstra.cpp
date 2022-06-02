#include<iostream>
#include<set>
#include<list>
#include<vector>
using namespace std;

class Graph{
	int V; 			// represents number of vertices in graph.
	list<pair<int, int>> *adj;

public:
	Graph(int v){
		V = v;
		adj = new list<pair<int, int>>[V];
	}

	void addEdge(int src, int dest, int wt, bool undir=false){
		adj[src].push_back({wt, dest});
		if(undir){
			adj[dest].push_back({wt, src});
		}
		return;
	}

	void printAdjList(){
		for(int i = 0; i < V; i++){
			cout << "Node " << i << " : ";
			for(auto nbr: adj[i]){
				cout << "(" << nbr.first << ", " << nbr.second << ") ";
			}
			cout << endl;
		}
	}

	// Time Complexity of this algo is O(ElogV) 
	// here we will traverse each edge and for each edge we will insert/remove data in set which takes O(log V) time, 
	// as set uses heap internally.
	void dijkstra(int src, int dest){
		vector<int> dist(V, INT_MAX);
		// using set as it will arrange the elements in sorted manner.
		set<pair<int, int>> ans;	// will store nodes and distance of nodes from src.

		// src node from itself is at 0 distance.
		dist[src] = 0;
		ans.insert({src, dist[src]});

		// kind of BFS, but here we will insert nodes for which we can reduce the distance from src to that node.
		while(!ans.empty()){
			auto strt = ans.begin();
			
			// first element of ans set will be closest to the src node.
			int node = strt->first;		// this node will be at minimum distance.
			int d = strt->second;		// min distance till now.
			ans.erase(strt);

			for(auto nbr: adj[node]){
				// updating distance of neighbour nodes, if distance can be optimized.
				if(dist[nbr.second] > d + nbr.first){
					// if nbr is already there in set, we will delete it as set doen't support update operation.
					auto temp = ans.find({nbr.second, dist[nbr.second]});
					if(temp!=ans.end()){
						ans.erase(temp);
					}

					// inserting updated values.
					dist[nbr.second] = d + nbr.first;
					ans.insert({nbr.second, dist[nbr.second]});
				}
			}
		}

		for(int i = 0; i < V; i++){
			cout << src << " -> " << i << " : " << dist[i] << endl;
		}

	}
};

int main(){
	Graph g(5);

	g.addEdge(0, 1, 1);
	g.addEdge(0, 2, 4);
	g.addEdge(0, 3, 7);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 2);
	g.addEdge(3, 4, 3);

	g.dijkstra(0, 4);

	return 0;
}
