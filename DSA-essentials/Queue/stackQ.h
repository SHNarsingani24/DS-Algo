// Building stack using two queues, underneath.

#include<queue>	// queue data structure from STL.
using namespace std;

template<typename T>
class Stack{
	queue<T> q1, q2;

public:
	// if stack is empty.
	bool empty(){
		return q1.empty() and q2.empty();
	}
	// pushing new element in the stack - O(1).
	void push(T d){
		// push new element in the non-empty queue.
		if(q1.empty()){
			q2.push(d);
		} else {
			q1.push(d);
		}
		return;
	}

	// Popping the element from the stack - O(N).
	void pop(){
		if(q1.empty()){
			while(q2.size() > 1){
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}else if(q2.empty()){
			while(q1.size() > 1){
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
	}

	// Getting the top most element of the stack - O(N).
	T top(){
		T ans;
		if(q1.empty()){
			while(!q2.empty()){
				T top = q2.front();
				q1.push(q2.front());
				q2.pop();
				
				// when we reach to the last element of queue, it will be basically top element of stack.
				if(q2.empty()){
					return top;
				}
			}
			
		}else if(q2.empty()){
			while(!q1.empty()){
				T top = q1.front();
				q2.push(q1.front());
				q1.pop();

				// when we reach to the last element of queue, it will be basically top element of stack.
				if(q1.empty()){
					return top;
				}
			}
		}
		return ans;
	}

	// printing the stack, however this will empty the stack.
	void print(){
		while(!empty()){
			cout << top() << " ";
			pop();
		}
		cout << endl;
	}
};