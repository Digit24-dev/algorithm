#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX 2000

vector<int> V[MAX];
bool Visit[MAX], ans;
int N, M;

void dfs(int index,int cnt){
	if(cnt == 5){
		ans = true;
		return;
	}
	
	Visit[index] = true;
	
	for(int i=0; i<V[index].size(); i++){
		int next = V[index][i];
		
		if(Visit[next]) 
			continue;
			
		dfs(next, cnt+1);
		
		if(ans) 
			return;
	}
	Visit[index] = false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// ют╥б
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	for(int i=0; i<N; i++){
		memset(Visit, false, sizeof(Visit));
		dfs(i, 1);
		if(ans) break;
	}
	
	if(ans)
		cout<<1<<endl;
	else
		cout<<0<<endl;
	
	
	return 0;
}
