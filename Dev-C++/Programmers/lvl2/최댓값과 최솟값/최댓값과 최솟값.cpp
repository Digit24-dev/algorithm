#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string s, const char delim) {
    stringstream ss(s);
    string t;
    vector<string> ret;
    
    while (getline(ss, t, delim))
    {
        ret.push_back(t);
    }
    return ret;
}

string solution(string s) {
    string answer = "";
    vector<string> bucket = split(s, ' ');
    int max = 0;
    int min = 2147483648;

    for (auto& i : bucket)
    {
        int temp = stoi(i);
        max = max > temp ? max : temp;
        min = min < temp ? min : temp;
    }

    string max_temp = to_string(max);
    string min_temp = to_string(min);

    answer = min_temp;
    answer += " ";
    answer += max_temp;

    return answer;
}

/*
// ****************** 다른 분의 코드 ****************************
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string sTemp = "";
    vector<int> vecInteger;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            vecInteger.push_back(stoi(sTemp));
            sTemp.clear();
            continue;
        }

        sTemp += s[i];
    }

    vecInteger.push_back(stoi(sTemp));

    sort(vecInteger.begin(), vecInteger.end());

    answer += to_string(vecInteger.front());
    answer += ' ';
    answer += to_string(vecInteger.back());

    return answer;
}
*/