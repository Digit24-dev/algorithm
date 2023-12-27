#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 최대 인기 다른 풀이.
// 큐에 대기 중인 프로세스의 걸리는 날을 구하여 앞의 걸리는 일 수보다 작을 경우 answer.back()에 +1, 아닐 경우 새로 푸시.
// 철저하게 일자만 고려하여 반복문 하나로 처리하였다. 처리 속도는 평균 0.01ms 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int day;
	int max_day = 0;
	for (int i = 0; i < progresses.size(); ++i)
	{
		day = (99 - progresses[i]) / speeds[i] + 1;

		if (answer.empty() || max_day < day)
			answer.push_back(1);
		else
			++answer.back();

		if (max_day < day)
			max_day = day;
	}

	return answer;
}

vector<int> solution2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

	while (!progresses.empty())
	{
		int cnt = 0; // 제거할 큐 개수
		// 반복문 실행이 끝날 때마다 개발 속도 만큼 진행한다.
		// progress
		for (size_t i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];
		}

		// 완성된 큐를 제거한다.
		// pop
		if (progresses[0] >= 100)
		{
			for (size_t i = 0; i < progresses.size(); i++)
			{
				// 100 이상인 큐 확인
				if (progresses[i] >= 100)
					++cnt;
				else
					break;
			}
			// 갯수 만큼 큐 제거
			progresses.erase(progresses.begin(), progresses.begin() + cnt);
			speeds.erase(speeds.begin(), speeds.begin() + cnt);
			// 정답에 완료된 기능 푸시
			answer.push_back(cnt);
		}
		
	}

    return answer;
}

int main()
{
	vector<int> a = solution({ 93,30,55 }, { 1,30,5 });

	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}