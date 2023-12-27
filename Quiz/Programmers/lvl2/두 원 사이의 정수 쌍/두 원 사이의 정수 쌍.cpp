#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = r2 - r1 + 1;
    long long xx;
    long long yy;
    double dist;

    for (int x = 1; x < r2; x++)
    {
        for (int y = r2 - 1; y > 0; y--)
        {
            xx = pow(x, 2);
            yy = pow(y, 2);
            dist = sqrt(xx + yy);
            if (dist <= r2 && dist >= r1)
            {
                answer++;
            }
            else
            {
                continue;
            }
        }
    }
    answer *= 4;
    return answer;
}

int main() {

    int r1, r2;
    r1 = 2, r2 = 3;

    cout << solution(r1, r2) << endl;

    return 0;
}