#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define LINE_SIZE 101
#define DO_R 0
#define DO_C 1


unordered_map<int, int> maps;

//vector<pair<int, int>> map;
int A[102][102];
int num_cnt[101];
int cnt_r = 3, cnt_c = 3;
bool mode = false; // 0: R 연산, 1: C 연산
int ans = 0;
int r, c, k;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

void sorting(bool mode) {
    if (!mode)
    {
        // R연산
        for (size_t i = 0; i < cnt_c; i++)
        {
            for (size_t j = 0; j < cnt_r; j++)
            {
                if (A[i][j] == 0)
                    continue;
                if (maps.find(A[i][j]) != maps.end()) {
                    maps[A[i][j]] += 1;
                }
                else {
                    maps.insert(make_pair(A[i][j], 1));
                }
            }
            
            sort(maps.begin(), maps.end(), cmp);

            int rot = 0;
            for (unordered_map<int,int>::iterator iter=maps.begin(); iter!= maps.end(); iter++)
            {
                if (rot + 2 > 100)
                    break;
                A[i][rot++] = iter->first;
                A[i][rot++] = iter->second;
            }
            
            A[i][101] = rot;

            maps.clear();
        }

        int max = 0;
        // 0 채우기
        for (size_t i = 0; i < cnt_c; i++)
        {
            max = max > A[i][101] ? max : A[i][101];
        }
        for (int y = 0; y < cnt_c; y++)
        {
            for (int d = A[y][101]; d < max; d++)
            {
                A[y][d] = 0;
            }
        }
        cnt_r = max;
    }
    else {
        // C연산
        for (size_t i = 0; i < cnt_r; i++)
        {
            for (size_t j = 0; j < cnt_c; j++)
            {
                if (A[j][i] == 0)
                    continue;
                if (maps.find(A[i][j]) != maps.end()) {
                    maps[A[i][j]] += 1;
                }
                else {
                    maps.insert(make_pair(A[i][j], 1));
                }
            }
            
            sort(maps.begin(), maps.end(), cmp);

            int rot = 0;
            for (unordered_map<int, int>::iterator iter = maps.begin(); iter != maps.end(); iter++)
            {
                if (rot + 2 > 100)
                    break;
                A[rot++][i] = iter->first;
                A[rot++][i] = iter->second;
            }
            
            A[101][i] = rot;

            maps.clear();
        }

        int max = 0;
        // 0 채우기
        for (size_t i = 0; i < cnt_c; i++)
        {
            max = max > A[101][i] ? max : A[101][i];
        }
        for (int y = 0; y < cnt_c; y++)
        {
            for (int d = A[101][y]; d < max; d++)
            {
                A[d][y] = 0;
            }
        }
        cnt_c = max;
    }
}

int solution() {
    if (cnt_r >= cnt_c) {
        mode = DO_R;
    }
    else {
        mode = DO_C;
    }
    sorting(mode);

    if (A[r][c] == k)
        return ans;
    if (ans > 100)
        return -1;
    
    ans++;
}

int main() {
    // 입력
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
        A[i][101] = 3;
        A[101][i] = 3;
    }

    cout << solution();

    return 0;
}
