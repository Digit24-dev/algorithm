#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;

    //sort(arr.begin(), arr.end());
    answer = lcm(arr[0], arr[1]);

    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        answer = lcm(*i, answer);
    }
    
    return answer;
}

void main()
{

    cout << solution({2,6,8,14 }) << endl;

}

/*
* 
* // 유클리드 호제법 https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95
int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
int lcm(int x, int y) { return x * y / gcd(x, y); }
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);
    return answer;
}
*/