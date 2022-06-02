// problem: Given a DAG, print all possible paths from 0 to n-1 node (in any order).
#include<iostream>
#include<vector>
using namespace std;

// utility function that will traverse given DAG in DFS manner.
void paths_util(int i, vector<vector<int>> graph, vector<vector<int>> &paths, vector<int> temp){
	int n = graph.size()-1;
	if(i==n){
		paths.push_back(temp);
		return;
	}

	for(int nbr: graph[i]){
		temp.push_back(nbr);
		paths_util(nbr, graph, paths, temp);
		temp.pop_back(); // backtracking
	}

	return;
}

// driver function to find all paths.
vector<vector<int>> getAllPaths(vector<vector<int>> graph){
	vector<vector<int>> paths;
	vector<int> temp = {0};
	paths_util(0, graph, paths, temp);
	return paths;
}

int main(){
	vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
	vector<vector<int>> paths = getAllPaths(graph);

	for(int i = 0; i < paths.size(); i++){
		for(auto node: paths[i]){
			cout << node << " ";
		}
		cout << endl;
	}

	return 0;
}
