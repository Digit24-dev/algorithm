

#include <iostream>
using namespace std;

int main(){
	
	bool v[121] = {0, };
	
	for(int i=1; i<=120; ++i){
		for(int j=1; i*j <= 120; ++j){
			v[i*j] = !v[i*j];
		}
	}
	int ans = 0;
	for(int i=0; i<=120; ++i){
		if(v[i])
			++ans;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
