#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Product{
    int id;
    string name;
    int price;

    public:
        Product(){};
        Product(int u_id, string name, int price){
            id = u_id;
            this -> name = name;
            this -> price = price;
        }

        string getProduct(){
            return name + " : Rs " + to_string(price) + "\n";
        }

        string getShortName(){
            return name.substr(0, 1);
        }

    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int qnt;

    public:
        Item(){};
        Item(Product p, int q): product(p), qnt(q){};

        int getTotalPrice(){
            return product.price*qnt;
        }

        string getItem(){
            return to_string(qnt) + " x " + product.name + " = Rs. " + to_string(getTotalPrice()) + "\n";
        }

    friend class Cart;
};

class Cart{
    unordered_map<int, Item> items;

    public:

        void addItem(Product p){
            if(items.count(p.id)==0){
                Item item(p, 1);
                items[p.id] = item;
            } else {
                items[p.id].qnt++;
            }
        }

        int getTotal(){
            int total = 0;
            for(auto itemPair: items){
                Item item = itemPair.second;
                total += item.getTotalPrice();
            }
            return total;
        }

        string viewCart(){
            if(items.empty()){
                return "Your Cart is empty!\n";
            }
            
            string itemList;
            int total = getTotal();

            for(auto itemPair: items){
                Item item = itemPair.second;
                itemList.append(item.getItem());
            }

            return itemList + "\nTotal Amount: Rs. " + to_string(total)+'\n';
        }

        bool isEmpty(){
            return items.empty();
        }

};