#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> graph[100001];
int visited[100001] = { 0, };
int result[100001];
int cnt = 0;

void bfs(int r) {
	queue<int> q;
	q.push(r);
	visited[r] = 1;
	cnt++;
	result[r] = cnt;
	cout << r << " ";
	while (!q.empty())
	{
		int inq = q.front();
		q.pop();
		
		for (size_t i = 0; i < graph[inq].size(); i++)
		{
			int temp = graph[inq][i];
			if (!visited[temp]) {
				q.push(temp);
				cnt++;
				result[temp] = cnt;
				visited[temp] = 1;
				cout << temp << " ";
			}
		}
	}
}

void dfs(int r) {
	if (visited[r])
		return;
	
	cnt++;
	result[r] = cnt;
	visited[r] = 1;
	cout << r << " ";

	for (int i = 0; i < graph[r].size(); i++)
	{
		dfs(graph[r][i]);
	}
}

int main() {
	int n, m, r;

	cin >> n >> m >> r;
	for (size_t i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (size_t i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(r);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	bfs(r);

	return 0;
}