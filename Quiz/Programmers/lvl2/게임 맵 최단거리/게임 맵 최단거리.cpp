#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

// 0: ��, 1: ����
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

        // ���� ����
        if (cur.first == n-1 && cur.second == m-1)
        {
            return ent_map[cur.first][cur.second];
        }

        // ���� Ž��
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

            //// �� �ڵ�� �Ʒ� �ڵ带 ���Ͽ� �����Ͽ� ����. bfs Ư���� ��� ��θ� ��ȸ�ϰ� �Ǵµ�,
            //// �ȵǴ� ��θ� continue �ϴ� ��� ���ٴ� ��Ȯ�� ���ǿ� ��� ���� ���� �����͸� �޴� �ڵ尡 �� ȿ�����̴�.
            // 
            //if (visited[nn][nm]) continue;
            //if (nn < 0 || nn >= n || nm < 0 || nm >= m) continue;
            //if (ent_map[nn][nm] == 0) continue;
        }
        
        // �� ���� Ž�� �� ť�� ���� �����Ͱ� ���� ��, �� �� �ִ� ������ ����.
        if (q.empty())
            return -1;
    }
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();    // 4 (����)
    m = maps[0].size(); // 5 (����)

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

        // ���� ����
        if (cur.first == n - 1 && cur.second == m - 1)
        {
            return ent_map[cur.first][cur.second];
        }

        // ���� Ž��
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

            //// �� �ڵ�� �Ʒ� �ڵ带 ���Ͽ� �����Ͽ� ����. bfs Ư���� ��� ��θ� ��ȸ�ϰ� �Ǵµ�,
            //// �ȵǴ� ��θ� continue �ϴ� ��� ���ٴ� ��Ȯ�� ���ǿ� ��� ���� ���� �����͸� �޴� �ڵ尡 �� ȿ�����̴�.
            // 
            if (visited[nn][nm]) continue;
            if (nn < 0 || nn >= n || nm < 0 || nm >= m) continue;
            if (ent_map[nn][nm] == 0) continue;

            q.push(make_pair(nn, nm));
            ent_map[nn][nm] = ent_map[cur.first][cur.second] + 1;
        }

        // �� ���� Ž�� �� ť�� ���� �����Ͱ� ���� ��, �� �� �ִ� ������ ����.
        if (q.empty())
            return -1;
    }
}

int solution2(vector<vector<int>> maps)
{
    n = maps.size();    // 4 (����)
    m = maps[0].size(); // 5 (����)

    ent_map = maps;
    int answer = sol2(0, 0);

    return answer;
}

// ������ ������ ���� �ð��� ���� ������, ��������� �Լ� �ʱ⿡ �ִ� �ڵ尡 �� ���� �ɸ��� ������ ���δ�.
// �����͸� �÷��� Ȯ���� ���� ���� ���ڴ�.

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