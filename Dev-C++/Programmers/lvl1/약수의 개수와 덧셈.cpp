#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
	int tmp_cnt = 0;

	for (int i = left; i <= right; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0) {
				tmp_cnt++;
			}
		}
		if (tmp_cnt & 0x01)
		{
			answer -= i;
		}
		else
		{
			answer += i;
		}
		tmp_cnt = 0;
	}

    return answer;
}