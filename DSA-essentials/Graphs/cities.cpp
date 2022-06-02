// this program will show an alternative way to make a graph.
// this time we will make graph of strings instead of integers.

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

class Graph;

// class for each node of graph.
class Node{
	string city;
	list<string> nbr;	// nbr stands for neighbours, this list will store neighbours of particular node!

public:
	// constructor.
	Node(string name){
		city = name;
	}

	friend class Graph;
};

class Graph{
	unordered_map<string, Node*> address;	// will store city and city node's address!
public:
	// constructor: wil expect vector containing names of cities, and then it will create node for each city
	// and at last city name and city node's address wil be mapped!
	Graph(vector<string>cities){
		for(auto city: cities){
			address[city] = new Node(city);
		}
	}

	// method to add edge between two nodes of graph.
	void addEdge(string x, string y, bool undir=true){
		// adding y in neighbour list of x.
		address[x]->nbr.push_back(y);
		// if graph is undirectional, we have to add x in y's neighbour list.
		if(undir){
			address[y]->nbr.push_back(x);
		}
		return;
	}

	// method to print adjacency matrix of this graph.
	void printAdjList(){
		// traversing through the map, will return pair<string, Node*>
		for(auto city: address){
			string name = city.first;
			Node *adr = city.second;

			cout << name << " : ";
			for(auto n: adr->nbr){
				cout << n << " ";
			}
			cout << endl;
		}
	}
};

int main(){
	vector<string> cities = {"London", "New York", "Mumbai", "Ahmedabad"};
	Graph g(cities);

	g.addEdge("London", "Ahmedabad", false);
	g.addEdge("Mumbai", "Ahmedabad");
	g.addEdge("New York", "Mumbai", false);
	g.addEdge("Ahmedabad", "New York", false);

	g.printAdjList();
	
	return 0;
}
