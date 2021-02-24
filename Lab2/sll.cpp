#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* link;
};
class sll{
public:
	Node* head;
	sll(){
		head = NULL;
	}
	void create(){
		Node* cur;
		Node* prev = NULL;
		int temp;
		cout << "Enter data to be put in linked list.\n(-1 to exit)\n";
		cin >> temp;
		while(temp!=-1){
			cur = new Node;
			cur ->data = temp;
			cur -> link = NULL;
			if(head == NULL)
				head = cur;
			else{
				prev ->link = cur;
			}
			prev = cur;
			cin >> temp;
		}
	}
	void display(){
		cout << "The linked list is\n";
		Node* temp = head;
		while(temp!= NULL){
			cout << temp->data << " ";
			temp = temp->link;
		}
		cout << endl;
	}
	void insert_beginning(int ele){
		Node* temp = new Node;
		temp -> data = ele;
		temp -> link = head;
		head = temp;
	}
	void insert_end(int ele){
		Node* cur = new Node;
		cur -> data = ele;
		cur -> link = NULL;
		Node* temp = head;
		while(temp->link!=NULL)
			temp = temp->link;
		temp ->link = cur;
	}
	void insertbefore(int target,int ele){
		Node* cur = new Node;
		cur ->data = ele;
		cur ->link = NULL;
		Node* temp = head;
		if(temp->data == ele){
			cur ->link = temp;
			head = cur;
		}
		else{
		while(temp->link->data!=target)
			temp = temp->link;
		cur ->link = temp->link;
		temp ->link = cur;
		}
	}
	void insertafter(int target,int ele){
		Node*cur = new Node;
		cur -> data = ele;
		cur ->link = NULL;
		Node* temp = head;
		while(temp->data!= target)
			temp = temp->link;
		if(temp->link == NULL)
			temp->link = cur;
		else{
			cur ->link = temp->link;
			temp->link = cur;
			}
	}
	void deleteElement(int ele){
		Node* cur = head;
		Node* prev = NULL;
		if(head->data == ele){
			head = cur ->link;
			delete cur;
		}
		else{
			while(cur->data!=ele){
				prev = cur;
				cur = cur->link;
			}
			prev->link = cur->link;
			delete cur;
		}
	}
};
int main(){
	sll l;
	l.create();
	cout << endl;
	int choice = -1;
	int ele,target;
	while(choice !=7){
		cout << "Enter\n1.Insert element in the beginning of the list\n2.Insert element at the end of the list\n";
		cout << "3.Insert element before another element in existing list\n4.Insert element after another element in existing list\n";
		cout << "5.Delete a given element from the list\n6.Print the list\n7.Exit\n";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Enter element you wish to insert:\n";
				cin >>ele;
				l.insert_beginning(ele);
				break;
			case 2:
				cout << "Enter element you wish to insert:\n";
				cin >>ele;
				l.insert_end(ele);
				break;
			case 3:
				cout << "Enter element you wish to insert:\n";
				cin >>ele;
				cout << "Insert element before which you wanna insert:\n";
				cin >> target;
				l.insertbefore(target,ele);
				break;
			case 4:
				cout << "Enter element you wish to insert:\n";
				cin >>ele;
				cout << "Insert element after which you wanna insert:\n";
				cin >> target;
				l.insertafter(target,ele);
				break;
			case 5:
				cout << "Enter element you wish to delete\n";
				cin >> ele;
				l.deleteElement(ele);
				break;
			case 6:
				l.display();
				break;
			case 7:
				cout << "Exiting . . . ";
		}
}
	return 0;
}
