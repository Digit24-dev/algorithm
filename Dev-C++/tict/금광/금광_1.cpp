#include <iostream>
#include <ctime>
using namespace std;

int T, n, m;

// dfs 로 맵을 구성하는 방법은 dp라 하기는 힘들어 보인다.
// dp적으로 생각해보자.

int map[21][21];
int ans[21][21];

int answer = 0;
int d[3] = { -1,0,1 };

clock_t start, finish;

void search(int i,int j, int sum) 
{
	if (i > n || j > m)
		return;

	ans[i][j] = max(sum, ans[i][j]);

	for (int dir = 0; dir < 3; dir++)
	{
		int next = i + d[dir];
		if (next > n || next < 1)
			continue;
		if (j + 1 > m)
			continue;
		search(next, j + 1, sum + map[next][j+1]);
	}
}


int main()
{
	start = clock();
	cin >> T;
	while (T--)
	{
		answer = 0;
		memset(ans, 0, sizeof(ans));
		// input
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> map[i][j];
			}
		}
		// init & search
		for (int i = 1; i <= n; i++)
		{
			ans[i][1] = map[i][1];
			search(i, 1, ans[i][1]);
		}
		for (int i = 1; i <= m; i++)
		{
			answer = max(answer, ans[i][m]);
		}
		cout << answer << endl;
	}
	finish = clock();
	cout << static_cast<double>(finish - start) / CLOCKS_PER_SEC << endl;
}