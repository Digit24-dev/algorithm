#include <iostream>

#include <vector>

using namespace std;


// 12시부터 시계방향 정렬
int di[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dj[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

pair<int, int> map[4][4];   // f: 순서, s: dir

pair<pair<int, int>, int> player;   // cord, dir

int score = 0;

void input() {
    int N = 32;
    int t, i = 0, j = 0;

    while (N)
    {
        cin >> t;

        if (N & 0x01) {
            map[i][j].second = t;
            ++j;
        }
        else
            map[i][j].first = t;

        if (j == 3) {
            ++i; j = 0;
        }
        --N;
    }
}

void getRubber(int i, int j)
{
    score += map[i][j].first;
    player.first = make_pair(i, j);
    player.second = map[i][j].second;
}

pair<int, int> findRub()
{
    int ni = player.first.first + di[player.second];
    int nj = player.first.second + dj[player.second];

    ;
}

int main() {

    input();
    getRubber(0, 0);


    return 0;
}