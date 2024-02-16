#include <iostream>

#include <string>
#include <vector>

using namespace std;

// го ©Л ╩С
int di[3] = {1, 0, -1};
int dj[3] = {0, 1, -1};
int map[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    int total = ((n + 1) * n) / 2;
    int box_num = 1;
    int dir_cnt = 1;
    int dist = n;
    int dir = 0;
    answer.reserve(total);

    // fill
    pair<int, int> cord = make_pair(0, 0);

    while (total--)
    {
        map[cord.first][cord.second] = box_num++;

        if (dir_cnt == dist) {
            --dist; dir_cnt = 0;
            dir = ++dir % 3;
        }

        cord = make_pair(cord.first + di[dir], cord.second + dj[dir]);
        dir_cnt++;
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            answer.push_back(map[i][j]);
        }
    }

    return answer;
}

int main() {

    vector<int> ret = solution(6);

    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}