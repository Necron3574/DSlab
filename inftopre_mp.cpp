#include<iostream>
#include<cstring>
using namespace std;
typedef char elt;
class Stack{
public:	
	int top;
	int max;
	elt a[20];
	Stack(int m){
		max = m;
		top = -1;
	}
	void push(elt ele);
	elt pop();
	bool isFull() ;
	bool isEmpty();
	void display();
	elt peek();
};
void Stack::push(elt ele){
		a[++top] = ele;
}
elt Stack::pop(){
	if(isEmpty()){
		return NULL;
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
elt Stack::peek(){
	if(isEmpty()){
		return NULL;
	}
	else{
		return a[top];
	}
}
bool isOp(char x){
	if(x == '+' ||x == '-' ||x == '*' ||x == '/' ||x == '^' ||x == '(' ||x == ')')
		return true;
	return false;
}

int precedence(char op){
	switch(op){
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		case '^':
			return 5;
	}
	return 0;
}

char* infixToPrefix(char* infix){
	char cur, prefix[30];
	int k=0;
	Stack s(20);
	for(int i=strlen(infix)-1;i>=0;i--){
		cur = infix[i];
		if(isOp(cur)){
			switch(cur){
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					while(precedence(cur)<=precedence(s.peek()) && s.peek()!= NULL){
						prefix[k++] = s.pop();
					}
					s.push(cur);
					break;
				case ')':
					s.push(cur);
					break;
				case '(':
					while(s.peek()!=')'){
						prefix[k++] = s.pop();
					}
					s.pop();
					break;
			}
		}
		else{
			prefix[k++] = cur;
		}
	}
	while(!s.isEmpty()){
		prefix[k++] = s.pop();	
	}
	prefix[k] = '\0';
	for(int i=strlen(prefix)-1;i>=0;i--)
		cout << prefix[i];
}

int main(){
	char inf[30];
	cout << "Enter the infix string:\n";
	cin >> inf;
	cout << "The prefix of this string is:\n";	
	infixToPrefix(inf);
return 0;
}
