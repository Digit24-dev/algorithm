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
	
	//	�������� : ������ ��尡 �湮�������� �ƴ���

	visited[index] = true;													// �湮 ���·� ǥ�� 
	
	for(int i=0; i<V[index].size(); i++){									// �ε��� 0��°���� ���� �ڷ����� V[index]�� ũ����� ���� 
		int next = V[index][i];												// ������ ����� �Ҵ�(next�� �������� �̵��� "���"�� �ǹ��Ѵ� �ε����� ������ �ƴϴ�.)
		
		if(!visited[next])													// ���� ���� ��尡 �湮�������� ������ ����Լ� ȣǮ 
			dfs(next);														//  
	}
}

void solution(){
	input();
	memset(visited, false, sizeof(visited));								// �ѹ� �湮�ߴ� ���� �ٽ� �湮�ϸ� �ȵǹǷ� �ѹ��� �ʱ�ȭ�Ѵ�. 
	
	for(int i=1; i<=N; i++){
		if(!visited[i])														// �׷����� 1�� ������ ��ȸ�ϴµ�, �湮���� �ʾҴ� ��忡 ���ؼ��� dfs�� �����ϸ�  
		{																	// �Լ��� ����ǰ� �����ȯ�Ǹ� 1ȸ ��ȸ�� ���̱� ������ ans + 1�� �Ѵ�. 
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
