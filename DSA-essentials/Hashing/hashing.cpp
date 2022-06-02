#include<iostream>
#include "hashing.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main(){

	Hashtable<int> h;

	h.insert("mango", 100);
	h.insert("orange", 110);
	h.insert("banana", 115);
	h.insert("chicku", 130);
	h.insert("pineapple", 150);
	h["watermelon"] = 130;

	h.print();

	cout << "---------------------------------------------------------------------------" << endl;

	// cout << h["watermelon"] << endl;
	h.erase("watermelon");
	h["pineapple"] += 10;
	// cout << h["pineapple"] << endl;

	// cout << "---------------------------------------------------------------------------" << endl;
	h.print();

	// string fruit;
	// cin >> fruit;

	// int *price = h.search(fruit);
	// if(price!=NULL){
	// 	cout << "Price of " << fruit << " is " << *price << "." << endl;
	// } else {
	// 	cout << fruit << " is not available." << endl;
	// }

	// Note: operations on unordered_map will cost on average O(1).
	// However, map will cost O(LogN) time.

	// things won't be sorted in unordered_map.
	unordered_map<string, int> ages;
	// inserting element -- Average Case time complexity O(1).
	ages["Sagar"] = 20;
	ages["Kavi"] = 27;
	ages["Varsha"] = 25;
	ages["Dhruvil"] = 19;

	// deleting element -- Average Case time complexity O(1).
	ages.erase("Dhruvil");

	// traversing through all the pairs stored in map.
	for(pair<string, int> x: ages){
		cout << x.first << " " << x.second << endl;
	}

	string name;
	cin >> name;

	// searching element -- Average Case time complexity O(1).
	if(ages.find(name)!=ages.end()){
		cout << name << " is " << ages[name] << " years old." << endl;
	} else {
		cout << "NO INFORMATION" << endl;
	}


	// similar to unordered_map, no order preserved.
	// inserting element -- O(1) at average.
	unordered_set<int> nums;
	nums.insert(1);
	nums.insert(5);
	nums.insert(7);
	nums.insert(3);

	// deleting element -- O(1) at average.
	nums.erase(3);

	// searching through unordered_set, on average takes only O(1) time.
	// which is much better compared to arrays.
	int num;
	cin >> num;
	if(nums.find(num)!=nums.end()){
		cout << "present" << endl;
	} else {
		cout << "absent" << endl;
	}

	// traversing through unordered_set.
	for(int x: nums){
		cout << x << " ";
	}	
	return 0;
}