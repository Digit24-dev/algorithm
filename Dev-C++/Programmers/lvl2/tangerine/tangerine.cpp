#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, int> solution(int k, vector<int> array);

int main(){
	
	int a;
	vector<int> arr;
	
	a = 6;
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(5);
	
	unordered_map<int, int> b = solution(a, arr);

	for(unordered_map<int, int>::iterator iter = b.begin(); iter != b.end(); ++iter){
		cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}

unordered_map<int, int> solution(int k, vector<int> array){
	unordered_map<int, int> uomap;
	for(int i=0; i<array.size(); ++i){
		if(uomap.find(array[i]) == uomap.end())
			uomap.insert(pair<int, int>{array[i], 1});
		else
			uomap.insert(pair<int, int>{array[i], ++uomap.at(array[i])});
	}
	
	return uomap;
}
