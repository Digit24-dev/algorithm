#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101

int map[MAX][MAX];
int visited[MAX];

int total_people;
int m, a, b;
int answer = -1;

void dfs(int cur, int target, int cnt)
{
	// 规巩 贸府
	visited[cur] = true;

	if (cur == b) {
		answer = cnt;
		return;
	}
	
	for (int i = 1; i <= total_people; i++)
	{
		if (visited[i]) continue;
		if (map[cur][i] == 0) continue;
			dfs(i, target, cnt + 1);
	}
	// backtrack
	cnt--;
}

int main()
{	
	cin >> total_people;
	cin >> a >> b;
	cin >> m;

	// map i -> j :: i绰 j狼 何葛
	for (int i = 0; i < m; i++)
	{
		int _first, _second;
		cin >> _first >> _second;

		map[_first][_second] = 1;
		map[_second][_first] = 1;
	}

	// a -> b
	dfs(a, b, 0);
	
	cout << answer << endl;

	return 0;
	
}