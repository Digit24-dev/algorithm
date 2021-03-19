#include <iostream>
using namespace std;

int fibonaci(int n){
	if(n<1)
		return 0;
	else if(n==1)
		return 1; 
	return fibonaci(n-1) + fibonaci(n-2); 
}

int main(){
    int n;
    cin>>n;
    cout<<fibonaci(n)<<endl;
    
    return 0;
}
