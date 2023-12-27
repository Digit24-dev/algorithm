#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define LINE_SIZE 101

struct myMap
{
    int num, cnt;
};

vector<pair<int, int>> map;

int A[101][101];
int num_cnt[101];
int cnt_r=3, cnt_c=3;
bool mode = false; // 0: R 연산, 1: C 연산
int ans = 0;
int r,c,k;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

void sorting(bool mode){
    if (!mode)
    {
        // R연산
        for (size_t i = 1; i < cnt_c; i++)
        {
            for (size_t j = 1; j < cnt_r; j++)
            {
                if(A[i][j] == 0)
                    continue;
                num_cnt[A[i][j]]++;
            }
            for (int d = 1; d < 101; d++)
            {
                if(num_cnt[d] != 0){
                    map.push_back(make_pair(d, num_cnt[d]));
                }
            }
            sort(map.begin(),map.end(), cmp);
            int rot=0;
            for (vector<pair<int,int>>::iterator iter=map.begin(); iter!=map.end(); iter++)
            {
                A[i][rot++] = iter->first;
                A[i][rot++] = iter->second;
            }
            A[i][101] = rot;

            memcpy(num_cnt, 0, sizeof(num_cnt));
            map.clear();
        }
        
        int max = 0;
        // 0 채우기
        for (size_t i = 0; i < cnt_c; i++)
        {
            max = max > A[i][101] ? max : A[i][101];
        }
        for (size_t i = 0; i < cnt_c; i++)
        {
            for (size_t d = A[i][101]; d < max; d++)
            {
                A[i][d] = 0;
            }
        }
        cnt_r = max;
    }else{
        // C연산
        for (size_t i = 0; i < cnt_r; i++)
        {
            for (size_t j = 0; j < cnt_c; j++)
            {
                if(A[j][i] == 0)
                    continue;
                num_cnt[A[j][i]]++;
            }
            for (int d = 1; d < 101; d++)
            {
                if(num_cnt[d] != 0){
                    map.push_back(make_pair(d, num_cnt[d]));
                }
            }
            sort(map.begin(),map.end(), cmp);
            int rot=0;
            for (vector<pair<int,int>>::iterator iter=map.begin(); iter!=map.end(); iter++)
            {
                A[rot++][i] = iter->first;
                A[rot++][i] = iter->second;
            }
            A[101][i] = rot;

            memcpy(num_cnt, 0, sizeof(num_cnt));
            map.clear();
        }
        
        int max = 0;
        // 0 채우기
        for (size_t i = 0; i < cnt_c; i++)
        {
            max = max > A[101][i] ? max : A[101][i];
        }
        for (size_t i = 0; i < cnt_c; i++)
        {
            for (size_t d = A[101][i]; d < max; d++)
            {
                A[d][i] = 0;
            }
        }
        cnt_c = max;
    }
}

int solution(){
    if(cnt_r>=cnt_c){
        mode = false;
    }else{
        mode = true;
    }
    sorting(mode);
    
    ans++;
    
    if(A[r][c] == k)
        return ans;
    if(ans > 100)
        return -1;
}

int main(){
    // 입력
    cin>>r>>c>>k;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
        A[i][101] = 3;
        A[101][i] = 3;
    }

    cout << solution();

    return 0;
}