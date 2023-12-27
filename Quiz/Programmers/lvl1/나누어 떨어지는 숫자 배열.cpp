#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(vector<int>::iterator iter=arr.begin() ; iter!=arr.end(); ++iter){
    	if(*iter % divisor == 0)
			answer.push_back(*iter);
	}
	
	if(answer.size() == 0)
		answer.push_back(-1);
		
	sort(answer.begin(), answer.end());
    return answer;
}

int main(){
	
	vector<int> t;
	t.push_back(5);
	t.push_back(9);
	t.push_back(7);
	t.push_back(10);
	
	cout << solution(t, 5) << endl;
	
	return 0;
}
