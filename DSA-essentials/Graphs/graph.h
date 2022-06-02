#include<iostream>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
	int nodes;	// will store number of nodes present in current graph.
	list<int> *adj;

	// making utility function private.
	void dfs_util(int src, bool visited[]){
		// first print the current node.
		cout << src << " ";
		visited[src] = true;	// mark current node visited.
		// traverse through children of current node.
		for(int nbr: adj[src]){
			// if child is not visited, go for it.
			if(!visited[nbr]){
				dfs_util(nbr, visited);
			}
		}
		// once we reached from where there is nothing to traverse.
		return;
	}

	// to manage direct graphs, we are making this function
	void bfs_util(int src, bool visited[]){
		queue<int> q;
		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			// take the front node.
			int f = q.front();
			cout << f << " ";
			q.pop();

			// push all un-visited neighbours of current node in the queue.
			// Note: As graph may contain cycles(unlike trees) we have to maintain visited array.
			for(auto nbr: adj[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

	// utility function for topological_sort_dfs method
	void sort_util(int src, bool visited[], stack<int> &temp){
		// mark curretn node as visited.
		visited[src] = true;
		// traverse all neighbours of current node, and find unvisited one.
		for(auto nbr: adj[src]){
			if(!visited[nbr]){
				// go to unvisited neighbour node.
				sort_util(nbr, visited, temp);
			}
		}
		// once there are no unvisited neighbours, push the current node (after the neighbour nodes).
		temp.push(src);

		return;
	}

public:
	// constructor
	Graph(int nodes){
		this->nodes = nodes;
		adj = new list<int>[nodes];
	}

	// adding an edge!!!
	void addEdge(int i, int j, bool isundir=true){	// isundir stands for is graph undirectional or not!!!
		adj[i].push_back(j);
		if(isundir){
			adj[j].push_back(i);
		}
		return;
	}

	// printing Adjacency List
	void printAdjList(){
		for(int i=0; i<nodes; i++){
			cout << i << " : ";
			for(auto neighbour: adj[i]){
				cout << neighbour << " ";
			}
			cout << endl;
		}
	}

	// Breadth First Search
	void bfs(int src){	// BFS will be started from the given node(src)!!!
		
		bool *visited = new bool[nodes]{false};		// create dynamic boolean array of size of number of nodes, and initialize it with false.

		bfs_util(src, visited);

		// in directed graphs, some nodes may not have any incoming edges, 
		// hence their neighbours will remain unvisited, to handle those nodes!!!
		for(int i = 0; i < nodes; i++){
			if(!visited[i]){
				bfs_util(i, visited);
			}
		}

		return;
	}

	void dfs(int src){
		bool *visited = new bool[nodes]{false};		// create dynamic boolean array of size of number of nodes, and initialize it with false.

		// as we are using recursion here, we have to use an utility function.
		dfs_util(src, visited);

		// in directed graphs, some nodes may not have any incoming edges, 
		// hence they will remain unvisited, to handle those nodes!!!
		for(int i = 0; i < nodes; i++){
			if(!visited[i]){
				dfs_util(i, visited);
			}
		}
		cout << endl;
		return;
	}

	// this algorithm runs on Directed Acyclic Graph, and traverses from nodes with least dependency to the most.
	void topological_sort(){		// Time Complexity: O(V+E)
		// first count indegree for each node.
		int *indegree = new int[nodes]{0};
		for(int i = 0; i < nodes; i++){
			for(auto nbr: adj[i]){
				indegree[nbr]++;
			}
		}

		// Kahn's Algorithm
		queue<int> q;
		for(int i = 0; i < nodes; i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}

		// if there are no elements having 0 indegree, then graph is cyclic.
		if(q.empty()){
			cout << "Graph is not DAG." << endl;
			return;
		}

		// Based on BFS.
		while(!q.empty()){
			int f = q.front();
			q.pop();

			cout << f << " ";
			for(int nbr: adj[f]){
				indegree[nbr]--;
				if(indegree[nbr]==0){
					q.push(nbr);
				}
			}
		}
		return;
	}

	// method for topological sorting based on DFS.
	void topological_sort_dfs(){
		// visited array will track the visited nodes.
		bool *visited = new bool[nodes]{false};
		stack<int> temp;	// of size V.
		// traverse through all nodes.
		for(int i = 0; i < nodes; i++){
			// if current node is not visited already.
			if(!visited[i]){
				// we will use a utility function here.
				sort_util(i, visited, temp);
			}
		}

		while(!temp.empty()){
			cout << temp.top() << " ";
			temp.pop();
		}
		return;
	}
};