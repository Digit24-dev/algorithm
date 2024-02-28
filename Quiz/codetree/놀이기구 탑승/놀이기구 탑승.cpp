#include <iostream>

#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define MAX 20

using namespace std;

queue<int> tq;

struct info
{
    int i;
    int j;
    int loves;
    int vacant;
};

int n;

int attraction[MAX][MAX];
int order[MAX * MAX][5];
int lover[MAX * MAX][4];

// »ó ¿ì ÇÏ ÁÂ
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

bool visited[410];

int answer = 0;

bool isRanged(int ni, int nj)
{
    if (ni >= 0 && ni < n && nj >= 0 && nj < n) return true;
    else return false;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> order[i][j];
        }
    }

    for (size_t i = 0; i < n * n; i++)
    {
        for (size_t j = 1; j < 5; j++)
        {
            lover[order[i][0]][j - 1] = order[i][j];
        }
    }
}

void check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cur = attraction[i][j];
            int friendsNum = 0;

            for (int dir = 0; dir < 4; dir++)
            {
                int ni = i + di[dir];
                int nj = j + dj[dir];
                
                if (isRanged(ni, nj))
                {
                    for (int f = 0; f < 4; f++)
                    {
                        if (attraction[ni][nj] == lover[cur][f]) {
                            ++friendsNum;
                        }
                    }
                }
            }

            answer += pow(10, friendsNum - 1);
        }
    }
}

void ddbb()
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << "\t" << attraction[i][j];
        }
        cout << endl;
    }

    for (size_t i = 1; i < n * n ; i++)
    {
        if (!visited[i]) cout << i << " ";
    }
    cout << endl;
}

void solution()
{
    // 1. ¿ÏÅ½
    for (int prioStudent = 0; prioStudent < n*n; prioStudent++)
    {
        info maxNode{ 0,0,0,0 };
        // 1. ÀüÃ¼ Å½»ö
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (attraction[i][j] != 0) continue;

                info current;
                current.i = i;
                current.j = j;
                current.loves = 0;
                current.vacant = 0;

                for (int dir = 0; dir < 4; dir++)
                {
                    int ni = i + di[dir];
                    int nj = j + dj[dir];

                    if (isRanged(ni, nj)) {
                        if (attraction[ni][nj] == 0) {
                            ++current.vacant;
                            continue;
                        }

                        for (int f = 1; f < 5; f++)
                        {
                            if (attraction[ni][nj] == order[prioStudent][f])
                                ++current.loves;
                        }
                    }
                }

                // max °»½Å
                if (current.loves > maxNode.loves)
                    maxNode = current;
                else if (current.loves == maxNode.loves && current.vacant > maxNode.vacant) {
                    maxNode = current;
                }
                else if (current.vacant == maxNode.vacant && current.i < maxNode.i)
                    maxNode = current;
                else if (current.i == maxNode.i && current.j < maxNode.j)
                    maxNode = current;
                
            }
        }
        
        if (attraction[maxNode.i][maxNode.j] == 0)
        {
            attraction[maxNode.i][maxNode.j] = order[prioStudent][0];
            visited[order[prioStudent][0]] = true;
        }
        else
        {
            tq.push(order[prioStudent][0]);
        }
    }

    // ¸¶Áö¸·
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (attraction[i][j] == 0)
            {
                int cur = tq.front(); tq.pop();
                attraction[i][j] = cur;
            }
        }
    }

    check();
}

int main() {
    
    cin.tie(NULL); ios_base::sync_with_stdio(0);

    input();

    solution();

    ddbb();

    cout << answer << endl;

    return 0;
}