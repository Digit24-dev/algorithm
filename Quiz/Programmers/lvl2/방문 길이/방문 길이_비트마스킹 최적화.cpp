#include <string>
using namespace std;

int MAP[11][11]={}; // -5 ~ 5 좌표 MAP
int r = 5, c = 5;   // 현재 위치 (0,0) => (5,5)
int dat[100]={};

// 방향 배열
int dr[] = {-1,1,0,0};
int dc[] = {0,0,1,-1};

int solution(string dirs) {
    int answer = 0;

    // 방향 배열용 인덱스
    dat['U'] = 0;
    dat['D'] = 1;
    dat['R'] = 2;
    dat['L'] = 3;

    for(int i=0; i<dirs.size(); i++){
        int nr = r + dr[dat[dirs[i]]];
        int nc = c + dc[dat[dirs[i]]];

        // 맵을 벗어나면 동작 안함
        if(nr < 0 || nr >= 11 || nc < 0 || nc >= 11) continue;

        // MAP[r][c] 가 0bxxxx의 형태로 
        // 각각 L R D U 를 지나간 적이 있는지 판단
        int check_bit = 1 << dat[dirs[i]];

        // 지나간 적이 없다면 지나갔다고 표시 해주며 카운트
        if(!(MAP[r][c] & check_bit)){
            int set_bit[2] = {check_bit,};
            set_bit[1] = dat[dirs[i]]%2 ? 
                (check_bit >> 1) : (check_bit << 1);

            MAP[r][c] |= set_bit[0];
            MAP[nr][nc] |= set_bit[1];
            answer++;

        }

        // 명령 수행하며 위치 업데이트
        r = nr;
        c = nc;
    }

    return answer;
}