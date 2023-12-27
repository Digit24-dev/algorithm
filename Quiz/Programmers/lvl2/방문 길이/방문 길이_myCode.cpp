#include <iostream>

#include <string>
using namespace std;

//           U   D  R  L
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

struct node {
    bool dir[4]; // UDRL
};

// visited 1, not 0
node map[11][11];
// 5, 5 zero point

int solution(string dirs) {

    int answer = 0;
    int i = 5, j = 5;
    int next_nodes;
    int ni, nj;

    for (auto& c : dirs)
    {
        switch (c)
        {
        case 'U':
            c = 0;
            next_nodes = 1;
            break;
        case 'D':
            c = 1;
            next_nodes = 0;
            break;
        case 'R':
            c = 2;
            next_nodes = 3;
            break;
        case 'L':
            c = 3;
            next_nodes = 2;
            break;
        default:
            break;
        }

        ni = i + di[c];
        nj = j + dj[c];

        if (ni > 10 || ni < 0 || nj > 10 || nj < 0)
            continue;

        if (!map[ni][nj].dir[next_nodes]) {
            map[i][j].dir[c] = 1;
            map[ni][nj].dir[next_nodes] = 1;
            ++answer;
        }
        i = ni;
        j = nj;
    }

    return answer;
}

int main() {
    string param = "LULLLLLLU";
    cout << solution(param) << endl;
}