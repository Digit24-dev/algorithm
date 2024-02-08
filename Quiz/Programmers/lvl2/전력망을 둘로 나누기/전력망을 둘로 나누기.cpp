#include <iostream>


#include <functional>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
using namespace std;

// 그래프에서 백트래킹 할 필요 없이 끊어졌다고 가정하고 조건문에서 판단할 것

int cnt = 0;
bool visited[101] = { false, };
vector<vector<int>> graph;

// 탐색
int dfs(int a, int b) {
    
    visited[a] = true;
    ++cnt;

    for (size_t i = 0; i < graph[a].size(); i++)
    {
        if (visited[graph[a][i]] || graph[a][i] == b) continue;
        dfs(graph[a][i], b);
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int ret = n;
    
    graph.resize(n + 1);

    for (auto& i : wires)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }

    // 하나씩 끊어보기
    for (auto& elem : wires)
    {
        cnt = 0;
        int left = dfs(elem[0], elem[1]);
        cnt = 0;
        int right = dfs(elem[1], elem[0]);
        ret = min(ret, abs(left - right));
        memset(visited, false, sizeof(visited));
    }

    return ret;
}


int main() {

    //int n = 9; vector<vector<int>> p = { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };
    //int n = 4; vector<vector<int>> p = { {1,2},{2,3},{3,4} };
    int n = 7; vector<vector<int>> p = { {1,2},{2,7},{3,7},{3,4},{4,5},{6,7} };

    cout << solution(n, p) << endl;

}