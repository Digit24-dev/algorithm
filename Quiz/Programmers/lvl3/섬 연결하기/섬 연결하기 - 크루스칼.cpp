#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

#define MAX 105
using namespace std;

int Parent[MAX];
vector<pair<int, pair<int, int>>> Graph;

int find_Parent(int idx)
{
	if (idx == Parent[idx]) return idx;
	return Parent[idx] = find_Parent(Parent[idx]);
}

bool same_Parent(int a, int b)
{
	a = find_Parent(a);
	b = find_Parent(b);
	if (a == b) return true;
	else return false;
}

void Union(int a, int b)
{
	a = find_Parent(a);
	b = find_Parent(b);
	Parent[b] = a;
}

int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;

	// init
	for (int i = 0; i < n; i++) Parent[i] = i;
	// draw
	for (int i = 0; i < costs.size(); i++)
	{
		int node1 = costs[i][0];
		int node2 = costs[i][1];
		int cost = costs[i][2];
		Graph.push_back(make_pair(cost, make_pair(node1, node2)));
	}
	// sort
	sort(Graph.begin(), Graph.end());
	// ũ�罺Į
	for (int i = 0; i < Graph.size(); i++)
	{
		int cost = Graph[i].first;
		int node1 = Graph[i].second.first;
		int node2 = Graph[i].second.second;

		if (!same_Parent(node1, node2)) 
		{
			Union(node1, node2);
			answer += cost;
		}
	}

	return answer;
}


int main() {

	int n = 4; vector<vector<int>> p = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

	cout << solution(n, p) << endl;

}