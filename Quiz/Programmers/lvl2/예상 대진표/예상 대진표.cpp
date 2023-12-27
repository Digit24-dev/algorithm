#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0; // round 
	int aR = a, bR = b;

	while (1)
	{
		answer++;

		for (size_t i = 1; i < n; i += 2)
		{
			if (i == aR)
				if (i + 1 == bR)
					goto ret;
			if (i == bR)
				if (i + 1 == aR)
					goto ret;
		}

		if (aR == 1)
			;
		else {
			aR = aR & 0x01 ? (aR + 1) / 2 : aR / 2;
		}

		if (bR == 1)
			;
		else{
			bR = bR & 0x01 ? (bR + 1) / 2 : bR / 2;
		}
	}
ret:
    return answer;
}


int main()
{
	cout << solution(8, 5, 8) << endl;
 }
/*
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	a--;
	b--;
	int answer=0;
	while(a!=b){
		a=a/2;
		b=b/2;
		answer++;
	}
	return answer;
}
///////////////////////////
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	while (a != b) {
		a = (a + 1) >> 1;   // 2 1 1
		b = (b + 1) >> 1;   // 4 2 1
		++answer;
	}

	return answer;
}
*/