#include <iostream>
using namespace std;

#define MAX_STACKSIZE 100

typedef int element;
element stack[MAX_STACKSIZE];
int top = -1;

bool isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
};

bool isFull(){
	if(top == MAX_STACKSIZE - 1)
		return 1;
	else
		return 0;
};

void push(element n){
	if(isFull())
		cout<<"stack is full"<<endl;
	else{
		top = top + 1;
		stack[top] = n;
		// stack[++top] = n;
	}
};

element pop(){
	if(isEmpty())
		cout<<"stack is empty"<<endl;
	else{
		top = top - 1;
		return stack[top+1];
	}
};

element peek(){
	if(isEmpty())
		cout<<"stack is Empty"<<endl;
	else
		return stack[top];
};

void printStack(){
	cout<<"stack[";
	for(int i=0; i<=top; i++){
		cout<<" "<<stack[i]<<" ";
	}
	cout<<"]"<<endl;
};

int main(){
	push(1);
	push(2);
	push(3);
	printStack();
	pop();
	pop();
	printStack();
	
	return 0;
}
