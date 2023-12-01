#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> split(string input, char delim){
    stringstream ss(input);
    vector<string> ret;
    string bucket;
    while(getline(ss, bucket, delim)){
        ret.push_back(bucket);
    }
    return ret;
}

int toDates(string str){
    int y, m, d;
    y = stoi(split(str, '.')[0]);
    m = stoi(split(str, '.')[1]);
    d = stoi(split(str, '.')[2]);

    return (y*12 + m) * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int _today = toDates(today);
    map<string, string> _map;

    for (size_t i = 0; i < terms.size(); i++)
    {
        _map.insert(make_pair(split(terms[i], ' ')[0], split(terms[i], ' ')[1]));
    }

    for (size_t i = 0; i < privacies.size(); i++)
    {
        toDates(split(privacies[i], ' ')[0]) + stoi(_map[split(privacies[i], ' ')[1]]);
        
    }
    
    

    return answer;
}