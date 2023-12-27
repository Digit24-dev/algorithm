#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    int correct = 0;
    int z_cnt = 0;
    int d[7] = { 6, 6, 5, 4, 3, 2, 1 };
    for (auto& i : lottos)
    {
        if (i == 0)
            ++z_cnt;
    }

    for (auto& i : win_nums)
    {
        for (auto& lotto : lottos)
        {
            if (i == lotto)
                ++correct;
        }
    }

    answer.push_back(d[correct + z_cnt]);
    answer.push_back(d[correct]);

    return answer;
}

int main() {
    vector<int> ret = solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 });
    vector<int> ret2 = solution({ 0, 0, 0, 0, 0, 0 }, { 38, 19, 20, 40, 15, 25 });
    vector<int> ret3 = solution({ 45, 4, 35, 20, 3, 9 }, { 20, 9, 3, 45, 4, 35 });

    for (auto& i : ret3)
    {
        cout << i << " ";
    }
    cout << endl;
}