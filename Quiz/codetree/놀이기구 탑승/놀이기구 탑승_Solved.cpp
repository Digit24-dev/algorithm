#include <iostream>

#include <vector>
#include <algorithm>
#include <cmath>

#include <tuple>

#define MAX 20
#define EMPTY 0
#define MAX_NUM 400
#define DIR_NUM 4

using namespace std;

typedef tuple<int, int, int, int> Cell;

int n, nn;

// 놀이기구
int attraction[MAX + 1][MAX + 1];

// 친구 관계 맵
bool friends[MAX_NUM + 1][MAX_NUM + 1];

// 순서 저장할 배열
int target[MAX_NUM + 1];

// 상 우 하 좌
int di[DIR_NUM] = { -1, 0, 1, 0 };
int dj[DIR_NUM] = { 0, 1, 0, -1 };

bool isRanged(int i, int j)
{
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

bool isFriend(int num1, int num2)
{
    return friends[num1][num2];
}

void input()
{
    cin >> n;
    nn = n * n;

    for (int i = 1; i <= nn; i++)
    {
        cin >> target[i];

        for (int j = 0; j < 4; j++)
        {
            int friend_num;
            cin >> friend_num;

            // 친구 관계 맵에 저장
            friends[target[i]][friend_num] = true;
        }
    }
}

Cell GetCurCell(int num, int i, int j)
{
    int cnt_f = 0, cnt_b = 0;
    for (int dir = 0; dir < DIR_NUM; dir++)
    {
        int ni = i + di[dir], nj = j + dj[dir];

        if (!isRanged(ni, nj)) continue;

        if (attraction[ni][nj] == EMPTY)
            ++cnt_b;
        else if (isFriend(num, attraction[ni][nj]))
            ++cnt_f;
    }

    return make_tuple(cnt_f, cnt_b, -i, -j);
}

void Move(int num)
{
    // 완탐
    Cell maxCell = make_tuple(0, 0, -(n + 1), -(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (attraction[i][j] == EMPTY) {
                Cell cur = GetCurCell(num, i, j);

                if (maxCell < cur)
                    maxCell = cur;
            }
        }
    }

    int i, j;
    tie(ignore, ignore, i, j) = maxCell;
    attraction[-i][-j] = num;
}

int getScore(int i, int j) {
    int cnt = 0;

    for (int dir = 0; dir < DIR_NUM; dir++)
    {
        int ni = i + di[dir], nj = j + dj[dir];
        if (isRanged(ni, nj) && isFriend(attraction[i][j], attraction[ni][nj]))
            ++cnt;
    }
    return (int)pow(10, cnt - 1);
}

int getTotalScore()
{
    int score = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            score += getScore(i, j);
        }
    }

    return score;
}

int solution()
{
    for (int i = 1; i <= nn; i++)
    {
        Move(target[i]);
    }

    return getTotalScore();
}

int main() {

    cin.tie(NULL); ios_base::sync_with_stdio(0);

    input();

    cout << solution();

    return 0;
}