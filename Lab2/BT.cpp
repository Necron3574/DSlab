#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Tnode{
	public:
	int data;
	Tnode* lc;
	Tnode* rc;
};

class BT{
	public:
	Tnode* root;
	
	BT(){
		root = NULL;
	}
	
		Tnode* rcreate();
		Tnode* dcreate();
		void inorder(Tnode* root);
		void postorder(Tnode* root);
		void preorder(Tnode* root);
		
};
Tnode* BT::rcreate(){
	int x;
	cout << "Enter data(-1 to exit)\n";
	cin >>x;
	if(x==-1)
		return NULL;
	else{
	Tnode* p = new Tnode;
	p-> data = x;
	cout << "Enter left child for " << x << endl;
	p -> lc = rcreate();
	cout << "Enter right child for " << x << endl;
	p -> rc = rcreate();
	return p;
	}
}
void BT::inorder(Tnode* root){     //left root right
	if(root){
		inorder(root->lc);
		cout << root -> data;
		inorder(root->rc);
	}
}
void BT::postorder(Tnode* root){  // left right root
	if(root){
		inorder(root->lc);
		inorder(root->rc);
		cout << root ->data;
	}
} 
void BT::preorder(Tnode* root){   // root left right
	if(root){
		cout << root -> data;
		inorder(root -> lc);
		inorder(root -> rc);
	}
}

int main(){
	BT Tree;
	Tnode* root = Tree.rcreate();
	Tree.inorder(root);
	return 0;
}
