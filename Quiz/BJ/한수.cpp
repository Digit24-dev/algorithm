#include <iostream>
using namespace std;

bool han(int n){
	int a[3];
	if(n<100)
		return true;
	else if(n==1000)
		return false;
	else{
		a[0] = n%10;
		n /= 10;
		a[1] = n%10;
		n /= 10;
		a[2] = n%10;
		
		if((a[0]-a[1])==(a[1]-a[2]))
			return true;
		else
			return false;
	}
}

int main(){
	int i, n;
	cin>>n;
	int cnt = 0;
	
	for(i=1; i<=n; i++){
		if(han(i))
			++cnt;
	}
	
	cout<<cnt<<endl;
	return 0;
}
