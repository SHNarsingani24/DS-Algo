#include<bits/stdc++.h>
using namespace std;

class Product{
	// private by default.
	int id;
	char *full_name;
	int MRP;
	int selling_price;
public:
	// Constructor.
	Product(){
		cout << "When no arguments are passed!" << endl;
	}
	// Constructor Overloading.
	Product(int id, char *n, int MRP, int selling_price){
		this -> id = id;
		full_name = new char[strlen(n)];
		strcpy(full_name, n);
		this -> MRP = MRP;
		this -> selling_price = selling_price;
	}
	// Copy Constructor
	Product(Product &X){	// this should be always passed by reference, 
							// as when argument is passed to any function a copy is created of that argument variable, 
							// but here the function itself is making copies.
		id = X.id;
		full_name = new char[strlen(X.full_name)]; // these 2 lines will create a deep copy of given object.
		strcpy(full_name, X.full_name);
		MRP = X.MRP;
		selling_price = X.selling_price;
	}
	// int MRP;
	// int selling_price;
	// Instead of using public attributes, we can use getters and setters.
	// Setters
	void setMRP(int price){
		MRP = price;
		return;
	}
	void setSellingPrice(int price){
		if(price < MRP){
			selling_price = price;
		} else {
			selling_price = MRP;
		}
		return;
	}
	void set_name(char *n){
		strcpy(full_name, n);
	}

	// Getters
	int getMRP(){
		return MRP;
	}
	int getSellingPrice(){
		return selling_price;
	}
	void get_details(){
		cout << "id: " << id << endl;
		cout << "full_name: " << full_name << endl;
		cout << "MRP: " << MRP << endl;
		cout << "Selling Price: " << selling_price << endl;
	}

	// operator overloading.
	void operator=(Product &X){	// custom copy assignment operator.
		id = X.id;
		full_name = new char[strlen(X.full_name)]; // these 2 lines will create a deep copy of given object.
		strcpy(full_name, X.full_name);
		MRP = X.MRP;
		selling_price = X.selling_price;
	}
};

int main(){
	// Product camera; -- constructor without arguments will be invoked automatically.
	// public properties can be accessed here.
	// cout << camera.MRP << endl;
	// cout << camera.selling_price << endl;
	// these will give 0s, as attributes are not set.

	// can't do this as attributes are private now.
	// camera.MRP = 1200;
	// camera.selling_price = 1149;

	// camera.setMRP(1200);
	// camera.setSellingPrice(1149);

	Product camera(937, "Sony Pixar", 12000, 10000);
	Product old_cam = camera;
	Product cam;	// constructor called already.

	old_cam.set_name("Sony P");	// if we are using default copy constructor, this line will change name property of both camera and old_cam.
								// This is known as Shallow Copy. If we used custom copy constructor, only name of old_cam will change. It is known as Deep Copy.
	// cout << camera.getMRP() << endl;
	// cout << camera.getSellingPrice() << endl;

	cam = old_cam; // Here comes the role of copy assignment operator. The default one will create a shallow copy.
	cam.set_name("Sony X"); // this change won't be reflected in old_cam.
	camera.get_details();
	old_cam.get_details();
	cam.get_details();

	// private properties can't be accessed here.
	// cout << camera.full_name << endl;
    return 0;
}