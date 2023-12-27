#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> graph[100001];
bool visited[100001] = { false, };
int result[100001];
int ans = 0;

void bfs(int r) {
	queue<int> q;
	q.push(r);
	visited[r] = true;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int i = 0; i < graph[a].size(); i++)
		{
			int dst = graph[a][i];
			
			if (!visited[dst]) {
				visited[dst] = true;
				q.push(dst);
				ans++;
			}
		}
	}
}

int main()
{
	int com; // 1 ~ 100
	int cnt; // °£¼±¼ö
	cin >> com >> cnt;

	for (size_t i = 0; i < cnt; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	cout << ans << endl;

	return 0;
}