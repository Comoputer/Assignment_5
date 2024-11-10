#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = nullptr;
    }
};

class Stack{
    public:
        int top;
        Node** arr;
        int capacity;

        Stack(int s){
            capacity = s;
            top = -1;
            arr = new Node*[capacity];  
        }

        bool isEmpty(){
            return top == -1;
        }

        void push(Node* k){
            if(top == capacity - 1){
                cout << "Stack Overflow";
            } else {
                arr[++top] = k;  
            }
        }

        Node* pop(){
            if(isEmpty()){
                cout << "Stack Underflow";
                return nullptr;
            } else {
                return arr[top--]; 
            }
        }

        ~Stack(){
            delete[] arr;
        }
};

class BST{
    Node* root;
    public:
        BST(){
            root = nullptr;
        }

        void insertNode(int data){
            Node* newnode = new Node(data);
            if(root == nullptr){
                root = newnode;
                return;
            }
            Node* current = root;

            while(true){
                if(data < current->data){
                    if(current->left == nullptr){
                        current->left = newnode;
                        return;
                    }
                    current = current->left;
                } else if(data > current->data){
                    if(current->right == nullptr){
                        current->right = newnode;
                        return;
                    }
                    current = current->right;
                } else {
                    delete newnode; 
                    return;
                }
            }
        }

        void inorder(){
            Node* current = root;
            if(current == nullptr){  
                cout << "Tree is empty";
                return;
            }
            Stack s(10);
            while(current != nullptr || !s.isEmpty()){
                while(current != nullptr){
                    s.push(current);
                    current = current->left;
                }
                current = s.pop();
                cout << current->data << " ";
                current = current->right;
            }
        }

        void preorder(){
            if(root == nullptr){  
                cout << "Tree is Empty";
                return;
            }

            Stack s(10);
            s.push(root);
            while(!s.isEmpty()){
                Node* current = s.pop();
                cout << current->data << " ";
                if(current->right){
                    s.push(current->right);
                }
                if(current->left){
                    s.push(current->left);
                }
            }
        }

        void Search(int data){
            if(root == nullptr){
                cout << "No tree present";
                return;
            }
            Node* current = root;
            while(current != nullptr){
                if(data < current->data){
                    current = current->left;
                } else if(data > current->data){
                    current = current->right;
                } else if(current->data == data){
                    cout << "Element found";
                    return;
                }
            }
            cout << "No search node exists in the tree";
        }

        void postOrder(){
            if(root == nullptr){  
                return;
            }
            Stack s(10), s1(10);
            s.push(root);
            while(!s.isEmpty()){
                Node* current = s.pop();
                s1.push(current);

                if(current->left){
                    s.push(current->left);
                }
                if(current->right){
                    s.push(current->right);
                }
            }

            while(!s1.isEmpty()){
                Node* d = s1.pop();
                cout << d->data << " ";
            }
        }
};

int main(){
    BST tree;
    int elements[] = {50, 30, 20, 40, 70, 60, 80};

    for (int key = 0; key < 7; key++) {
        tree.insertNode(elements[key]);
    }

    cout << "In-order traversal of the BST: ";
    tree.inorder();
    cout << endl;
    cout<<"Pre-order Traversal of the BST: ";
    tree.preorder();
    cout<<endl;

    cout<<"Post-order Traversal of the BST: ";
    tree.postOrder();
    cout<<endl;
    return 0;
}