#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int di[2] = { 0, 1 };
int dj[2] = { 1, 0 };

int visited[101][101] = { 0, };

int map[101][101] = { 0, };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<int> t_bucket(m + 1, 0);

    for (auto& i : puddles)
    {
        map[i[0]][i[1]] = -1;
    }

    // bfs
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));

    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        ++visited[cur.first][cur.second];
        
        int up = map[cur.first - 1][cur.second] == -1 ? 0 : map[cur.first - 1][cur.second];
        int left = map[cur.first][cur.second - 1] == -1 ? 0 : map[cur.first][cur.second - 1];

        map[cur.first][cur.second] = map[cur.first][cur.second] + up + left % 1000000007;

        for (size_t dir = 0; dir < 2; dir++)
        {
            int ni = cur.first + di[dir];
            int nj = cur.second + dj[dir];

            if (map[ni][nj] != -1 && ni <= n && nj <= m) {
                q.push(make_pair(ni, nj));
                map[ni][nj] += visited[cur.first][cur.second];
            }
        }
    }

    return map[m][n];
}


int main() {

    cout << solution(4, 3, { {2,2} }) << endl;

}