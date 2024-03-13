#include <iostream>
#include <vector>
#include <tuple>
#include <memory.h>

#define MAX_N 21
#define MAX_M 5

using namespace std;

int m, n;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int score = 0;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
/// <summary>
/// 폭탄, 빨간색, 행, 열
/// </summary>
typedef tuple<int, int, int, int> node;

vector<pair<int, int>> temp;
vector<pair<int, int>> BOMB;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
}

void gravity() {
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - 1; k++) {
            if (map[n - 1 + k][i] == -1) {            // 돌일 경우
                continue;
            }
            else {                                 // 돌 아닐 경우
               // 다음 위치도 돌 아닐 경우 내려오게 함.
                if (map[n - 1 + k + 1][i] != -1) {
                    map[n - 1 + k][i] = map[n - 1 + k + 1][i];
                    map[n - 1 + k + 1][i] = -2;
                }
            }
        }
    }
}

void rotate()
{
    int start = 0;
    int end = n;

    while (start < end) {
        int last_piece = map[start][start];
        // top
        for (int i = start; i < end; i++) {
            map[start][i] = map[start][i + 1];
        }
        // right
        for (int i = start; i < end; i++) {
            map[i][end] = map[i + 1][end];
        }
        // bottom
        for (int i = end - 1; i > start; i--) {
            map[end][i] = map[end][i - 1];
        }
        // left
        for (int i = end - 1; i > start; i--) {
            map[i][start] = map[i - 1][start];
        }
        map[start + 1][start] = last_piece;
        start++;
        end--;
    }
}

bool isRanged(int i, int j) {
    return i >= 0 && i < n&& j >= 0 && j < n;
}

/// <summary>
/// DFS without red
/// </summary>
/// <param name="ci">: i</param>
/// <param name="cj">: j</param>
/// <param name="color">: 색깔</param>
node dfs_withoutRed(int ci, int cj, int color)
{
    // 기준점 찾는 방법... 찾은 기준점을 전달하는 방법...
    // 기준점
    int ri = ci, rj = cj;
    int bomb = 1;

    for (int dir = 0; dir < 4; dir++)
    {
        int ni = ci + di[dir];
        int nj = cj + dj[dir];

        if (isRanged(ni, nj)) {
            if (map[ni][nj] == color) {
                bomb++;
                visited[ni][nj] = true;
                temp.push_back(make_pair(ni, nj));
                dfs_withoutRed(ni, nj, color);

                // 기준점
                if (ni > ri) {
                    ri = ni; rj = nj;
                }
                else if (ri == ni && nj < rj) {
                    ri = ni, rj = nj;
                }
            }
        }
    }
    memset(visited, false, sizeof(visited));
    node ret = make_tuple(bomb, 0, ri, -rj);

    return ret;
}

node dfs_withRed(int ci, int cj, int color)
{
    int ri = ci, rj = cj;
    int bomb = 1, reds = 0;

    for (int dir = 0; dir < 4; dir++)
    {
        int ni = ci + di[dir];
        int nj = cj + dj[dir];

        if (isRanged(ni, nj)) {
            if (map[ni][nj] == color || map[ni][nj] == 0) {
                if (map[ni][nj] == 0) reds++;
                else bomb++;

                temp.push_back(make_pair(ni, nj));
                visited[ni][nj] = true;
                dfs_withRed(ni, nj, color);

                // 기준점
                if (ni > ri) {
                    ri = ni; rj = nj;
                }
                else if (ri == ni && nj < rj) {
                    ri = ni, rj = nj;
                }
            }
        }
    }

    memset(visited, false, sizeof(visited));
    node ret = make_tuple(bomb, 0, ri, -rj);

    return ret;
}

bool find()
{
    node theBomb = make_tuple(0, 0, 0, 0);
    // tie(ignore, , -, -) = ;

    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 현재 칸의 정보
            int cur_Color = map[i][j];

            // 현재 상태 정보 - 같은 색깔 상태 1, 빨간색 폭탄을 포함한 정확히 2개의 색 상태
            int status = 0;

            if (cur_Color < 1) continue;

            // dfs without Red
            node T = dfs_withoutRed(i, j, cur_Color);
            if (theBomb < T) {
                theBomb = T;
                BOMB = temp;
                temp.clear();
            }

            // dfs with Red
            T = dfs_withRed(i, j, cur_Color);
            if (theBomb < T) {
                theBomb = T;
                BOMB = temp;
                temp.clear();
            }
        }
    }

    int _;
    tie(_, ignore, ignore, ignore) = theBomb;

    if (_ >= 2) flag = true;

    return flag;
}

void kaboom()
{
    score += BOMB.size();

    for (auto& cord : BOMB)
    {
        map[cord.first][cord.second] = -2;
    }
}

void solution()
{
    input();

    while (find())
    {
        kaboom();

        gravity();

        rotate();

        gravity();
    }

    cout << score << endl;
}

int main() {

    // -2    : 빈 칸
    // -1    : 검은색
    // 0     : 빨간색
    // 1 ~ m : 빨간색과 다른 서로 다른 색의 폭탄

    // 폭탄 묶음 없을 떄까지 밑 반복
    // 1. 가장 크기가 큰 폭탄 묶음 찾기 (2개 이상의 폭탄, 같은 색깔의 폭탄으로만 이루어져있거나 빨간색 폭탄을 포함한 정확히 2개의 색깔로만 이루어진 폭탄)
      // 완전 탐색으로 찾기..
    // 2.  빨간색만 -> 폭탄 x, 격자 상에서 연결되어 있어야 함. (폭탄 묶음 내 상하좌우 인접한 곳)

    // 폭탄 크기
    // 1. 빨간색 폭탄이 가장 적은 묶음
    // 2. 기준점? 중 행이 가장 큰 폭탄 (빨간색 아니고 행이 가장 큰 칸, if 행==행, 열 이 가장 작은 칸)
    // 3. 기준점 열이 가장 작은 묶음

    // 폭탄 제거 (돌 빼고 모두 아래로) <============================

    // 반 시계 90도 회전 <==============================

    // 중력 <======================================

    // 터진 폭탄의 수 C, 점수 = C * C

    // 터진 폭탄 없을 떄까지 반복
    solution();


    return 0;
}