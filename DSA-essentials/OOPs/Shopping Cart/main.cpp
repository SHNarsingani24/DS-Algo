#include<iostream>
#include "datamodel.h"
#include<vector>
#include<string>
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(2, "mango", 16),
    Product(3, "guava", 36),
    Product(4, "banana", 56),
    Product(5, "strawberray", 29),
    Product(6, "pineapple", 20)
};

void showProducts(){
    string productList = "";

    cout << endl << "Available Products" << endl << endl;

    for(auto p: allProducts){
        productList.append(p.getProduct());
    }
    cout << productList << endl;
    cout << "-----------------------------" << endl;
}

Product* chooseProduct(){
    string prod;
    cout << "\nSelect a product to add it in your cart" << endl;
    cin >> prod;
    for(int i = 0; i < allProducts.size(); i++){
        if(allProducts[i].getShortName() == prod){
            return &allProducts[i];
        }
    }
    cout << "Product not available." << endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        cout << "You don't have any items in your cart.";
        return false;
    }

    int total = cart.getTotal();
    int paid;

    cout << "Pay in Cash: ";
    cin >> paid;

    if(paid >= total){
        cout << "Change: " << paid - total << endl;
        cout << "Thank you for shopping! Visit Again!";
        return true;
    } else {
        cout << "Not enough cash!" << endl;
        return false;
    }
}

int main(){
    char action;
    Cart cart;
    while(true){
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;

        if(action=='a'){
            // show products + let user choose one + add a choosen one into the cart
            showProducts();
            Product *p = chooseProduct();
            cart.addItem(*p);
            cout << "\nAdded to the cart " + p->getProduct();
            

        } else if(action=='v'){
            //show items added to a cart.
            cout << "------------------------------" << endl;
            cout << cart.viewCart();
            cout << "------------------------------" << endl;
        } else {
            // checkout
            cout << cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }

    }
    return 0;
}