#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    int n = 625, k = 781;
    for (auto s : word){
        answer++;
        if (s == 'E') answer += k;
        else if (s == 'I') answer += k*2;
        else if (s == 'O') answer += k*3;
        else if (s == 'U') answer += k*4;
        k -= n;
        n /= 5;
    }
    return answer;
}
