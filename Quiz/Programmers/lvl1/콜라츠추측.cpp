#include <string>
#include <vector>

using namespace std;

int stack = 0;

void sol(int num){
	if(stack >= 500){
		stack = -1;
		return;
	}
	
	if(num < 0){
		stack = -1;
		return;
	}else if(num == 1)
		return;
    
	++stack;
    
	if(num & 0x01){
		// odd
		sol(3*num + 1);
	}else{
		// even
		sol(num / 2);
	}
}

int solution(int num) {
    
    sol(num);
 	
    return stack;
}
