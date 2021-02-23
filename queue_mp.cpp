#include<iostream>
using namespace std;
class queue{
public:
	int front,rear,max;
	int a[20];
	queue(int m){
		front = -1;
		rear = 0;
		max = m;
	}
	void enque(int x);
	int deque();
	void display();
	bool isFull();
	bool isEmpty();
};
void queue::enque(int x){
	if(isFull()){
		cout << "The queue is Full\n";
	}
	else{
		a[++front] = x;
	}
}
int queue::deque(){
	if(isEmpty()){
		cout << "The queue is Empty\n";
		return 0;
	}
	else{
		return a[rear++];
	}
}
bool queue::isFull(){
	if(front == max-1)
		return true;
	return false;
}
bool queue::isEmpty(){
	if(rear == front+1)
		return true;
	return false;
}
void queue::display(){
	for(int i=rear;i<=front;i++)
		cout << a[i] << " ";
	cout << "\n";
}
int main(){
	int choice,n;
	cout << "Enter the size of queue\n";
	cin >> n;
	queue q(n);
	cout << "Enter\n1.Enque\n2.Deque\n3.Display\n4.Exit\n";
	cin >> choice;
	while(choice!=4){
		switch(choice){
			case 1:
				int ele;
				cout << "Enter element to enque\n";
				cin >> ele;
				q.enque(ele);
				break;
			case 2:
				cout << "The dequeued element is " << q.deque() << "\n";
				break;
			case 3:
				cout << "The queue is \n";
				q.display();
				break;
		}
		cout << "Enter\n1.Enque\n2.Deque\n3.Display\n4.Exit\n";
		cin >> choice;
	}	
return 0;
}
