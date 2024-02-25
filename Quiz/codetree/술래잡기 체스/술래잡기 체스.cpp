#include <iostream>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 12시부터 반시계방향 정렬
int di[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int answer = 0;

/// <summary>
/// first: 순서, second: 방향
/// </summary>
pair<int, int> map[4][4];

// 스택에 방향과 달라진 맵을 전달

int input() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j].first >> map[i][j].second;
            map[i][j].second--;
        }
    }

    return map[0][0].first;
}

void moveThief(pair<int, int> _map[4][4])
{
    vector<pair<int, int>> dup;
    dup.reserve(16);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dup.push_back(_map[i][j]);
        }
    }

    sort(dup.begin(), dup.end());

    for (int i = 0; i < 16; i++)
    {
        if (dup[i].first == 0) continue;

        for (int d = 0; d < 8; d++)
        {
            int nd = dup[i].second + d == 7 ? 0 : dup[i].second + d;
            int ni = (i / 4) + di[nd];
            int nj = (i % 4) + dj[nd];

            if (ni >= 0 && ni < 4 && nj >= 0 && nj < 4) {
                if (_map[ni][nj].first != 0) {
                    swap(_map[ni][nj], _map[i / 4][i % 4]);
                    break;
                }
            }
        }
    }
}

vector<pair<int, int>> play(pair<int, int> _map[4][4], int player_i, int player_j, int &score)
{
    vector<pair<int, int>> ret;
    int ni = player_i, nj = player_j, cnt = 3;
    while (cnt--)
    {
        ni += map[player_i][player_j].second;
        nj += map[player_i][player_j].second;

        if (ni >= 0 && ni < 4 && nj >= 0 && nj < 4)
        {
            if (map[ni][nj].first != 0) {
                ret.push_back(make_pair(ni, nj));
                score += _map[ni][nj].first;
            }
        }
    }

    return ret;
}

void solution(pair<int,int> _map[4][4], int player_i, int player_j, int score) 
{
    // 1. 도둑말 이동
    pair<int, int> dup[4][4];
    pair<int, int> dup2[4][4];
    memcpy(dup, map, sizeof(map));
    
    moveThief(dup);

    // 2. 술래말 이동
    vector<pair<int, int>> q = play(dup, player_i, player_j, score);

    memcpy(dup2, dup, sizeof(dup));

    for (auto& i : q)
    {
        memcpy(dup, dup2, sizeof(dup2));
        solution(dup, i.first, i.second, score);
        answer = max(answer, score);
    }
}

int main() {

    int initScore = input();
    map[0][0].first = 0;

    solution(map, 0, 0, initScore);

    cout << answer << endl;

    return 0;
}