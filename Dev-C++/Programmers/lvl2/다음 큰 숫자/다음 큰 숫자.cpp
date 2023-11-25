#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toBin(int n) {
    string ret;
    while (n != 0)
    {
        ret = ((n & 0x01) == 1 ? "1" : "0") + ret;
        n <<= 1;
    }
    return ret;
}

int countOnes(int n) {
    int ret = 0;
    while (n!=0)
    {
        if (n & 0x01)
            ret++;
        n >>= 1;
    }
    return ret;
}

int solution(int n) {
    int answer = n + 1;

    while (countOnes(n) != countOnes(answer))
    {
        answer++;
    }
    answer = answer;
    return answer;
}

int main()
{
    cout << solution(15) << endl;
}