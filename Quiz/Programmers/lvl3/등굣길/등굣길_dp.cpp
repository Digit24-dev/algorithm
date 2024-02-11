#include <iostream>

#include <string>
#include <vector>

using namespace std;

int map[101][101] = { 0, };

// 2. 메모제이션
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int ways = 1;

    for (auto& i : puddles)
    {
        map[i[1]][i[0]] = -1;
    }
    
    for (size_t i = 1; i <= m; i++)
    {
        if (map[1][i] == -1) {
            ways = 0;
            continue;
        }
        map[1][i] = ways;
    }
    ways = 1;
    for (size_t i = 1; i <= n; i++)
    {
        if (map[i][1] == -1) {
            ways = 0;
            continue;
        }
        map[i][1] = ways;
    }

    for (size_t i = 2; i <= n; i++)
    {
        for (size_t j = 2; j <= m; j++)
        {
            if (map[i][j] != -1) {
                int up = map[i - 1][j] == -1 ? 0 : map[i - 1][j];
                int left = map[i][j - 1] == -1 ? 0 : map[i][j - 1];

                map[i][j] = (up + left) % 1000000007;
            }
        }
    }

    return map[n][m];
}

int main() {
    vector<vector<int>> p = { {2,2}, {3,3}, {1,2} };

    cout << solution(5, 5, p) << endl;

}

// 1. bfs로 탐색을 진행하며 dp를 쓴다?

//// bfs
//queue<pair<int, int>> q;
//q.push(make_pair(1, 1));

//while (!q.empty())
//{
//    pair<int, int> cur = q.front(); q.pop();
//    visited[cur.first][cur.second] = (visited[cur.first][cur.second] + 1) % 1000000007;

//    //int up = map[cur.first - 1][cur.second] == -1 ? 0 : map[cur.first - 1][cur.second];
//    //int left = map[cur.first][cur.second - 1] == -1 ? 0 : map[cur.first][cur.second - 1];

//    //map[cur.first][cur.second] = (up + left) % 1000000007;

//    for (size_t dir = 0; dir < 2; dir++)
//    {
//        int ni = cur.first + di[dir];
//        int nj = cur.second + dj[dir];

//        if (map[ni][nj] != -1 && ni <= n && nj <= m) {
//            q.push(make_pair(ni, nj));
//            //map[ni][nj] += visited[cur.first][cur.second];
//        }
//    }
//}
