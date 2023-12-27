#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;

int left(int N){
    int r = N/2, c = N/2-1;
    int sand = map[r][c];
    cout << (int)(sand * 0.55) << endl;
    map[r][c-1] += (int)(sand * 0.55);
    map[r][c-2] += (int)(sand * 0.05);
    map[r-1][c-1] += (int)(sand * 0.1);
    map[r-1][c] += (int)(sand * 0.07);
    map[r-1][c+1] += (int)(sand * 0.01);
    map[r-2][c] += (int)(sand * 0.02);
    map[r+1][c-1] += (int)(sand * 0.1);
    map[r+1][c] += (int)(sand * 0.07);
    map[r+1][c+1] += (int)(sand * 0.01);
    map[r+2][c] += (int)(sand * 0.02);
}

int main(){

    int N, bucket;
    
    cin >> N;
    for(int i=0; i<N; ++i){
        vector<int> temp;
        for(int j=0; j<N; ++j){
            cin >> bucket;
            temp.push_back(bucket);
        }
        map.push_back(temp);
    }

    left(N);

    cout << endl;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}