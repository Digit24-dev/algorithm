#include <iostream>

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> m(n+1);
    vector<bool> visited(n+1, false);
    vector<int> t_dist(n+1, 0);

    // �׷��� �׸���
    for (auto& i : edge)
    {
        m[i[0]].push_back(i[1]);
        m[i[1]].push_back(i[0]);
    }

    // ���� �� ��� ã��
    int max_dist = 0; // �ִ� �Ÿ�
    queue<pair<int, int>> q; // f: node, s: dist
    q.push(make_pair(1, 0));
    visited[1] = true;

    // 1. bfs�� ��� ����� �Ÿ��� �˾Ƴ���, �ִ� ���� dist �� ��� ���� ��ȯ
    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        
        for (auto i : m[cur.first])
        {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(make_pair(i, cur.second + 1));
            t_dist[i] = cur.second + 1;
            max_dist = max(max_dist, cur.second + 1);
        }
    }

    for (auto& i : t_dist)
    {
        if (i == max_dist) answer++;
    }

    return answer;
}


int main() {
    int n = 6; vector<vector<int>> param = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };

    cout << solution(n, param) << endl;

}