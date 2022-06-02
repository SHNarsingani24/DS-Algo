#include<bits/stdc++.h>
using namespace std;

// We can put this whole class+template defination in diffrent file with '.h' extention.
// We can import it using ' include "file_name.h" '.

template<typename T> // using this, we can create vector of different data types
// Vector Data Structure Implementation.
class Vector{
	T* arr;
	int cs, ms; // cs- current size, ms- max size

	public:
		Vector(){
			cs = 0, ms = 1;
			arr = new int[ms];
		}

		void push_back(const T d){
			if(ms == cs){
				int* old_arr = arr;
				ms = ms * 2;
				arr = new int[ms];

				for(int i = 0; i < cs; i++){
					arr[i] = old_arr[i];
				}

				delete [] old_arr;
			}

			arr[cs++] = d;
		}

		void pop_back(){
			if(cs > 0){
				cs--;
			}
		}

		// const functions are those in which no data attributes are modified.
		// similarly const variables are those who are not modified in particular block of function.
		// It is a good practice to make functions & variables constant as it helps in debugging.

		T front() const{
			return arr[0];
		}

		T back() const{
			return arr[cs-1];
		}

		T at(const int i) const{
			return arr[i];
		}

		int size() const{
			return cs;
		}

		int capacity() const{
			return ms;
		}

		bool isEmpty() const{
			return cs==0;
		}

		// OPERATOR OVERLOADING.
		T operator [] (const int i) const{
			return arr[i];
		}

};

int main(){
        
    vector<int> v = {1, 2, 3, 4, 5}; // initializing with list.
    // vector<int> v(num_of_elements, value); - initializing with fill constructor.

    v.pop_back(); // last element will be removed.
    v.push_back(6); // adding element at the end of vector.

    // when the current capacity of vector is occupied then, 
    // vector will automatically double it's capacity(on the insertion of new element).
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    cout << v.front() << endl; // first element.
    cout << v.back() << endl;  // last element.
    // 2D vector.
    vector< vector<int> > arr = {
    	{1, 2, 3},
    	{4, 5, 6},  // Each row can be of different length, which is not possible in normal array.
    	{7, 8, 9}
    };

    // accessing all elements using for nested each loops. normal loops can be used too.
    for(vector<int> x: arr){
    	for(int y: x){
    		cout << y << " ";
    	}
    	cout << endl;
    }

    vector<int> v2 = {2, 3};

    vector<int>::iterator it = find(v.begin(), v.end(), 4); 
    // syntax : find(start(inc), end(exc), key) - returns iterator, if not found then v.end() is returned.
    cout << it-v.begin() << endl; // printing index, only 'it' will give error. need to substract base iterator.

    vector<int>:: iterator it1 = search(v.begin(), v.end(), v2.begin(), v2.end());
    // this will search if v2 exists in v and return the starting iterator or v.end() if not found.
    cout << it1 - v.begin() << endl; // printing index, only ot will give error. need to substract base iterator.

    // lower_bound(start, end, val): it finds the first element that is just lower than val and returns an iterator. 
    // upper_bound(start, end, val): it finds the first element that is just bigger than val and returns an iterator.

    Vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);

    v1.pop_back();

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

    cout << v1.front() << endl;
    cout << v1.back() << endl;

    for(int i = 0; i < v1.size(); i++){
    	cout << v1[i] << " ";
    	// cout << v1.at(i) << " ";
    }
    cout << endl;

    return 0;
}