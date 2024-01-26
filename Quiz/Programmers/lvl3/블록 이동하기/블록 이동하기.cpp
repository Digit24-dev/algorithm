#include <iostream>

#include <string>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

int map[101][101];
bool visited[101][101][4];
int target;

// 동 남 서 북
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

struct roboState    // 항상 로봇의 왼쪽 위를 기준으로 한다.
{
    int i;
    int j;
    bool state;
};

inline bool movable(roboState state, int dir, vector<vector<int>>& board) {
    int ni = state.i + di[dir];
    int nj = state.j + dj[dir];

    if (state.state) {
        switch (dir)
        {
        case 0:
            if (ni + 1 > target) return false;
            if (board[ni + 1][nj] == 0 && board[ni][nj] == 0) return true;
            else return false;
            break;
        case 1:
            if (ni + 1 > target) return false;
            if (board[ni + 1][nj] == 0 && board[ni][nj] == 0) return true;
            else return false;
            break;
        case 2:
            if (ni + 1 > target) return false;
            if (board[ni + 1][nj] == 0 && board[ni][nj] == 0) return true;
            else return false;
            break;
        case 3:
            if (board[ni][nj] == 0) return true;
            break;
        }
    }
    else {
        switch (dir)
        {
        case 0:
            if (nj + 1 > target) return false;
            if (board[ni][nj + 1] == 0 && board[ni][nj] == 0) return true;
            else return false;
            break;
        case 1:
            if (nj + 1 > target) return false;
            if (board[ni][nj + 1] == 0 && board[ni][nj] == 0) return true;
            else return false;
            break;
        case 2:
            if (board[ni][nj] == 0) return true;
            break;
        case 3:
            if (nj + 1 > target) return false;
            if (board[ni][nj + 1] == 0 && board[ni][nj] == 0) return true;
            else return false;
            break;
        }
    }
}

// 0: 기준점 시계, 1: 기준점 반시계, 2: 반대 시계, 3: 반대 반시계
inline bool rotatble(roboState state, int rot, vector<vector<int>>& board) {
    if (state.state)    // 세로
    {
        switch (rot)
        {
        case 0:
            if (state.i + 1 > target || state.j - 1 < 0) return false;
            if (board[state.i][state.j - 1] == 0 && board[state.i + 1][state.j - 1] == 0 && board[state.i + 1][state.j] == 0) return true;
            else return false;
            break;
        case 1:
            if (state.i + 1 > target || state.j + 1 > target) return false;
            if (board[state.i][state.j + 1] == 0 && board[state.i + 1][state.j + 1] == 0 && board[state.i + 1][state.j] == 0) return true;
            else return false;
            break;
        case 2:
            if (state.i + 1 > target || state.j + 1 > target) return false;
            if (board[state.i][state.j + 1] == 0 && board[state.i + 1][state.j + 1] == 0 && board[state.i + 1][state.j] == 0) return true;
            else return false;
            break;
        case 3:
            if (state.i + 1 > target || state.j - 1 < 0) return false;
            if (board[state.i][state.j - 1] == 0 && board[state.i + 1][state.j - 1] == 0 && board[state.i + 1][state.j] == 0) return true;
            else return false;
            break;
        }
    }
    else {              // 가로
        switch (rot)
        {
        case 0:
            if (state.i + 1 > target  || state.j + 1 > target) return false;
            if (board[state.i + 1][state.j] == 0 && board[state.i + 1][state.j + 1] == 0 && board[state.i][state.j + 1] == 0) return true;
            else return false;
            break;
        case 1:
            if (state.i - 1 < 0 || state.j + 1 > target) return false;
            if (board[state.i - 1][state.j] == 0 && board[state.i - 1][state.j + 1] == 0 && board[state.i][state.j + 1] == 0) return true;
            else return false;
            break;
        case 2:
            if (state.i - 1 < 0 || state.j + 1 > target) return false;
            if (board[state.i - 1][state.j] == 0 && board[state.i - 1][state.j + 1] == 0 && board[state.i][state.j + 1] == 0) return true;
            else return false;
            break;
        case 3:
            if (state.i + 1 > target || state.j + 1 > target) return false;
            if (board[state.i + 1][state.j] == 0 && board[state.i + 1][state.j + 1] == 0 && board[state.i][state.j + 1] == 0) return true;
            else return false;
            break;
        }
    }
}

inline void m_rotate(roboState& state, int rot) {
    if (state.state)
    {
        state.state = !state.state;
        switch (rot)
        {
        case 0:
            state.j -= 1;
            break;
        case 1:
            break;
        case 2:
            state.i += 1;
            break;
        case 3:
            state.i += 1;
            state.j -= 1;
            break;
        }
    }
    else {
        state.state = !state.state;
        switch (rot)
        {
        case 0:
            break;
        case 1:
            state.i -= 1;
            break;
        case 2:
            state.i -= 1;
            state.j += 1;
            break;
        case 3:
            state.j += 1;
            break;
        }
    }
}

int solution(vector<vector<int>> board) {

    target = board.size() - 1;

    roboState robot = { 0,0,false };
    queue<pair<roboState, int>> q;

    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board.size(); j++)
        {
            map[i][j] = INT32_MAX;
        }
    }
    memset(visited, false, sizeof(visited));

    // bfs
    q.push(make_pair(robot, 0));
    visited[0][0][robot.state] = true;
    while (!q.empty())
    {
        pair<roboState, int> cur = q.front(); q.pop();

        map[cur.first.i][cur.first.j] = min(cur.second, map[cur.first.i][cur.first.j]);

        // 이동 여부
        for (int dir = 0; dir < 4; dir++)
        {
            int ni = cur.first.i + di[dir];
            int nj = cur.first.j + dj[dir];

            // 기본적인 bfs 탐색
            if (visited[ni][nj][cur.first.state] && cur.second >= map[ni][nj]) continue;

            if (ni >= 0 && ni <= target && nj >= 0 && nj <= target && board[ni][nj] == 0) {
                if (movable(cur.first, dir, board)) {
                    q.push(make_pair(roboState{ ni,nj,cur.first.state }, cur.second + 1));
                    visited[ni][nj][cur.first.state] = true;
                }
            }
        }

        // 회전 여부
        for (int dir = 0; dir < 4; dir++)
        {
            if (rotatble(cur.first, dir, board)) 
            {
                roboState temp = cur.first;
                m_rotate(temp, dir);
                if (visited[temp.i][temp.j][temp.state] && cur.second > map[temp.i][temp.j]) continue;
                q.push(make_pair(temp, cur.second + 1));
                visited[temp.i][temp.j][temp.state] = true;
            }
        }
    }
    
    return min(map[target - 1][target], map[target][target - 1]);
}


int main() {
    //vector<vector<int>> param1 = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };
    vector<vector<int>> param2 = { {0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 0} };
    vector<vector<int>> param3 = { {0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0} };
    vector<vector<int>> param4 = { {0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 0} };
    vector<vector<int>> test_case_1 = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0}
    };
    /*vector<vector<int>> test_case = {
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0}
    };*/
    vector<vector<int>> test_case = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0,0,1},
        {0,0,1,0,0,0,1,0,1,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,1,0,0,1,0,0,0,1,0},
        {1,0,0,0,1,0,0,0,1,1},
        {0,0,0,1,1,1,1,1,1,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };


    cout << solution(test_case) << endl;
    for (size_t i = 0; i < test_case.size(); i++)
    {
        for (size_t j = 0; j < test_case.size(); j++)
        {
            cout << "\t" << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
