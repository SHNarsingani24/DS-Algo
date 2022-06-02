// topics in this code: Pointers, Refference variables, address of operator, derefferencing operator, dynamic memory allocation.

#include<bits/stdc++.h>
using namespace std;

// taking the refference variable. not returning anything.
void increment(int &x, int i){
	x = x + i;
}

// taking the pointer variable, not returning anything.
void decrement(int* x, int i){
	*x = *x - i; // here it is dereffrencing operator.
}

// Dynamic Memory allocation example : store first i natural numbers in dynamic array and print that.
void print_numbers(int i){
	int* arr = new int[i];  // creating dynamic array(means at run time, i can be user input too).
	// for dynamic variable, use 'new int' only(without [i]).
	for(int j = 1; j <= i; j++){
		arr[j-1] = j;  // *(arr+j-1) can be used too, where * is derefferencing operator.
	}
	for(int j = 0; j < i; j++){
		cout << arr[j] << " ";
	}
	cout << endl;

	// for dynamic variable(not array) use delete var_name only(without []).
	delete [] arr; // to free the heap memory reserved for arr, other wise memory leak occurs.
	// Memory Leak : if we return without freeing the heap memory, pointer pointing to that particular memory chunk will be destroyed.
	// Hence that memory chunk can't be accessed again and will become useless. This is called Memory Leak.
	return;
}

// creating 2D array using dynamic memory allocation.
int** create2Darray(int rows, int cols){
	// ----------------------------Creation--------------------------------------//
	// array of pointers hence ** is used.
	int** arr = new int* [rows]; // each pointer in this array will point to the row of 2D array.
	for(int i = 0; i < rows; i++){
		arr[i] = new int[cols]; 
		// arr[i] is expecting address, new int[cols] will create block of integers(cols number of integers).
		// and give the address to arr[i].
	}

	// ----------------------------Allocation--------------------------------------//
	int val = 1;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			arr[i][j] = val++;
		}
	}

	// note that we are not deleting the array, but passing the pointer to the main and hence the array is still accessible.
	return arr;
}

int main(){
        
    int x = 24; // normal integer variable.
    int* xptr = &x;  //  pointer variable used to store the address of variable, &x will give address of x.
    int** xxptr = &xptr; // storing the adress of pointer to x in another pointer.

    // xxptr => xptr(address) xptr => x(address).
    cout << x << " " << &x << " " << xptr << " " << &xptr << " " << xxptr << " " << endl;

    // Derefference Variable.
    int y = *xptr;  // xptr has address of x, which has 24 value. we can dereffrence a variable using * before pointer variable.
    cout << y << " " << &y << endl;

    // Refference Variable.
    int &z = y; // giving an alias to y varible. y and z both are the name of same address in memory.
    // If we change y then z will also change and vice versa.
    // initialization is mandatory. we can't just define it without giving a value (like int &z; - will give error).
    cout << z << " " << &z << endl;

    increment(x, 10);  // just calling, not storing anything.
    cout << x << endl; // change will be reflected here, as we are using pass by refference variable.

    decrement(&x, 10); // just calling WITH ADDRESS, not storing anything.
    cout << x << endl; // change will be reflected here, as we are passing by refference using the pointer variable.

    print_numbers(10); // Dynamic Memory Allocation Example.

    // Creating 2D array using Dynamic Memory Allocation.
    int rows, cols;
    cin >> rows >> cols;

    int** arr = create2Darray(rows, cols);

    for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	delete [] arr;
	
    return 0;
}