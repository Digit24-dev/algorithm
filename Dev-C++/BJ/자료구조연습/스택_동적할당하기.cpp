#include <iostream>
using namespace std;

typedef int element;
int top = -1;
int size;
element* Stack;

void createStack(int n){
	size = n;
	Stack = new element[n];
};

bool isFull(){
	if(top == size - 1)
		return 1;
	else
		return 0;
};

bool isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
};

int push(element n){
	if(isFull()){
		cout<<"stack is full."<<endl;
		return -1;
	}
	else{
		Stack[++top] = n;
		return 0;
	}
};

element pop(){
	if(isEmpty())
		cout<<"stack is empty."<<endl;
	else{
		return Stack[top--];
	}
};

element peek(){
	if(isEmpty())
		cout<<"stack is empty."<<endl;
	else
		return Stack[top];
};

void printStack(){
	cout<<"Stack[";
	for(int i=0; i<size; i++){
		cout<<" "<<Stack[i]<<" ";
	}
	cout<<"]"<<endl;
};

void destroyStack(){
	delete[] Stack;
};

int main(){
	int n;
	cin>>n;
	createStack(n);
	push(3);
	push(2);
	push(1);
	printStack();
	pop();
	pop();
	printStack();
	destroyStack();
	
	return 0;
}
