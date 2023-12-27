#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b){
    // 조건 제대로 읽어보고, 그냥 넘어가지 말자. 비교하는 구문에서 value 값이 같고, vector의 key가 순서대로 배열되어 있지 않다면 return 조건에서 큰 것이 앞에 오는 경우가 발생할 수도 있다.
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int attempt[502] = {0, };
    int success[502] = {0, };

    vector<pair<int, double>> fail;

    for(int i=0; i<stages.size(); ++i){
        int j;
        for(j=1; j<stages[i]; ++j){
            ++attempt[j];
            ++success[j];
        }
        ++attempt[j];
    }
    
    for(int i=1; i<N+1; ++i){
        // 조건을 반드시 눈여겨 보자. 0으로 나눌때 attempt가 0인 경우를 자동으로 에러처리 해준다면, 논리적 오류를 발견하지 못할 수 있다.
        if(attempt[i] == 0)
            fail.push_back(make_pair(i, 0));
        else
            fail.push_back(make_pair(i, (double)(attempt[i] - success[i]) / attempt[i]));
    }
    
    sort(fail.begin(), fail.end(), cmp);
    
    for(vector<pair<int, double>>::iterator iter=fail.begin(); iter!=fail.end(); ++iter){
        answer.push_back(iter->first);
    }

    return answer;
}