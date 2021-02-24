#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* front;
	Node* back;
};
class dll{
public:
	Node* head;
	Node* tail;
	dll(){
		head = NULL;
		tail = NULL;
	}
	void create();
	void display();
	void ins_beg(int x);
	void ins_end(int x);
	void deletefront();
	void deleteback();
	void insert_pos(int pos,int x);
	void search(int ele);	
	void deleteposition(int pos);
};
void dll::create(){
	Node* prev = new Node;
	int x;
	cout << "Enter the data\nEnter -1 to exit\n";
	cin >> x;
	while(x!=-1){
		Node* cur = new Node;
		cur -> data = x;
		cur -> front = NULL;
		cur -> back = NULL;
		if(head==NULL)
			head = cur;
		else{
			prev->front = cur;
			cur -> back = prev;
		}
		prev = cur;	
		cout << "Enter the data\nEnter -1 to exit\n";
		cin >> x;
	}
	tail = prev;
}
void dll::display(){
	Node* temp = head;
	cout << "The dll is\n";
	while(temp -> front != NULL){
		cout << temp-> data << " ";
		temp = temp -> front; 
	}
	cout << temp -> data << "\n";
}
void dll::ins_beg(int x){
	Node* temp = new Node;
	temp -> data = x;
	temp -> front = head;
	temp -> back = NULL;
	head -> back = temp;
	head = temp;
}
void dll::ins_end(int x){
	Node* temp = new Node;
	temp -> data = x;
	temp -> front = NULL;
	temp-> back = head -> back;
	head -> back = temp;
}
void dll::deletefront(){
	Node* temp = head;
	head = head -> front;
	head -> back = NULL;
	delete temp;
}
void dll::deleteback(){
	Node* temp = tail;
	tail = tail -> back;
	tail ->front = NULL;
	delete temp;
}
void dll::insert_pos(int pos,int ele){
	Node *temp = head;
	pos = pos-1;
	int count = 0;
	while(count < pos-1){
		temp = temp -> front;
		count ++;
	}
	Node * temp2 = new Node;
	temp2 -> data = ele;
	temp2 -> front = temp -> front;
	temp2 -> back = temp;
	temp -> front = temp2;
	if (count ==0)
		temp = head; 
}
void dll::search(int ele){
	Node* temp = head;
	int count = 0;
	while(temp -> data != ele){
		temp = temp -> front;
		count ++;	
	}
	cout << "The element " << ele << " is found at the position " << count+1 << "\n";
}
void dll::deleteposition(int pos){
	if(pos==1)
		deletefront();
	else{
	int count = 0;
	Node* temp = head;
	while(count < pos-1){
		temp = temp -> front;
		count ++;
	}
	Node* temp2 = temp -> front;
	temp -> front = temp2 -> front;
	Node* temp3 = temp2 -> front;
	temp3 -> back = temp;
	delete temp2; 
	}
}
int main(){
	dll s;
	s.create();
	s.display();
	s.deletefront();
	s.display();	
	s.deleteback();
	s.display();
	s.deleteposition(2);
	s.display();
	return 0;
}
