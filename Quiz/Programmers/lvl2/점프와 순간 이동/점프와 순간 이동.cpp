#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
	int temp = n;

	while (temp > 1)
	{
		if (temp & 0x01)
		{
			temp -= 1;
			ans++;
		}
		temp = temp / 2;
	}

    return ++ans;
}
/*
이 문제는 1의 갯수를 세는 문제와 같다.
그리디 알고리즘으로 생각하였을 때, 최대 이득을 얻기 위하여 짝수면 2로 나누고, 홀수면 1을 감산하는 것은 결국 최하위 비트의 1의 갯수를 세는 것과 동일하다.
__builtin_popcount 를 사용하여 1의 비트 수를 계산하는 것과 동일하다.


*/
int main()
{
	cout << solution(5000) << endl;
}