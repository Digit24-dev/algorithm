#include <iostream>
#define MAX 10001
using namespace std;

int karprekar(int n){
	int sum = n;
	
	while(n>0){
		sum += n%10;
		n /= 10;
	}
	
	return sum;
}


int main(){
	int D[MAX] = {0, };
	int i;
	for(i=1; i<MAX; i++){
		int idx = karprekar(i);
		if(idx < MAX)
			D[idx] = 1;
	}
	
	for(i=1; i<MAX; i++){
		if(!D[i])
			cout<<i<<endl;
	}
	
	return 0;
}
