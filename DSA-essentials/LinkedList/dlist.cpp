#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        Node *next, *prev;
        int data;

        Node(int d){
            data = d;
            next = prev = NULL;
        }

        ~Node(){
            if(prev)
                delete prev;
            if(next)
                delete next;
        }
};


class List{
    public:
        Node *root, *tail;
    
        List(){
            root = NULL;
            tail = NULL;
        }

        List(int r){
            root = new Node(r);
            tail = root;
        }

        List(vector<int> nodes){
            root = new Node(nodes[0]);
            for(int i=1; i<nodes.size(); i++){
                Node *tmp = root;
                while(tmp->next){
                    tmp = tmp->next;
                }
                tmp->next = new Node(nodes[i]);
                tmp->next->prev = tmp;
                tail = tmp->next;
            }
        }

        void addNode(int node){
            Node *tmp = root;
            while(tmp->next){
                tmp = tmp->next;
            }
            tmp->next = new Node(node);
            tmp->next->prev = tmp;
            tail = tmp->next;
        }

        void print(){
            Node *tmp = root;
            while(tmp->next){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << tmp->data << endl;
        }

        void revPrint(){
            Node *tmp = tail;

            while(tmp->prev){
                cout << tmp->data << " ";
                tmp = tmp->prev;
            }

            cout << tmp->data << endl;
        }
};

int main(){
    List dll = List({2, 4, 1, 5});
    dll.print();
    dll.revPrint();

    int n;
    cout << "Enter value for new node: ";
    cin >> n;

    dll.addNode(n);
    dll.print();
    dll.revPrint();
    
    return 0;
}