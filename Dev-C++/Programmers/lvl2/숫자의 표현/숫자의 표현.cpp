#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
	int tmp_sum = 0;

	for (int i = 1; i <= n; i++)
	{
		tmp_sum += i;
		if (tmp_sum == n) {
			answer++; tmp_sum = 0; continue;
		}
			
		for (int j = i + 1; j <= n; j++)
		{
			tmp_sum += j;
			if (tmp_sum == n) {
				answer++;
				tmp_sum = 0;
				break;
			}
			else if (tmp_sum > n) {
				tmp_sum = 0;
				break;
			}
		}
	}

    return answer;
}

int main()
{
	cout << solution(15) << endl;
}