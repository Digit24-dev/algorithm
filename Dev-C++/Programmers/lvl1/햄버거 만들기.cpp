
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 이해하기 쉬웠던 코드
bool check4(vector<int>& v) {
	if (vector<int>(v.end() - 4, v.end()) == vector<int>{1, 2, 3, 1}) {
		return true;
	}
	return false;
}

int solution2(vector<int> ingredient) {
	int answer = 0;
	vector<int> v;
	for (int it : ingredient) {
		v.push_back(it);
		while (check4(v)) {
			for (int i = 0; i < 4; i++) v.pop_back();
			answer++;
		}
	}
	return answer;
}


int main()
{
	cout << solution2({ 1, 3, 2, 1, 2, 1, 3, 1, 2 }) << endl;
	//cout << solution({ 1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1 }) << endl;
}
