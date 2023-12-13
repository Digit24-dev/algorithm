#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m; //옷의 종류를 key 해당 종류의 수를 value로 하는 map함수
    vector<string> v; //옷의 종류를 저장해놓을 벡터함수
    for (int i = 0; i < clothes.size(); i++)
    {
        if (m[clothes[i][1]] == 0) { //처음 나오는 옷의 종류라면
            m[clothes[i][1]] = 1;
            v.push_back(clothes[i][1]);
        }
        else
        {
            m[clothes[i][1]]++;
        }
    }
    int result = 1;
    for (int i = 0; i < v.size(); i++)
    {
        result *= (m[v[i]] + 1);
    }
    return result - 1;
}