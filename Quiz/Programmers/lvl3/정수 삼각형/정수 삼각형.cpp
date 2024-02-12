#include <iostream>

#include <string>
#include <vector>

using namespace std;

int dp[501][501] = { 0, };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int sum = 0;

    dp[0][0] = triangle[0][0];

    for (size_t i = 1; i < triangle.size(); i++)
    {
        for (size_t j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == triangle[i].size() - 1)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    for (size_t i = 0; i < triangle.size(); i++)
    {
        answer = max(dp[triangle.size() - 1][i], answer);
    }

    return answer;
}

int main() {
    vector<vector<int>> p = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };

    cout << solution(p) << endl;


    return 0;
}