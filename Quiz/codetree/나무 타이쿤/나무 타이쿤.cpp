#include <iostream>

#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 15
#define MAX_M 100

int di[8] = { 0, -1,-1, -1, 0, 1, 1, 1  };
int dj[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int gi[4] = {-1, -1, 1, 1};
int gj[4] = {-1, 1, -1, 1};

int map[MAX_N][MAX_N];
bool injected[MAX_N][MAX_N];

int m, n, p, d;

vector<pair<int, int>> rules;   // p, d

vector<pair<int, int>> meds; // cord

void input()
{
    cin >> n >> m;
    rules.resize(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    meds.push_back(make_pair(n - 1, 0));
    meds.push_back(make_pair(n - 2, 0));
    meds.push_back(make_pair(n - 1, 1));
    meds.push_back(make_pair(n - 2, 1));

    for (int i = 0; i < m; i++)
    {
        cin >> d >> p;
        rules[i] = make_pair(p, d - 1);
    }
}

void move_meds(int num) {
    int pp = rules[num].first;
    int dd = rules[num].second;

    for (auto& elem : meds)
    {
        int ti = (elem.first + di[dd] * pp) % n;
        int tj = (elem.second + dj[dd] * pp) % n;
        elem.first = ti < 0 ? n + ti : ti;
        elem.second = tj < 0 ? n + tj : tj;
    }
}

void inject()
{
    while (!meds.empty())
    {
        int mi = meds[meds.size() - 1].first;
        int mj = meds[meds.size() - 1].second;

        // inject
        ++map[mi][mj];
        injected[mi][mj] = true;

        meds.pop_back();
    }
}

void growth()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (injected[i][j])
            {
                for (int k = 0; k < 4; k++)
                {
                    int ni = (i + gi[k]);
                    int nj = (j + gj[k]);
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

                    if (map[ni][nj] >= 1)
                        ++map[i][j];
                }
            }
        }
    }
}

void replace()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (injected[i][j])
            {
                injected[i][j] = false;
            }
            else
            {
                if (map[i][j] >= 2)
                {
                    map[i][j] -= 2;
                    meds.push_back(make_pair(i, j));
                }
            }
        }
    }
}

int solution() {
    int cnt = 0;
    while (cnt < m)
    {
        // 1. move as rule
        move_meds(cnt);
        // 2. inject
        inject();
        // 3. growth
        growth();
        // 4. replace
        replace();

        ++cnt;
    }
    
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt += map[i][j];
        }
    }
    return cnt;
}

int main() {
    
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    input();

    cout << solution() << endl;


    return 0;
}