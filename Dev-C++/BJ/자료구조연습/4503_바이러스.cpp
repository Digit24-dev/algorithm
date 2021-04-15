#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX 101

int N, M;
int ans = 0;
//vector<vector<int>> map;
//vector<int> map2;
bool visited[MAX] = {false};
int map[MAX][MAX];

void input(){
	cin>>N>>M;
	int x, y;
	
	while(M--){
		cin>>x>>y;
//		map[x].push_back(y);
//		map[y].push_back(x);
		map[x][y] = map[y][x] = 1;
	}
}

void dfs(int depth){
	//if(depth == M)
	//	return;
		
	visited[depth] = true;
	
	for(int i=1; i<=N; i++){
		if(!visited[i] && map[depth][i]){
			ans++;
			dfs(i);
		}
	}
}

void solution(){
	input();
	dfs(1);
	cout<<ans<<endl;
}

int main(){
//	map.push_back(map2);
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	
	solution();
	
	return 0;
}
