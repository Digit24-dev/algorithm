#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
	string buf;
	vector<pair<string, string>> v;
	
	for(vector<string>::iterator iter=strings.begin(); iter!=strings.end(); ++iter) {
		buf = *iter;
		v.push_back(make_pair(buf.substr(n, 1), buf )); 
	}
	
	sort(v.begin(), v.end());
    
    for(vector<pair<string, string>>::iterator iter=v.begin(); iter != v.end(); ++iter){
    	answer.push_back(iter->second); 
	}
    
    return answer;
}

int main(){
	
	
	
	return 0;
}
