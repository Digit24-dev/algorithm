#include <iostream>
using namespace std;

typedef char element;

class Stack{
	private:
		int top, MaxSize;
		element *stack;
	public:
		Stack(int size);
		bool isFull(), isEmpty();
		element pop();
		void push(element data);
		void print();
};

Stack::Stack(int size){
	MaxSize = size;
	stack = new element[MaxSize];
	top = -1;
}

bool Stack::isFull(){
	if(top==MaxSize-1) return 1;
	else return 0;
}

bool Stack::isEmpty(){
	if(top == -1) return 1;
	else return 0;
}

element Stack::pop(){
	if(isEmpty())
		cout<<"stack is Empty."<<endl;
	else
		return stack[top--];
}

void Stack::push(element data){
	if(isFull())
		cout<<"stack is full."<<endl;
	else
		stack[++top] = data;
}

void Stack::print(){
	for(int i=0; i<=top; i++)
		cout<<stack[i]<<" ";
	cout<<endl;
}

int main(){
	
	Stack a(5);
	a.push('a');
	a.push('b');
	a.push('c');
	a.print();
	cout<<a.pop()<<endl;
	cout<<a.pop()<<endl;
	a.print();
	
	return 0;
}
