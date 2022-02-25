// Problem: You are given a tree, with each node having either 0 or 1 as value.
// two nodes (n1, n2) are called diverse neighbours if value(n1)!=value(n2) and there is no node n3 between them such that
// value(n3)==value(n2). You need to find sum of distance between each node and it's diverse neighbours. 

#include<iostream>
#include<vector>
using namespace std;

// helper function to calculate dist and subtr arrays.
void dfs1(vector<vector<int>> tree, vector<int>state, vector<int>&dist, vector<int>&subtr, int node, int parent){
	// starting with node 0, we will traverse in dfs manner.
	for(int child: tree[node]){
		if(child==parent) continue;
		dfs1(tree, state, dist, subtr, child, node);
		// if state of parent and child is same, then parent will have same diverse neighbours as child have in child's subtree.
		if(state[child]==state[node]){
			subtr[node] = subtr[node] + subtr[child];
			// as for each neighbour(in child's subtree) we need to add 1 in dist of parent, we will simply add no. of
			// neighbours in child's subtree( 1* neighbours in subtree).
			dist[node] = dist[node] + dist[child] + subtr[child]; 
		} else {
			// if both child and parent have different states, then we will increase number of diverse neighbours
			// in parent's subtr and dist will also increase by 1.
			subtr[node]++;
			dist[node]++;
		}
	}
	return;
}

// helper function to calculate total array.
void dfs2(vector<vector<int>> tree, vector<int>state, vector<int>&total, vector<int>subtr, int node, int parent){
	// for root node(parent=-1) number of total neighbours is same as number of neighbours present in it's subtree.
	if(parent==-1) total[node] = subtr[node];
	// traversing in dfs manner.
	for(int child: tree[node]){
		if(child==parent) continue;	// to avoid cycle.
		// if state of child and parent are same, then child will have same neighbours as parent.
		if(state[node]==state[child]){
			total[child] = total[node];
		} else {
			// if states of child and parent are different then they both are neighbours of each other.
			// total neighbours = neighbours in subtr + 1(for parent).
			total[child] = subtr[child] + 1;
		}
		dfs2(tree, state, total, subtr, child, node);
	}
	return;
}

// function to get final answer for the problem.
void dfs3(vector<vector<int>> tree, vector<int>state, vector<int>&ans, vector<int>total, vector<int>dist, vector<int>subtr, int node, int parent){
	// for root node(parent=-1) subtree contains all the neighbours and dist is the answer only, as
	// dist is storing sum of distance of neighbours.
	if(parent==-1) ans[node] = dist[node];
	// traversing in DFS manner.
	for(int child: tree[node]){
		if(child==parent) continue;	// to avoid loop.
		// if state of both child and parent are same...
		if(state[child]==state[node]){
			// ans[child] = ans[parent] - subtr[child]	-- ans of parent will have 1 unit more of distance then child
			// hence we are removing 1 unit for each neighbour in subtree of child.
			// + total no. of neighbours - neighbours in subtree -- these neighbours are connected with child through parents and hence
			// we need to add 1 unit for each of them , this term will do the same.
			// neighbours in first term(subtract) ---- Child ---- Parent ---- neighbours in second trem(add).
			ans[child] = ans[node] + total[child] - (2*subtr[child]);
		} else {
			// if satates of child and parent are different, ans[child] = distance sum for neighbours in subtree + 1(for parent).
			ans[child] = dist[child] + 1;
		}
		dfs3(tree, state, ans, total, dist, subtr, child, node);
	}
}

// driver function.
vector<int> getDistSum(int n, vector<vector<int>> tree, vector<int>state){
	vector<int>total(n, 0), ans(n, 0), dist(n,0), subtr(n, 0);
	// total: total[i] shows how many total diverse elements of a node i are there.
	// subtr: subtr[i] shows how many diverse neighbours of node i are present in subtree of node i.
	// dist: dist[i] shows sum of distance from diverse neighbours of node i, but this neighbours are present in subtree of node i.
	// ans: ans[i] shows the main answer, which is sum of distance from node i to it's all diverse neighbours.
	dfs1(tree, state, dist, subtr, 0, -1);
	dfs2(tree, state, total, subtr, 0, -1);
	dfs3(tree, state, ans, total, dist, subtr, 0, -1);
	return ans;
}

int main(){
	int n=7;	// number of nodes.
	// adjacency list for tree.
	vector<vector<int>> tree={
		{1, 4},
		{0, 2, 3},
		{1},
		{1, 6},
		{0, 5},
		{4},
		{3}
	};
	// state of each node, either 0 or 1.
	vector<int>state = {0, 0, 1, 1, 0, 1, 1};
	vector<int> ans = getDistSum(n, tree, state);
	for(int i: ans){
		cout << i << " ";
	}
	return 0;
}