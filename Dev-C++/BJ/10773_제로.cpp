#include <iostream>
using namespace std;
#define MAX 100000



int main(){
	
	int K,n;
	cin>>K;
	int s[K];
	int top = -1;
	
	while(K--){
		cin>>n;
		if(n == 0){
			top = top - 1;
		}else{
			top = top + 1;
			s[top] = n;
		}
	}
	int sum=0;
	for(int i=0; i<=top; i++){
		sum += s[i];
	}
	cout<<sum<<endl;
	
	return 0;
}
