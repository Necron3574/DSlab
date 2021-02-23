#include<iostream>
using namespace std;
typedef char elt_type;
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
	int base,num,temp;
	cout << "Enter the number\n";
	cin >> num;
	cout << "Enter base you wish to convert to:\n";
	cin >> base;
	Stack s(20);
	while(num!=0){
		s.push(num%base);
		num /= base;	
	}
	cout << "The number converted to base " << base << " is \n";
	while(s.isEmpty() != true){
		temp = s.pop();
		if(temp>9){
			temp += 55;
			cout << (char) temp;
		}
		else{
			cout << temp;
		}
	}
}
