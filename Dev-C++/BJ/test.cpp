#include <iostream>
using namespace std;

int main(){
	string a = "asdfasdf";
	const char *p = a.c_str();
	string *pp = &a;
	
	cout<<*(p+1)<<endl;
	cout<<*pp<<endl;
	
	return 0;
}
