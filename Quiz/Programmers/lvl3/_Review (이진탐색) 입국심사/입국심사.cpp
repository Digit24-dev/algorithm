#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution2(int n, vector<int> times) {
    // times 의 배수마다 이벤트가 발생.
    long long time = 0;
    int k = 0;
    sort(times.begin(), times.end());
    vector<bool> tlatk(times.size(), false);
    
    while (n)
    {
        for (int i = 0; i < times.size(); i++)
        {
            if (tlatk[i]) tlatk[i] = false;

            for (int j = 0; j <= i; j++)
            {
                if (tlatk[j]) continue;
                if (times[j] < times[i]) {
                    tlatk[j] = true;
                    break;
                }
                else {
                    tlatk[i] = true;
                    time = static_cast<long long>(times[i] * k);
                }
            }
            
            --n;
        }
        ++k;
    }

    return time;
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = 1;  // 최소 시간
    long long right = static_cast<long long>(*max_element(times.begin(), times.end())) * n;  // 최대 시간

    while (left < right) {
        long long mid = (left + right) / 2;
        long long total = 0;

        // mid 시간 동안 처리할 수 있는 총 인원 수 계산
        for (int i = 0; i < times.size(); ++i) {
            total += mid / times[i];
        }

        // 처리한 인원이 주어진 사람 수보다 적으면 최소 시간을 늘림
        if (total < n) {
            left = mid + 1;
        }
        // 처리한 인원이 주어진 사람 수 이상이면 최대 시간을 줄임
        else {
            right = mid;
        }
    }

    return left;
}


int main() {
    int n = 6; vector<int> param = { 7,10 };

    cout << solution(n, param) << endl;
}