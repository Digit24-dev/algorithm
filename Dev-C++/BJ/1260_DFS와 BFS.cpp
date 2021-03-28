#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 1001

int n, m, s;

// map -> ������� ��� ���� 
int map[MAX][MAX];
vector<int> vector_map[MAX];
 
bool visited[MAX] = {false, };
stack<int> st;



/*
************ dfs *************

void dfs_����(){
	���� ���� 
	
	while( ������ ������� �ʴ� ���� ){
		���� top
		���� pop
		
		�湮 ������ continue / �������� �湮 ó��
		for(i�� 0���� �ش� ��/�迭 ������){
			next = map[index][i];
			���� push(next) 
		}
	}
}
*/


// ���� ��� ������� ������ �ʿ� ����Լ��� �̿��� dfs
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

// ���� ��� ������� ������ ���� �ʿ� ����Լ��� �̿��� dfs
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

// ���� ��� ������� ������ �ʿ� ������ �̿��� dfs
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



/*
********** bfs ***********

void bfs(){
	ť ���� 
	ť push
	�湮 ó�� 
	
	while( ť�� ���� ���� ���� ){
		ť front 
		ť pop
		
		if( ���� ){
			ť push
			�湮 ó�� 
		}
	
	}
}
***************************
*/

// �� ������� ������ �ʿ� ť�� �̿��� BFS
void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
	while(!q.empty()){
		int q_front = q.front();
		q.pop();
		cout<<q_front<<endl;
		
		for(int i=1; i<=n; i++){
			if(i == q_front)
				continue;
			else{
				if(!visited[i] && map[q_front][i] == 1 && map[i][q_front] == 1){
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}
}


int main(){
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
	
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		map[x][y] = map[y][x] = 1;
	}
	
	/*for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		vector_map[x].push_back(y);
		vector_map[y].push_back(x);
	}*/
	
	//dfs_map(s);
	//dfs_vector(s);
	bfs(s);
	
	return 0;
}
