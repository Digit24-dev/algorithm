#include <iostream>
using namespace std;

int main(){
	
	int T, n;
	int max = 0;
	
	string max_name;
	
	cin>>T;
	
	while(T--){
		cin>>n;
		int price[n];
		string name[n];
		
		for(int i=0; i<n; i++){
			cin>>price[i]>>name[i];
			if(max < price[i]){
				max = price[i];
				max_name = name[i];
			}
		}
		
		cout<<max_name<<endl;
		max_name = "";
		max = 0;
	}
	
	return 0;
}
