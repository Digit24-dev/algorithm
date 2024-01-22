#include <iostream>


#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<vector<int>> dp(land.size());
    //int dp[100000][4];
    
    for (auto& i : land[0])
    {
        dp[0].push_back(i);
    }
    for (int i = 1; i < land.size(); i++)
    {
        dp[i].resize(4);
    }

    int prevMax;

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            prevMax = 0;
            for (int k = 0; k < 4; k++)
            {
                if (j == k) continue;
                prevMax = max(prevMax, dp[i - 1][k]);
            }
            dp[i][j] = land[i][j] + prevMax;
        }
    }

    for (auto& i : dp[dp.size() - 1])
    {
        answer = max(answer, i);
    }

    return answer;
}

int main() {
    vector<vector<int>> param = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };
    
    cout << solution(param) << endl;
}