#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int ret_i = arr1.size();
    int ret_j = arr2[0].size();

    answer.resize(ret_i);
    for (size_t i = 0; i < ret_i; i++)
    {
        answer[i].resize(ret_j);
    }

    for (size_t i = 0; i < arr1.size(); i++)
    {
        for (size_t j = 0; j < arr2[0].size(); j++)
        {
            int sum = 0;
            for (size_t k = 0; k < arr2.size(); k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }

    return answer;
}

int main()
{
    //vector<vector<int>> ret = solution({ {1,4},{3,2},{4,1} }, { {3,3},{3,3} });
    vector<vector<int>> ret = solution({ {2, 3, 2}, {4, 2, 4}, {3, 1, 4} }, { {5, 4, 3}, {2, 4, 1}, {3, 1, 1} });

    for (auto& i : ret)
    {
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}