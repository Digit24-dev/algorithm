#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> s;
    for(int i=0; i<=n; ++i){
    	if(n%i == 0){
    		s.push_back(i);
		}
	}
	for(int i=0; i<s.size(); ++i){
		answer += s[i];
	}
    return answer;
}
