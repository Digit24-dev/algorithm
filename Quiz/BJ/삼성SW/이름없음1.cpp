#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;


/*
0 : ��ĭ 
1 : ��
2 : ���̷��� 
*/

int N, M; // 3 ~ 8
// 1 < ���̷����� ���� <= 10, ��ĭ >= 3 
int map[8][8];
int tmp[8][8]; 

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

void copy(int dst[8][8], int src[8][8]){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			dst[i][j] = src[i][j];
		}
	}
}

void bfs(){
	int spread[8][8];
	copy(spread, tmp);
	queue<pair<int, int>> q;
	
	// ���̷��� ���� 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 2){
				q.push({i,j});
			}
		}
	}
	// bfs ���� 
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		
		for(int dir=0; dir<4; dir++){
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			
			if(nx<0 || nx>N || ny<0 || ny>M)
				continue;
			if(spread[nx][ny] != 0)
				continue;
				
			spread[nx][ny] = 2;
			q.push({nx,ny});
		}
	}
	
	// 0����
	int cnt = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(spread[i][j] == 0){
				++cnt;
			}
		}
	}
	ans = max(cnt, ans);
}

void permut(int depth) {
	if(depth == 3){
		bfs();
		return;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tmp[i][j] == 0){
				tmp[i][j] = 1;
				permut(depth + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// �Է� 
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
	
	// �ߺ� ����
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 0){
				copy(tmp, map);
				tmp[i][j] = 1;
				permut(1);
				tmp[i][j] = 0;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}

/*

��� ����� ����Ͽ��� ����
�ִ� �ð� ���
8 x 8 ���̷��� 2 
62 �� �ִ�

62 c 3

62 61 60
 3 2 1
 
 62 * 61 * 10 37820 < 2 000 000 000
*/
