#include<iostream>
using namespace std;
typedef int elt_type;
class mstack{
public:
	int top[100];
	int max[100];
	elt_type a[100];
	mstack(int n,int s){ 
		for(int i = 0;i< n ; i++){
			top[i] = s*i - 1;
			max[i] = s*(i+1) - 1; 
		}
	}
	void insert_ele(int s_num);
	elt_type pop_ele(int s_num);
	void display(int s_num);
	bool isFull(int s_num);
	bool isEmpty(int s_num);
};
void mstack::insert_ele(int s_num){
	if(isFull(s_num)){
		cout << "The stack " << s_num << " is Full.\n";
	}
	else{
	cout << "Enter the element to be inserted\n";
	elt_type data;
	cin >> data;
	a[++top[s_num-1]] = data;
	}
}
elt_type mstack::pop_ele(int s_num){
	if(isEmpty(s_num)){
		cout < "The stack is empty.\n";
		return 404;
	}	
	else
		return a[top[s_num-1]--];
}
bool mstack::isFull(int s_num){
	if(top[s_num-1] == max[s_num-1])
		return true;
	return false;
} 
bool mstack::isEmpty(int s_num){
	if(s_num == 1){
		if(top[0] == -1)
			return true;
		return false;
	}
	else{
		if(top[s_num-1] == max[s_num-2])
			return true;
		return false;
	}
}
void mstack::display(int s_num){
	if(s_num==1){
		for(int i = top[0]; i>-1;i--)
			cout << a[i] << " ";
		cout << "\n";
	}
	else{
		for(int i = top[s_num-1];i>max[s_num-2];i--)
			cout << a[i] << " ";
		cout << "\n";
	}
}
int main(){
	int num,size;
	cout << "Enter number of stacks and size of each stack.\n";
	cin >> num >> size;
	int s_num,choice = -1;
	mstack s(num,size);
	while(choice !=4){
	cout << "Enter\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
	cin >> choice;
	cout << "Enter stack number\n";
	cin >> s_num;
	switch(choice){
		case 1:
			s.insert_ele(s_num);
			break;
		case 2:
			cout << "The element is " << s.pop_ele(s_num) << "\n";
			break;
		case 3:
			s.display(s_num);
			break;
		}
	}
}
