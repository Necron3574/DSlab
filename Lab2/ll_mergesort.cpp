#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node *link;
};
class sll{
public:
    Node *tail;
    Node *head;
    sll(){
        head = NULL;
    }
    void create();
    void display();
    void insertfront(int ele);
};

void sll::create(){
    int x;
    Node *cur,*prev=NULL;
    cout << "Enter data.\nEnter -1 to exit.\n";
    cin >> x;
    while(x != -1){
        Node *cur = new Node;
        cur -> data = x;
        cur -> link = NULL;
        if(prev == NULL)
            head = cur;
        else
            prev -> link = cur;
        prev = cur;
        cin >> x;
    }
    tail = prev;
}

void sll::display(){
    Node *temp;
    temp = head;
    while(temp->link!=NULL){
        cout <<temp -> data << ",";
        temp = temp -> link;
    }
    cout << temp -> data;
    cout << "\n";
}

void sll::insertfront(int ele){
    Node *temp = new Node;
    temp -> data = ele;
    temp -> link = head;
    head = temp;
}

void Mergesort(Node* a,Node* b){
	sll c;
	while(a!= NULL && b!= NULL){
		if(a-> data > b->data){
			c.insertfront(a -> data);
			a = a-> link;
		}
		else{
			c.insertfront(b -> data);
			b = b-> link;
		}	
	}
	while(a){
		c.insertfront(a->data);
		a = a -> link;
	}
	while(b){
		c.insertfront(b->data);
		b = b -> link;
	}
	c.display();	
}
int main(){
	sll a,b;
	cout << "Enter elements of list a\n";
	a.create();
	cout << "Enter elements of list b\n";
	b.create();
	cout << "The merged, sorted list is \n";
	Mergesort(a.head,b.head);
return 0;
}
