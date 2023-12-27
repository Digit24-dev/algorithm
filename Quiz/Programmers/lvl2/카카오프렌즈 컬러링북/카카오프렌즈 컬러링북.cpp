#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int o_map[101][101];
bool visited[101][101];

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);

    // 전역 변수 초기화
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visited[i][j] = 0;
        }
    }

    // 맵 초기화
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            o_map[i][j] = picture[i][j];
        }
    }
    
    stack<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp_area_size = 1;

            if (o_map[i][j] == 0)
                continue;
            if (visited[i][j])
                continue;

            st.push(make_pair(i, j));
            number_of_area++;

            while (!st.empty())
            {
                pair<int, int> cord = st.top();
                st.pop();
                
                visited[cord.first][cord.second] = true;

                for (int dir = 0; dir < 4; dir++)
                {
                    int ni = cord.first + dx[dir];
                    int nj = cord.second + dy[dir];

                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;

                    if (o_map[ni][nj] == o_map[cord.first][cord.second] && !visited[ni][nj]) {
                        st.push(make_pair(ni, nj));
                        temp_area_size++;
                        visited[ni][nj] = true;
                    }
                }
            }
            max_size_of_one_area = max_size_of_one_area > temp_area_size ? max_size_of_one_area : temp_area_size;
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    vector<vector<int>> pic;
    //pic = { {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} };
    pic = { {0,1,0},{1,1,0},{0,0,0} };
    vector<int> ans = solution(3, 3, pic);

    cout << ans[0] << " " << ans[1] << endl;
}