#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int size = food.size() - 1;
	
	for (size_t i = 1; i < food.size(); i++)
	{
		for (size_t j = 0; j < food[i]/2; j++)
		{
			answer += to_string(i);
		}
	}
	answer += "0";
	for (int i = food.size() - 1; i >= 0; i--)
	{
		for (size_t j = 0; j < food[i] / 2; j++)
		{
			answer += to_string(i);
		}
	}
	
	return answer;
}

int main()
{
	cout << solution({ 1,3,4,6 }) << endl;
	cout << solution({ 1,7,1,2 }) << endl;
}

/*
//1. �� ���� ����ϴ� ���
string solution(vector<int> food) {
	string answer = "0";
	int check;
	for(int i=food.size()-1; i>0; i--){
		check = food[i]/2;
		while(check){
			answer = to_string(i) + answer + to_string(i);
			check--;
		}
	}
	return answer;
}

//2. Ư���� �̿��� reverse �Լ� ���
string solution(vector<int> food) {
	string answer = "";

	for(int i = 1; i < food.size(); ++i)
	{
		for(int j = 0; j < food[i]/2; ++j)
		{
			answer += to_string(i);
		}
	}

	int n = answer.size();

	answer = answer + "0" + answer;

	reverse(answer.begin()+n+1,answer.end());

	return answer;
}

//3. insert �Լ� ����� ����ȭ
string solution(vector<int> food)
{
	string s = "";
	for (int i = 1; i < food.size(); ++i)
		s.insert(s.size() / 2, food[i] - food[i]%2, '0'+i);
	s.insert(s.size() / 2, 1, '0');
	return s;
}

*/