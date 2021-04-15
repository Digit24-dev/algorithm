#include <iostream>
using namespace std;

int main(){
	int dp[40] = {0, 1};
	int t, n;
	for(int i=2; i<=40; i++){
			dp[i] = dp[i-1] + dp[i-2];
		}
	cin>>t;
	while(t--){
		cin>>n;
		if(n == 0)
			cout<<"1 0"<<endl;
		else if(n == 1)
			cout<<"0 1"<<endl;
		else{
			cout<<dp[n-1]<<" "<<dp[n]<<endl;
		}
	}
	
	return 0;
}
