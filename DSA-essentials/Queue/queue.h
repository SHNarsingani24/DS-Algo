using namespace std;


template<typename T>
class Queue{
	T *queue;
	int ms, cs, front, rear;

public:
	Queue(int size=5): ms(size){
		queue = new int [ms];
		cs = 0;
		front = 0;
		rear = size - 1;
	}

	bool full(){
		return cs == ms;
	}
	bool empty(){
		return cs == 0;
	}

	void push(T data){
		if(full()) return;
		rear = (rear+1)%ms;
		queue[rear] = data;
		cs++;
	}

	void pop(){
		if(empty()) return;
		front = (front + 1)%ms;
		cs--;
	}

	T get_front(){
		return queue[front];
	}

	void print(){
		for(int i = front; i <= cs; i++){
			cout << queue[i%ms] <<  " ";
		}
		cout << endl;
	}

	~Queue(){
		delete [] queue;
	}
};
