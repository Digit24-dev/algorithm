#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 1000

vector<int> V[MAX];
bool visited[MAX] = {false, };
int ans = 0, cnt = 0;
int N, M;

void input(){
	cin>>N>>M;
	
	while(M--){
		int a, b;
		cin>>a>>b;
		
		V[a].push_back(b);
		V[b].push_back(a);
	}
}

void dfs(int index){
	
	//	종료조건 : 다음번 노드가 방문상태인지 아닌지

	visited[index] = true;													// 방문 상태로 표시 
	
	for(int i=0; i<V[index].size(); i++){									// 인덱스 0번째부터 벡터 자료형의 V[index]의 크기까지 증감 
		int next = V[index][i];												// 다음번 노드의 할당(next는 다음으로 이동할 "노드"를 의미한다 인덱스의 개념이 아니다.)
		
		if(!visited[next])													// 만약 다음 노드가 방문상태이지 않으면 재귀함수 호풀 
			dfs(next);														//  
	}
}

void solution(){
	input();
	memset(visited, false, sizeof(visited));								// 한번 방문했던 노드는 다시 방문하면 안되므로 한번만 초기화한다. 
	
	for(int i=1; i<=N; i++){
		if(!visited[i])														// 그래프를 1번 노드부터 순회하는데, 방문하지 않았던 노드에 대해서만 dfs를 선언하며  
		{																	// 함수가 종료되고 정상반환되면 1회 순회한 것이기 때문에 ans + 1을 한다. 
			dfs(i);
			ans++;
		}
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solution();
	
	return 0;
}
