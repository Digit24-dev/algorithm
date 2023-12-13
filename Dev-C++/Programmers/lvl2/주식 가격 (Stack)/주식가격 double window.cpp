#define MOD1
//#define MOD2

#ifdef MOD1
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();

    for (int i = 0; i < size; i++) {
        int time = 0;
        for (int j = i + 1; j < size; j++) {
            time++;
            if (prices[j] < prices[i] || j == size - 1) { //마지막에서 두번째 값은 만약 마지막 값이 더 크다면 push할 수가 없기때문에 조건에 추가
                answer.push_back(time);
                break;
            }
        }
    }

    answer.push_back(0); //마지막은 시간이 없음

    return answer;
}

#endif // MOD1

#ifdef MOD2
#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;
    for (int i = 0; i < prices.size(); i++) {
        count = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            //가격이 유지되는 동안
            if (prices[i] <= prices[j]) {
                count++;
            }
            else {
                count++;
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}
#endif // MOD2


int main()
{
    vector<int> ans = solution({ 1,2,3,2,3 });
    //vector<int> ans = solution({ 9, 8, 7, 6, 5 });

    for (auto& i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
