using namespace std;
#include <cmath>

long long solution(int price, int money, int count)
{
    long long answer = -1;
	long long t_ = 0;

	for (int i = 1; i <= count; i++)
	{
		t_ += price * i;
	}

	answer = static_cast<long long>(money) > t_ ? 0 : abs(static_cast<long long>(money) - t_);

    return answer;
}