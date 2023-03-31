#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 윗 동 서 남 북 밑
int dice[6] = {0, 0, 0, 0, 0, 0};
int map[20][20];

void roll(int dir){
    int bucket[6];
    switch (dir)
    {
        case 1: // east
            bucket[0] = dice[2];
            bucket[1] = dice[0];
            bucket[2] = dice[5];
            bucket[3] = dice[3];
            bucket[4] = dice[4];
            bucket[5] = dice[1];
            memcpy(dice, bucket, sizeof(dice));
            break;
        case 2: // west
            bucket[0] = dice[1];
            bucket[1] = dice[5];
            bucket[2] = dice[0];
            bucket[3] = dice[3];
            bucket[4] = dice[4];
            bucket[5] = dice[2];
            memcpy(dice, bucket, sizeof(dice));
            break;
        case 3: // north
            bucket[0] = dice[3];
            bucket[1] = dice[1];
            bucket[2] = dice[2];
            bucket[3] = dice[5];
            bucket[4] = dice[0];
            bucket[5] = dice[4];
            memcpy(dice, bucket, sizeof(dice));
            break;
        case 4: // south
            bucket[0] = dice[4];
            bucket[1] = dice[1];
            bucket[2] = dice[2];
            bucket[3] = dice[0];
            bucket[4] = dice[5];
            bucket[5] = dice[3];
            memcpy(dice, bucket, sizeof(dice));
            break;
        default:
            break;
    }
}

void copy(int x, int y){
    if(map[x][y] == 0){
        map[x][y] = dice[5];
    }else{
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
}

int main(){
    int N, M;
    int x, y, order;
    int temp;

    cin >> N >> M >> x >> y >> order;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (size_t i = 0; i < order; i++)
    {
    	bool flag = false;
        cin >> temp;
        switch (temp)
        {
        case 1:
            if(y+1 >= M)
                flag = true;
            else{
            	roll(temp);
            	copy(x, y+1);
            	y = y+1; 
			}
            break;
        case 2:
            if(y-1 < 0)
                flag = true;
            else{
                roll(temp);
                copy(x, y-1);
                y = y-1;
            }
            break;
        case 3:
            if(x-1 < 0)
                flag = true;
            else{
                roll(temp);
                copy(x-1, y);
                x = x-1;
            }
            break;
        case 4:
            if(x+1 >= N)
                flag = true;
            else{
                roll(temp);
                copy(x+1, y);
                x = x+1;
            }
            break;
        default:
            break;
        }
        if(flag)
        	continue;
         cout << dice[0] << endl;
        
    }
    
    return 0;
}