#include<iostream>
using namespace std;
typedef int elt_type;
class Stack{
public:	
	int top;
	int max;
	elt_type a[20];
	Stack(int m){
		max = m;
		top = -1;
	}
	void push(elt_type elt);
	elt_type pop();
	bool isFull() ;
	bool isEmpty();
	void display(); 
};
void Stack::push(elt_type elt){
	if(isFull())
		cout << "Stack is Full\n";
	else
		a[++top] = elt;
}
elt_type Stack::pop(){
	if(isEmpty()){
		cout << "Stack is empty\n";
		return -1;
	}
	else
		return a[top--];
}
bool Stack::isEmpty(){
	if(top == -1)
		return true;
	return false;
}
bool Stack::isFull(){
	if(top == max-1 )
		return true;
	return false;
}
void Stack::display(){
	cout << "The Stack is\n";
	for(int i = top; i>=0;i--){
		cout << a[i] << " ";
	}
	cout << "\n";
}
int main(){
	int n;
	cout << "Enter size of stack\n";
	cin >> n;
	Stack s(n);
	int choice = -1;
	while(choice != 4){
		cout << "Enter\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
		cin >> choice;
		switch(choice){
			case 1:
				elt_type temp;
				cout << "Enter element to push\n";
				cin >> temp;
				s.push(temp);
				break;
			case 2:
				cout << "The popped element is " << s.pop() << ".\n";
				break;
			case 3:
				s.display();
				break;
			case 4:
				break;
		}
	}
}
