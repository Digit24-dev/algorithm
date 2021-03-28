#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100

int N, M;
bool a[MAX + 1][MAX + 1];
bool visited[MAX][MAX] = {false, };
int cnt = 0;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
	cin>>N>>M;
	int val;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%1d", &val);
			a[i][j] = val;
		}
	}
}

void check(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout<<a[i][j];
		}
	}
}

void bfs(){
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx>0 && nx<= M && ny>0 && ny<N && a[ny][nx] == 1){
				q.push(make_pair(ny, nx));
				
			}
		}
	}
}

void solution(){
	input();
	check();
	bfs();
	cout<<cnt<<endl;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	solution();
	
	return 0;
}
