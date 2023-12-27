#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

// 0: 벽, 1: 공간
vector<vector<int>> ent_map;
int visited[100][100] = { 0, };

int m, n;

int dm[4] = { 0,0,1,-1 };
int dn[4] = { 1,-1,0,0 };

int sol(int i, int j) {
    queue<pair<int, int>> q; // n, m
    q.push(make_pair(i, j));
    size_t dir;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        visited[cur.first][cur.second] = 1;
        q.pop();

        // 종료 조건
        if (cur.first == n-1 && cur.second == m-1)
        {
            return ent_map[cur.first][cur.second];
        }

        // 방향 탐색
        for (dir = 0; dir < 4; dir++)
        {
            int nn = cur.first + dn[dir];
            int nm = cur.second + dm[dir];

            if (nn >= 0 && nn < n && nm >= 0 && nm < m)
            {
                if (visited[nn][nm] == 0)
                {
                    if (ent_map[nn][nm] == 1)
                    {
                        q.push(make_pair(nn, nm));
                        ent_map[nn][nm] = ent_map[cur.first][cur.second] + 1;
                    }
                }
            }

            //// 위 코드와 아래 코드를 비교하여 생각하여 보자. bfs 특성상 모든 경로를 조회하게 되는데,
            //// 안되는 경로를 continue 하는 방법 보다는 정확한 조건에 들어 왔을 때만 데이터를 받는 코드가 더 효율적이다.
            // 
            //if (visited[nn][nm]) continue;
            //if (nn < 0 || nn >= n || nm < 0 || nm >= m) continue;
            //if (ent_map[nn][nm] == 0) continue;
        }
        
        // 네 방향 탐색 후 큐에 넣은 데이터가 없을 때, 갈 수 있는 방향은 없다.
        if (q.empty())
            return -1;
    }
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();    // 4 (세로)
    m = maps[0].size(); // 5 (가로)

    ent_map = maps;
    int answer = sol(0, 0);

    return answer;
}

int sol2(int i, int j) {
    queue<pair<int, int>> q; // n, m
    q.push(make_pair(i, j));
    size_t dir;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        visited[cur.first][cur.second] = 1;
        q.pop();

        // 종료 조건
        if (cur.first == n - 1 && cur.second == m - 1)
        {
            return ent_map[cur.first][cur.second];
        }

        // 방향 탐색
        for (dir = 0; dir < 4; dir++)
        {
            int nn = cur.first + dn[dir];
            int nm = cur.second + dm[dir];

            /*if (nn >= 0 && nn < n && nm >= 0 && nm < m)
            {
                if (visited[nn][nm] == 0)
                {
                    if (ent_map[nn][nm] == 1)
                    {
                        q.push(make_pair(nn, nm));
                        ent_map[nn][nm] = ent_map[cur.first][cur.second] + 1;
                    }
                }
            }*/

            //// 위 코드와 아래 코드를 비교하여 생각하여 보자. bfs 특성상 모든 경로를 조회하게 되는데,
            //// 안되는 경로를 continue 하는 방법 보다는 정확한 조건에 들어 왔을 때만 데이터를 받는 코드가 더 효율적이다.
            // 
            if (visited[nn][nm]) continue;
            if (nn < 0 || nn >= n || nm < 0 || nm >= m) continue;
            if (ent_map[nn][nm] == 0) continue;

            q.push(make_pair(nn, nm));
            ent_map[nn][nm] = ent_map[cur.first][cur.second] + 1;
        }

        // 네 방향 탐색 후 큐에 넣은 데이터가 없을 때, 갈 수 있는 방향은 없다.
        if (q.empty())
            return -1;
    }
}

int solution2(vector<vector<int>> maps)
{
    n = maps.size();    // 4 (세로)
    m = maps[0].size(); // 5 (가로)

    ent_map = maps;
    int answer = sol2(0, 0);

    return answer;
}

// 실행할 떄마다 실행 시간이 변경 되지만, 평균적으로 함수 초기에 있는 코드가 더 오래 걸리는 경향을 보인다.
// 데이터를 늘려서 확인해 보는 편이 좋겠다.

int main()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();

    cout << solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} }) << endl;
    
    chrono::system_clock::time_point end = chrono::system_clock::now();

    chrono::nanoseconds nano = end - start;

    cout << "Solution 1 process time : " << nano.count() << endl;

    memset(visited, 0, sizeof(visited));

    start = chrono::system_clock::now();

    cout << solution2({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} }) << endl;
    
    end = chrono::system_clock::now();

    nano = end - start;

    cout << "Solution 2 process time : " << nano.count() << endl;

    return 0;
}