#include <iostream>

#include <vector>
#include <memory.h>
#include <string>
#include <stack>

#define endl '\n'
#define MAX_MAP 25
using namespace std;

int answer = 0;

int n, m;
int d, p;

int player;

int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };

int map[MAX_MAP][MAX_MAP];

vector<pair<int, int>> rounds;

vector<int> serialized;

vector<pair<int, int>> attacked;

void printMap() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

bool isRanged(int ni, int nj) {
    if (ni < 0 || ni >= n || nj < 0 || nj >= n) return false;
    else return true;
}

void input() 
{
    cin >> n >> m;
    player = n / 2;
    rounds.resize(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> d >> p;
        rounds[i] = make_pair(d, p);
    }
}

void printSerializedData(string str)
{
    cout << str << " ====== SER DATA ====== " << endl;

    for (size_t i = 0; i < serialized.size(); i++)
    {
        cout << serialized[i] << " ";
    }
    cout << endl;
}

void serialize()
{
    int ni = player;
    int nj = player - 1;
    int cnt = 0;
    int g = 1;
    int dir = 1;

    serialized.clear();

    while (isRanged(ni, nj))
    {
        if (serialized.size() >= (n * n) - 1) break;
        bool flag = false;
        if (map[ni][nj] == 0)
            flag = true;

        if (!attacked.empty() && ni == attacked[0].first && nj == attacked[0].second)
        {
            attacked.erase(attacked.begin());
            flag = true;
        }

        if (!flag) {
            serialized.push_back(map[ni][nj]);
        }

        // ���� �Ǵ�
        if (cnt == g)
        {
            dir = dir - 1 < 0 ? 3 : dir - 1;
            cnt = 0;

            if (dir == 0 || dir == 2)
                ++g;
        }

        ni += di[dir];
        nj += dj[dir];
        cnt++;
    }
}

void attack(int idx)
{
    int d = rounds[idx].first;
    int c = rounds[idx].second;
    int ni = player + di[d];
    int nj = player + dj[d];

    while (c--)
    {
        attacked.push_back(make_pair(ni, nj));
        answer += map[ni][nj];
        ni += di[d];
        nj += dj[d];
    }
}

bool removing()
{
    bool isRemoved = false;
    pair<int, int> chk = {serialized[0], 1};  // f: num, s: cnt;
    for(int i = 1; i < serialized.size(); i++)
    {
        if (chk.first == serialized[i]) {
            ++chk.second;
        }
        else {
            if (chk.second >= 4)
            {
                // ** �� �������� �̹� idx �� ���� ����. 6->2
                isRemoved = true;
                answer += chk.first * chk.second;
                serialized.erase(serialized.begin() + i - chk.second, serialized.begin() + i);
                
                i -= chk.second;
            }
            
            chk.first = serialized[i];
            chk.second = 1;
        }
    }
    if (chk.second >= 4){
        while (chk.first == serialized.back())
        {
            serialized.pop_back();
            answer += chk.first;
        }
    }
    return isRemoved;
}

vector<int> pairing()
{
    vector<int> temp;
    int cnt = 1;
    int was = serialized[0];

    for (int i = 1; i < serialized.size(); i++)
    {
        if (was == serialized[i]) {
            cnt++;
        }
        else {
            temp.push_back(cnt);
            temp.push_back(was);
            was = serialized[i];
            cnt = 1;
        }
    }
    
    temp.push_back(cnt);
    temp.push_back(was);
    
    return temp;
}

void deserialize()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
        }
    }

    int ni = player;
    int nj = player - 1;
    int idx = 0;
    int cnt = 0;
    int g = 1;
    int dir = 1;

    // ��� ���� �߻�
    while (idx < serialized.size())
    {
        map[ni][nj] = serialized[idx++];
        if (ni == 0 && nj == 0) break;

        // ���� �Ǵ�
        if (cnt == g)
        {
            dir = dir - 1 < 0 ? 3 : dir - 1;
            cnt = 0;

            if (dir == 0 || dir == 2)
                ++g;
        }

        ni += di[dir];
        nj += dj[dir];
        
        cnt++;
    }
}

void solution()
{
    int round = 0;
    while (round < m)
    {
        // 1. attack
        attack(round);

        // 2. fill
        serialize();

        // 3. remove 4
        while (removing());

        // 4. pair
        vector<int> temp(pairing());
        serialized.clear();
        serialized.swap(temp);

        // 5. deserialize
        deserialize();

        ++round;
        attacked.clear();
    }
}

int main() {

    cin.tie(NULL); ios_base::sync_with_stdio(0);
    
    input();

    solution();

    cout << answer << endl;

    return 0;
}


/*
// Ʋ�� �κ� ����

// 1. vector .erase �ε��� Ȯ��

// 2. �޸� �ʰ��� �κп� ���� ó�� ����

// 3. ��� �κп��� �߻��ϴ� ������ ó�� ����.
//  - ó���� ������ �κп��� �߻��ϴ� ����.
// 3.1 pairing
//  - ���ϴ� ���� �ְ� ���� ������ �κп��� ���� ���� ó�� ����.

// 3.2 removing
//  - ����� ���� �� ������ �κ��� ����. (������ �κп��� 4�� �̻��� ���� ��Ȳ �߻��� ó�� ����.)
*/