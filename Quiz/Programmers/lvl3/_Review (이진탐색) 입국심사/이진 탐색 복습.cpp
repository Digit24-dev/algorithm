#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 사용 방법
// 1. 정렬된 자료형에서 사용할 것.
// 2. 자료형의 최하위 인덱스를 left 최상위 인덱스를 right
// 3. mid = (left + right) / 2
// 4. 주어진 조건에 따라 인덱스를 옮기며 명령 처리.

// 문제에 적용한 점
// 문제에 주어진 데이터를 기반으로 자료형을 정한 것이 아닌,
// 구하고자 하는 '시간'을 이진 탐색 대상으로써 바라보았다.

// 최대 걸리는 시간의 절반 만큼동안 일 했을 때 일을 끝냈다. -> 최대시간 줄임
// 최대 걸리는 시간의 절반 만큼동안 일 했을 때 일을 못 끝냈다. -> 최소시간 높임

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