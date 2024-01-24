#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// �� ���ڸ� �̾�ٿ��� �� �� ū ���ڰ� �������� ���ϴ� �Լ�
bool compare(int a, int b) {
    string num1 = to_string(a);
    string num2 = to_string(b);
    
    return num1 + num2 > num2 + num1;
}

string solution(vector<int> numbers) {
    // �� �Լ��� �̿��Ͽ� ����
    sort(numbers.begin(), numbers.end(), compare);

    // ��� ���ڰ� 0�� ��� ���� ó��
    if (numbers[0] == 0) {
        return "0";
    }

    // ���ĵ� ���ڸ� �̾�ٿ� ���ڿ��� ��ȯ
    string answer = "";
    for (int num : numbers) {
        answer += to_string(num);
    }

    return answer;
}

int main() {
    vector<int> numbers = { 1, 6, 10, 12 };
    string result = solution(numbers);

    cout << "The largest number is: " << result << endl;

    return 0;
}
