#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

#define MAX_D 5
using namespace std;

string w = "AEIOU";
vector<char> retv;
int index = 1;
unordered_map<string, int> uomap;

void duplicatePermutation(int depth) {
    if (depth == MAX_D) {
        return;
    }

    for (int i = 0; i < MAX_D; i++)
    {
        retv.push_back(w[i]);
        string _t = "";
        for (auto& c : retv)
        {
            _t += c;
        }
        uomap.insert(make_pair(_t, index++));
        duplicatePermutation(depth + 1);
        retv.erase(retv.end() - 1);
    }
}

int solution(string word) {

    duplicatePermutation(0);

    return uomap[word];
}

int main() {
    cout << solution("EIO") << endl;
}