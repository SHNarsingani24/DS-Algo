#include<iostream>
#include<vector>
using namespace std;

int getStar(vector<vector<int>> graph){
	pair<int, int> first_edge = {graph[0][0], graph[0][1]};
	pair<int, int> second_edge = {graph[1][0], graph[1][1]};

	// returning the common node in first two edges..
	if(first_edge.first == second_edge.first  or  first_edge.first == second_edge.second){
		return first_edge.first;
	}

	return first_edge.second;
}


int main(){
	vector<vector<int>> graph = {{1, 2}, {2, 3}, {4, 2}};
	cout << getStar(graph);
	return 0;
}
