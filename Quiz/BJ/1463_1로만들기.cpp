// 1463_1로 만들기

#include <iostream>
#include <algorithm>
using namespace std;

int cnt;
int DP[1000001];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	
	for(int i=2; i<=n; i++){
		DP[i] = DP[i-1] + 1;
		if(i%2 == 0) DP[i] = min(DP[i], DP[i/2] + 1);
		if(i%3 == 0) DP[i] = min(DP[i], DP[i/3] + 1);
	}
	
	printf("%d\n", DP[n]);
	
	return 0;
}
