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

// �� �� �� ��
int dc[] = {0, 1, 0, -1};
int dr[] = {-1, 0, 1, 0};
// +1 : �ð����, -1: �ݽð����

void dfs(int r, int c, int d, int ans) {
	visited[r][c] = true;
	bool mode = 0;

	// Ž��
	for (int dir = 0; dir < 4; dir++)
	{
		int nc = c + dc[dir];
		int nr = r + dr[dir];

		// Out of Range
		if (nc < 0 || nc >= m || nr < 0 || nr >= n)
			continue;

		// �� �̰ų� û�� ������ ƨ
		if (map[nr][nc] == 1 || visited[nr][nc])
			continue;

		// ���� �ƴϰ�, û�� ���� �ʾ����� mode 1
		if (map[nr][nc] == 0 && visited[nr][nc] == false) {
			mode = 1;
			break;
		}

		// �ֺ��� ��� û�� �Ǿ��ų� ���� ��� mode 0
	}

	if (mode)	// û�ҵ��� ���� ��ĭ�� �ִ� ���
	{
		for (int i = 0; i < 4; i++)		// �ݽð� 90�� ���� ��ĭ ã�� û�� ����
		{
			int dir = (4 + d - 1 - i) % 4;		// �ݽð� ���� �켱 ȸ��, Ž��
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
	else                // û�ҵ��� ���� ��ĭ�� ���� ���
	{
		// ���� ����
		int back = (d + 2) % 4;
		int nr = r + dr[back];
		int nc = c + dc[back];
		if (nr >= 0 && nr < n && nc >= 0 && nc < m)
		{
			// ���� ���⿡ ���� ���� ���
			if (map[nr][nc] == 0)
			{
				// ����
				dfs(nr, nc, d, ans);
			}
			else {
				// ���� �� �� ���� ���
				// ����
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