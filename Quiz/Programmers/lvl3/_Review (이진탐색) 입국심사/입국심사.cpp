#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution2(int n, vector<int> times) {
    // times �� ������� �̺�Ʈ�� �߻�.
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


int main() {
    int n = 6; vector<int> param = { 7,10 };

    cout << solution(n, param) << endl;
}