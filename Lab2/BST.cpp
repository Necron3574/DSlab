#include<iostream>
using namespace std;

class treenode{
public:
	int data;
	treenode* lc;
	treenode* rc;
};


treenode* rec_insert(treenode* root,int x){
	if(root==NULL){
		root = new treenode();
		root->data = x;
		root->lc = NULL;
		root->rc = NULL;
		return root;
	}
	else{
		if(x>root->data)
			root->rc = rec_insert(root->rc,x);
		else
			root->lc = rec_insert(root->lc,x);
		return root;
	}
}
void insert(treenode* root){
	int x;
	cout << "Enter data\n";
	cin >> x;	
	if(root == NULL){
		root ->data = x;
		root->rc = NULL;
		root->lc = NULL;
	}	
	else{
		treenode* prev = new treenode();
		while(root){
			if(x>root->data){
				prev = root;
				root = root->rc;
			}
			else if(x<root->data){
				prev = root;
				root = root->lc;
			}
			else{
				cout<<"Element already in BST\n";
				break;
			}
		}
		treenode* temp = new treenode();
		temp ->data =x;
		temp->rc = NULL;
		temp->lc = NULL;
		if(x>prev->data)
			prev->rc= temp;
		else
			prev->lc= temp;
	}
}
//Still need to add delete for node with both lc and rc != null
treenode* deletenode(treenode* root,int ele){
	treenode* cur = root;
	treenode* prev = NULL;
	while(cur->data!= ele){
		prev = cur;
		if(ele>cur->data)
			cur = cur->rc;
		else if(ele<cur->data)
			cur = cur->lc;	
	}
	treenode* childstore = new treenode;
	if(cur -> lc == NULL){
		childstore = cur->rc;	
	}
	else if(cur->rc == NULL){
		childstore = cur->lc;
	}
	else{
		treenode* insuc = cur->rc;
		while(insuc->lc!=NULL){
			insuc = insuc->lc;
		}
		insuc->lc = cur->lc;
		childstore = cur->rc;
	}
	delete cur;
	if(prev==NULL){
		root = childstore;
		return root;
	}
	else{
		if(prev->rc==cur){
			prev->rc = childstore;
			return root;
		}
		else{
			prev->lc = childstore;
			return root;
		}
	}
}

void inorder(treenode* root){
	if(root!=NULL){
        inorder(root->lc);
        cout<<root->data<<" ";
        inorder(root->rc);
    }
}

int main(){
	int choice = 0;
	int x;
	treenode* ournode = NULL;
	while(choice != 4){
		cout << "Menu\n";
		cout<< "1.Insert\n";
		cout << "2.Display\n";
		cout << "3.Delete\n";
		cout << "4.Exit\n";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Insert data\n";
				cin >> x;
				ournode = rec_insert(ournode,x);
				break;
			case 2:
				cout << "Displaying tree\n";
				inorder(ournode);
				cout << "\n";
				break;
			case 3:
				cout<< "Enter element to delete\n";
				cin >> x;
				ournode = deletenode(ournode,x);
				break;
			case 4:
				cout << "Exiting.";
				break;
			default:
				cout<< "Enter 1,2,3 or 4 only\n";
		}	
	}
	return 0;
}
