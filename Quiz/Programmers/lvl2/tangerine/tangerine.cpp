#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> func(int k, vector<int> array){
	unordered_map<int, int> uomap;
	for(int i=0; i<array.size(); ++i){
		if(uomap.find(array[i]) == uomap.end())
			uomap.insert(pair<int, int>{array[i], 1});
		else
			uomap.insert(pair<int, int>{array[i], ++uomap.at(array[i])});
	}
	
	return uomap;
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
	if(a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int,int> b = func(k, tangerine);
    vector<pair<int,int>> vec( b.begin(), b.end() );
	
	sort( vec.begin(), vec.end(), cmp );
	
	for(vector<pair<int,int>>::iterator iter = vec.begin() ; iter != vec.end() ; ++iter){
		if((k - iter->second) > 0){
			k -= iter->second;
			++answer;
		}else
            return ++answer;
	}
}
