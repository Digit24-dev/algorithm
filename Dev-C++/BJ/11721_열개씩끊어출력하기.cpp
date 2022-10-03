#include <iostream>
#include <string>
using namespace std;

int main(){
	char s[102] = {0, };
	char c;
	int idx = 0;
	
	for(idx = 1; idx < 102; idx++){
		scanf("%c", &c);
		s[idx] = c;
		if( c == '\n' ){
			s[idx] = c;
			break;
		}
	}
	
	for(idx = 1; s[idx] != '\n'; idx++){
		
		if(idx%10 == 0 && idx > 1)
			cout<<s[idx]<<endl;
		else
			cout<<s[idx];
	}
	
	return 0;
}
