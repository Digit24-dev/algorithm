#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef pair<int, int> P;   // v, w

vector<P> graph[100];
bool visited[100];

/// <summary>
/// ***************** STL 인스턴스에 커스텀 함수 넣는 방법
/// </summary>
struct comp
{
    bool operator()(P a, P b) {
        return a.second > b.second;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<P, vector<P>, comp> pq;
    
    for (auto& cost : costs)
    {
        graph[cost[0]].push_back(make_pair(cost[1], cost[2]));
    }

    for (size_t i = 0; i < graph[0].size(); i++)
    {
        pq.push(graph[0][i]);
    }
    visited[0] = true;

    int cnt = 0;
    while (cnt < n - 1)
    {
        P cur = pq.top(); pq.pop();

        int node = cur.first;
        int weight = cur.second;

        if (visited[node]) continue;
        visited[node] = true;
        ++cnt;
        answer += weight;

        for (size_t i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i].first;
            if (!visited[nextNode]) pq.push(graph[node][i]);
        }
    }
    
    return answer;
}

int main() {
    //int n = 4; vector<vector<int>> p = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    //int n = 5; vector<vector<int>> p = { {0,1,5},{0,4,3},{1,2,4},{1,3,8},{2,3,2},{2,4,1},{3,4,3} };
    //int n = 4; vector<vector<int>> p = { {0,1,1},{0,2,1},{1,2,1},{1,3,1},{2,3,1} };
    int n = 8; vector<vector<int>> p = { {0,1,1},{1,2,4},{2,3,1},{0,4,1},{4,5,1},{1,5,1},{2,6,1},{6,7,1},{3,7,1} };

    cout << solution(n, p) << endl;

 }