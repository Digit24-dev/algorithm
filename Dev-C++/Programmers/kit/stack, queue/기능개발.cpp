#include <string>
#include <vector>
#include <iostream>
using namespace std;

// �ִ� �α� �ٸ� Ǯ��.
// ť�� ��� ���� ���μ����� �ɸ��� ���� ���Ͽ� ���� �ɸ��� �� ������ ���� ��� answer.back()�� +1, �ƴ� ��� ���� Ǫ��.
// ö���ϰ� ���ڸ� ����Ͽ� �ݺ��� �ϳ��� ó���Ͽ���. ó�� �ӵ��� ��� 0.01ms 
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
		int cnt = 0; // ������ ť ����
		// �ݺ��� ������ ���� ������ ���� �ӵ� ��ŭ �����Ѵ�.
		// progress
		for (size_t i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];
		}

		// �ϼ��� ť�� �����Ѵ�.
		// pop
		if (progresses[0] >= 100)
		{
			for (size_t i = 0; i < progresses.size(); i++)
			{
				// 100 �̻��� ť Ȯ��
				if (progresses[i] >= 100)
					++cnt;
				else
					break;
			}
			// ���� ��ŭ ť ����
			progresses.erase(progresses.begin(), progresses.begin() + cnt);
			speeds.erase(speeds.begin(), speeds.begin() + cnt);
			// ���信 �Ϸ�� ��� Ǫ��
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