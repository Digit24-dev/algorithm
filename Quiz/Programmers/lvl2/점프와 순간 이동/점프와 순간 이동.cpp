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
�� ������ 1�� ������ ���� ������ ����.
�׸��� �˰������� �����Ͽ��� ��, �ִ� �̵��� ��� ���Ͽ� ¦���� 2�� ������, Ȧ���� 1�� �����ϴ� ���� �ᱹ ������ ��Ʈ�� 1�� ������ ���� �Ͱ� �����ϴ�.
__builtin_popcount �� ����Ͽ� 1�� ��Ʈ ���� ����ϴ� �Ͱ� �����ϴ�.


*/
int main()
{
	cout << solution(5000) << endl;
}