#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAX 51

int n, m;
int r, c;
int d;
int answer = 1;

int map[MAX][MAX];
int visited[MAX][MAX];

// 북 동 남 서
int dc[] = {0, 1, 0, -1};
int dr[] = {-1, 0, 1, 0};
// +1 : 시계방향, -1: 반시계반향

void dfs(int r, int c, int d, int ans) {
	visited[r][c] = true;
	bool mode = 0;

	// 탐색
	for (int dir = 0; dir < 4; dir++)
	{
		int nc = c + dc[dir];
		int nr = r + dr[dir];

		// Out of Range
		if (nc < 0 || nc >= m || nr < 0 || nr >= n)
			continue;

		// 벽 이거나 청소 했으면 튕
		if (map[nr][nc] == 1 || visited[nr][nc])
			continue;

		// 벽이 아니고, 청소 하지 않았으면 mode 1
		if (map[nr][nc] == 0 && visited[nr][nc] == false) {
			mode = 1;
			break;
		}

		// 주변이 모두 청소 되었거나 벽일 경우 mode 0
	}

	if (mode)	// 청소되지 않은 빈칸이 있는 경우
	{
		for (int i = 0; i < 4; i++)		// 반시계 90도 부터 빈칸 찾고 청소 진행
		{
			int dir = (4 + d - 1 - i) % 4;		// 반시계 방향 우선 회전, 탐색
			int nc = c + dc[dir];
			int nr = r + dr[dir];

			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (map[nr][nc] == 0 && !visited[nr][nc])
				{
					answer++;
					dfs(nr, nc, dir, ans + 1);
				}
			}
		}
	}
	else                // 청소되지 않은 빈칸이 없는 경우
	{
		// 후진 방향
		int back = (d + 2) % 4;
		int nr = r + dr[back];
		int nc = c + dc[back];
		if (nr >= 0 && nr < n && nc >= 0 && nc < m)
		{
			// 후진 방향에 벽이 없는 경우
			if (map[nr][nc] == 0)
			{
				// 후진
				dfs(nr, nc, d, ans);
			}
			else {
				// 후진 할 수 없는 경우
				// 종료
				cout << ans << endl;
				exit(0);
				return;
			}
		}
	}
	cout << ans << endl;
	exit(0);
	return ;
}

int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;
	int temp; int idx=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			map[i][j] = temp;
			if (temp == 0)
				idx++;
		}
	}

	dfs(r, c, d, 1);
	cout << answer;

	return 0;
}