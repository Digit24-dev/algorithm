#include <iostream>
#include <string>
#define STACK_MAX 10000
using namespace std;

int top = -1;
int stack[STACK_MAX];
int size;

int main(){
	int N, num;
	string op;
	
	cin>>N;
	while(N--){
		cin>>op;
		if(op == "push"){
			cin>>num;
			top = top + 1;
			stack[top] = num;
		}else if(op == "top"){
			if(top == -1)
				cout<<"-1"<<endl;
			else
				cout<<stack[top]<<endl;
		}else if(op == "size"){
			cout<<top+1<<endl;
		}else if(op == "pop"){
			if(top == -1)
				cout<<"-1"<<endl;
			else{
				cout<<stack[top]<<endl;
				top = top - 1;
			}
		}else if(op == "empty"){
			if(top == -1)
				cout<<"1"<<endl;
			else
				cout<<"0"<<endl;
		}
	}
	return 0;
}
