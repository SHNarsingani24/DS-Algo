#include<vector>
using namespace std;

template<typename T>
class Stack{
	vector<T> arr;
public:
	void push(T d){
		arr.push_back(d);
	}
	void pop(){
		arr.pop_back();
	}
	T top(){
		return arr[arr.size()-1];
	}
	bool is_empty(){
		return arr.size()==0;
	}
	void print(){
		for(int i = arr.size() -1; i >= 0; i--){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};