#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    // a개 주면 b개 받음
    while (!(n < a))
    {
        answer += b * (n / a);
        n = b * (n / a) + n % a;
    }

    return answer;
}

int main()
{
    //cout << solution(2, 1, 20) << endl;
    cout << solution(10000, 9999, 100000) << endl;
    //cout << solution(3, 1, 20) << endl;
    cout << solution(3, 2, 20) << endl;
}

/*
???

int solution(int a, int b, int n) {
    return (n > b ? n - b : 0) / (a - b) * b;
}

*/