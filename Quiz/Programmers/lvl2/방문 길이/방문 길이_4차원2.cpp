#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool path[11][11][11][11];

int trans(char s) {
    int n;
    switch(s) {
        case 'U':
            n = 0;
            break;
        case 'D':
            n = 1;
            break;
        case 'R':
            n = 2;
            break;
        case 'L':
            n = 3;
            break;
    }
    return n;
}

int solution(string dirs)
{ 
    int answer = 0;

    int x = 5;
    int y = 5;

    for(int i = 0; i < dirs.size(); i++) {
        int j = trans(dirs[i]);

        int mx = x + dx[j];
        int my = y + dy[j];

        if(mx < 0) {
            mx = 0;
        }
        else if(mx > 10) {
            mx = 10;
        }

        if(my < 0) {
            my = 0;
        }
        else if(my > 10) {
            my = 10;
        }


        if(x == mx && y == my) {
            continue;
        }

        if(path[x][y][mx][my] == false && path[mx][my][x][y] == false) {
            path[x][y][mx][my] = true;
            path[mx][my][x][y] = true;
            answer++;
        }

        x = mx;
        y = my;
    }

    return answer;
}