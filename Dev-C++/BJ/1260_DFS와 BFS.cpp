#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX 1001

int n, m, s;

// map -> 인접행렬 방식 저장 
int map[MAX][MAX];
vector<int> vector_map[MAX];
 
bool visited[MAX] = {false, };
stack<int> st;

// 인접 행렬 방식으로 저장한 맵에 재귀함수를 이용한 dfs
void dfs_map(int v){
	if(visited[v])
		return;
	visited[v] = true;
	cout<<v<<endl;
	for(int i=1; i<MAX; i++){
		if(map[v][i] == 1 and !visited[i]){
			dfs_map(i);
		}
	}
}

// 인접 행렬 방식으로 저장한 벡터 맵에 재귀함수를 이용한 dfs
void dfs_vector(int v){
	if(visited[v])
		return;
	visited[v] = true;
	cout<<v<<endl;
	for(int i=0; i<vector_map[v].size(); i++){
		int next = vector_map[v][i];
		dfs_vector(next);
	}
}

// 인접 행렬 방식으로 저장한 맵에 스택을 이용한 dfs
void dfs_stack(int v){
	st.push(v);
	
	while(!st.empty()){
		int cur = st.top();
		st.pop();
		
		if( visited[cur] )
			continue;
		visited[v] = true;
		cout<<cur<<endl;
		
		for(int i=vector_map[cur].size()-1; i>=0; i--){
			int next = vector_map[cur][i];
			st.push(next);
		}
	}
}

int main(){
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
	/*
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		map[x][y] = map[y][x] = 1;
	}*/
	
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		vector_map[x].push_back(y);
		vector_map[y].push_back(x);
	}
	
	//dfs_map(s);
	dfs_vector(s);
	
	return 0;
}
