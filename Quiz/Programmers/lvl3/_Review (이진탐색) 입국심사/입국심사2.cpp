#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;


long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = 1;  // �ּ� �ð�
    long long right = static_cast<long long>(*max_element(times.begin(), times.end())) * n;  // �ִ� �ð�

    while (left < right) {
        long long mid = (left + right) / 2;
        long long total = 0;

        // mid �ð� ���� ó���� �� �ִ� �� �ο� �� ���
        for (int i = 0; i < times.size(); ++i) {
            total += mid / times[i];
        }

        // ó���� �ο��� �־��� ��� ������ ������ �ּ� �ð��� �ø�
        if (total < n) {
            left = mid + 1;
        }
        // ó���� �ο��� �־��� ��� �� �̻��̸� �ִ� �ð��� ����
        else {
            right = mid;
        }
    }

    return left;
}