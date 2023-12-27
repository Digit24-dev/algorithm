#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
정규식을 이용한 풀이로 풀어보자.
*/

int solution(string s) {

    string ret;
    string a[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    while (!s.empty())
    {
        int cnt = 0;
        for (size_t i = 0; i < 10; i++)
        {
            size_t idx = s.find(a[i]);
            if (idx == string::npos) {
                ++cnt;
                continue;
            }
            s[idx] = i + 0x30;
            s.erase(s.begin() + idx + 1, s.begin() + idx + a[i].size());
        }
        if (cnt == 10)
        {
            break;
        }
    }
    
    return stoi(s);
}

int main()
{
    cout << solution("one4seveneight") << endl;
}

/*
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    return stoi(s);
}
*/

/*
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

int solution(string s) {
    int answer = 0;
    regex r;
    for(int i = 0; i < numbers.size(); i++) {
        r = numbers[i];
        s = regex_replace(s, r, to_string(i));
    }
    answer = stoi(s);
    return answer;
}
*/