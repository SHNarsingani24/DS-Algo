#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

bool canVisitRooms(vector<vector<int>> rooms){
	int n = rooms.size();
	unordered_set<int> unvisited;

	for(int i = 0; i < n; i++){
		unvisited.insert(i);
	}

	queue<int> q;
	q.push(0);

	// traversing in BFS manner.
	while(!q.empty()){
		int f = q.front();
		q.pop();
		unvisited.erase(f);

		for(int i: rooms[f]){
			if(unvisited.find(i)!=unvisited.end()){
				q.push(i);
			}
		}
	}

	return (!unvisited.size());
}

int main(){
	vector<vector<int>> rooms = {{1}, {2}, {}, {}};

	cout << canVisitRooms(rooms) << endl;
	return 0;
}