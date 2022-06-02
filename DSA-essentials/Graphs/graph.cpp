#include<iostream>
#include "./graph.h"
using namespace std;

int main(){
	// Graph g(5);
	// g.addEdge(0, 1);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);
	// g.addEdge(1, 4);
	// g.addEdge(2, 4);

	// g.printAdjList();

	// g.dfs(2);

	Graph dag(6);
	dag.addEdge(0, 2, false);
	dag.addEdge(2, 3, false);
	dag.addEdge(3, 5, false);
	dag.addEdge(4, 5, false);
	dag.addEdge(1, 4, false);
	dag.addEdge(1, 2, false);

	dag.topological_sort();
	cout << endl;
	dag.topological_sort_dfs();
	cout << endl;

	// Special Case of directed graph (for dfs & bfs).
	Graph g(6);
	g.addEdge(5, 2, false);
	g.addEdge(5, 0, false);
	g.addEdge(4, 1, false);
	g.addEdge(4, 0, false);
	g.addEdge(2, 3, false);
	g.addEdge(3, 1, false);

	// g.bfs(1);
	// cout << endl;
	// g.dfs(1);
	g.topological_sort_dfs();
	cout << endl;
	g.topological_sort();
	return 0;
}
