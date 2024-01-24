#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 두 숫자를 이어붙였을 때 더 큰 숫자가 나오도록 비교하는 함수
bool compare(int a, int b) {
    string num1 = to_string(a);
    string num2 = to_string(b);
    
    return num1 + num2 > num2 + num1;
}

string solution(vector<int> numbers) {
    // 비교 함수를 이용하여 정렬
    sort(numbers.begin(), numbers.end(), compare);

    // 모든 숫자가 0일 경우 예외 처리
    if (numbers[0] == 0) {
        return "0";
    }

    // 정렬된 숫자를 이어붙여 문자열로 반환
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
