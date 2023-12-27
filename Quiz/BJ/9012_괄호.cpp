#include <iostream>
using namespace std;
#define MAX 50

int main(){
	int T;
	cin>>T;
	
	string stack;
	const char* p = stack.c_str();
	int top = -1;
	
	while(T--) {
		cin>>stack;
		
		for(p = stack.c_str(); *p!='\0'; p++){
			if(*p == '('){			// push
				if(top == stack.length()){
					cout<<"NO"<<endl;
					goto end;
				}else{
					top = top + 1;
				}
			}else{					// pop
				if(top == -1){
					cout<<"NO"<<endl;
					goto end;
				}else{
					top = top - 1;
				}
			}
		}
		if(top == -1)
			cout<<"YES"<<endl;
		else{
			cout<<"NO"<<endl;
		}
		
	end:
		stack = "";
		top = -1;
	}
	
	return 0;
}
