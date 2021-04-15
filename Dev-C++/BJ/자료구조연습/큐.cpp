#include <iostream>
using namespace std;

typedef int element;
#define MAX_Q_SIZE 100

int front = -1;
int rear = -1;
element Queue[MAX_Q_SIZE];

bool isEmpty(){
	if(front == rear)
		return 1;
	else
		return 0;
};

bool isFull(){
	if(rear = MAX_Q_SIZE - 1)
		return 1;
	else
		return 0;
};

void enQueue(element n){
	if(isFull())
		cout<<"Queue is full."<<endl;
	else{
		Queue[++rear] = n;
	}
};

element deQueue(){
	if(isEmpty())
		cout<<"Queue is empty."<<endl;
	else{
		return Queue[++front];
	}
};

int main(){
	
	
	return 0;
}
