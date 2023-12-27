#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<string> people[11];
	set<string> dupCheck;
	int cur = 1;
	char end_word = words[0][0];

	for (auto& i : words)
	{
		// �ٽ� ù�� ° �������
		if (cur > n)
			cur = 1;

		people[cur].push_back(i);

		// �ߺ��˻�
		if (!dupCheck.insert(i).second)
			return { cur, static_cast<int>(people[cur].size()) };
		
		// ���� �˻�
		if (end_word != i[0])
			return { cur, static_cast<int>(people[cur].size()) };

		end_word = i[i.size() - 1];
		cur++;
	}

	// �ܾ� ��� ����

	return { 0,0 };
}

int main() {

	cout << solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" })[0] << solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" })[1] << endl;

}