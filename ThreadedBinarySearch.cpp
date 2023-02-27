#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *llink, *rlink;
	Node *dummyNode;
	bool ltag, rtag;
	
	Node(int data):data(data),llink(dummyNode),rlink(dummyNode),ltag(true),rtag(true){}
};

class BinaryTree{
private:
	Node *root = nullptr;
public:
	void setRoot(int data){
		Node *newNode = new Node(data);
		root = newNode;
		root->ltag = false;
		root->rtag = false;
	}
	
	Node *getRoot(){
		return root;
	}
	
	void insert(){
		int data;
		cout<<"Enter the data: ";cin>>data;
		Node *newNode = new Node(data);
		
		if(root==nullptr){
			setRoot(data);
			return;
		}
		
		Node *parent, *current=root;
		while(current != nullptr){
			parent = current;
			if(current->data>newNode->data){
				current = current->llink;
			}else{
				current = current->rlink;
			}
		}
		
		if(newNode->data<parent->data){
			parent->llink = newNode;
			parent->ltag = false;
		}else{
			parent->rlink = newNode;
			parent->rtag = true;
		}
	}
	
	void inorder(Node* current){
		if(current!=nullptr){
			inorder(current->llink);
			Node* temp = current;
			inorder(current->rlink);
		}
	}
};

int main(){
	BinaryTree tree;
	tree.insert();
	tree.insert();
	cout<<"The list is:"<<endl;
	tree.inorder(tree.getRoot());
}
