#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string str, char delimiter);

string solution(string s) {
    string answer = "";
    vector<string> bucket;
    bucket = split(s, ' ');
    
    for(int i=0; i<bucket.size(); ++i){
    	string t = bucket[i];
		for(int j=0; j<t.size(); ++j){
			if(!(j & 0x01)){
				t[j] -= 32;
			}
		}
	}
	
	for(int i=0; i<bucket.size(); ++i){
		answer = answer + bucket[i] + " ";
	}
    return answer;
}

vector<string> split(string input, char delimiter){
	vector<string> ret;
	stringstream ss(input);
	string temp;
	
	while(getline(ss, temp, delimiter)){
		ret.push_back(temp);
	}
	
	return ret;
}
