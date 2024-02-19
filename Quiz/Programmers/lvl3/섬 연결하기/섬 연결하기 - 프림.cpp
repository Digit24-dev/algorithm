#include <iostream>

#include <string>
#include <vector>
#include <queue>

#define MAX 105
using namespace std;

bool visit[MAX];
vector<pair<int, int>> graph[MAX];

int solution(int n, vector<vector<int>> costs) 
{
	int answer = 0;

	for (int i = 0; i < costs.size(); i++)
	{
		int u = costs[i][0];
		int v = costs[i][1];
		int cost = costs[i][2];

		graph[u].push_back(make_pair(v, cost));
		graph[v].push_back(make_pair(u, cost));
	}

	priority_queue<pair<int, int>> pq;	// 우선순위 큐 -> pair의 first로 정렬
	for (int i = 0; i < graph[0].size(); i++)
	{
		int next = graph[0][i].first;
		int next_cost = graph[0][i].second;

		pq.push(make_pair(-next_cost, next));
	}
	visit[0] = true;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (!visit[cur]) 
		{
			visit[cur] = true;
			answer += dist;

			for (int i = 0; i < graph[cur].size(); i++)
			{
				int next = graph[cur][i].first;
				int next_dist = graph[cur][i].second;
				if (!visit[next]) pq.push(make_pair(-next_dist, next));
			}
		}
	}

	return answer;
}


int main() {

	int n = 4; vector<vector<int>> p = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

	cout << solution(n, p) << endl;

}