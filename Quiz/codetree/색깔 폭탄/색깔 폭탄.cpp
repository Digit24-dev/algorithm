#include <iostream>
#include <vector>

#define MAX_N 21
#define MAX_M 5

using namespace std;

int m,n;
int map[MAX_N][MAX_N];

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
}

void gravity(){
    for(int i=0; i < n; i++)
    {
        for(int k=0; k < n - 1; k++){
            if (map[n-1 + k][i] == -1){            // 돌일 경우
                continue;
            }else{                                 // 돌 아닐 경우
                // 다음 위치도 돌 아닐 경우 내려오게 함.
                if (map[n-1 + k + 1][i] != -1){
                    map[n-1 + k + 1][i] = -2;
                    map[n-1 + k][i] = map[n-1 + k + 1][i];
                }
            }
        }
    }
}

void rotate()
{
    int start = 0;
    int end = n;

    while(start < end){
        int last_piece = map[start][start];
        // top
        for(int i=start; i<end; i++){
            map[start][i] = map[start][i+1];
        }
        // right
        for(int i=start; i<end; i++){
            map[i][end] = map[i+1][end];
        }
        // bottom
        for(int i=end-1; i>=start; i--){
            map[end][i] = map[end][i-1];
        }
        // left
        for(int i=end-1; i>start; i--){
            map[i][start] = map[i-1][start];
        }
        map[start+1][start] = last_piece;
        start++;
        end--;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    // -2    : 빈 칸
    // -1    : 검은색
    // 0     : 빨간색
    // 1 ~ m : 빨간색과 다른 서로 다른 색의 폭탄

    // 폭탄 묶음 없을 떄까지 밑 반복
    // 1. 가장 크기가 큰 폭탄 묶음 찾기 (2개 이상의 폭탄, 같은 색깔의 폭탄으로만 이루어져있거나 빨간색 폭탄을 포함한 정확히 2개의 색깔로만 이루어진 폭탄)
      // 완전 탐색으로 찾기..
    // 2.  빨간색 -> 폭탄 x, 격자 상에서 연결되어 있어야 함. (폭탄 묶음 내 상하좌우 인접한 곳)

    // 폭탄 크기
    // 1. 빨간색 폭탄이 가장 적은 묶음
    // 2. 기준점? 중 행이 가장 큰 폭탄 (빨간색 아니고 행이 가장 큰 칸, if 행==행, 열 이 가장 작은 칸)
    // 3. 기준점 열이 가장 작은 묶음

    // 폭탄 제거 (돌 빼고 모두 아래로) <============================

    // 반 시계 90도 회전 <==============================

    // 중력 <======================================

    // 터진 폭탄의 수 C, 점수 = C * C

    // 터진 폭탄 없을 떄까지 반복


    return 0;
}