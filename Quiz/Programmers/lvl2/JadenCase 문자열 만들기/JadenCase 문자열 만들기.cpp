#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string s) {
    stringstream ss(s);
    string str;
    vector<string> ret;

    while (getline(ss, str, ' '))
    {
        ret.push_back(str);
    }

    return ret;
}

string solution(string s) {
    int idx = 0;
    
    if (s[idx] == ' ')
    {
        while (s[idx] != ' ')
        {
            ++idx;
        }
    }
    bool prev_stat = true;
    for (; idx < s.size(); idx++)
    {
        if (prev_stat)
        {
            if (s[idx] >= 'a' && s[idx] <= 'z') {
                s[idx] -= 32;
            }
            prev_stat = false;
            continue;
        }

        if (s[idx] == ' ' && s[idx + 1] != ' ') {
            prev_stat = true;
            continue;
        }

        if (s[idx] >= 'A' && s[idx] <= 'Z') {
            s[idx] += 32;
        }
    }

    return s;
}

string solution2(string s) {
    s[0] = toupper(s[0]);

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == ' ')
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
    return s;
}

int main()
{
    cout << solution2("3people unFollowed me") << endl;
}