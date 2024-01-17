#include <iostream>

#include <string>
#include <vector>
#include <queue>
using namespace std;

int available(string a, string b) {
    int cnt = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i]);
        else cnt++;
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);

    q.push(make_pair(begin, 0));

    while (!q.empty())
    {
        pair<string, int> cur = q.front(); q.pop();
        
        if (target == cur.first) {
            answer = cur.second;
            break;
        }

        for (size_t i = 0; i < words.size(); i++)
        {
            if (!visited[i] && available(cur.first, words[i]) == 1) {
                q.push(make_pair(words[i], cur.second + 1));
                visited[i] = true;
            }
        }
    }

    return answer;
}

void main() {

    string b = "hit";
    string t = "cog";
    vector<string> w = { "hot", "dot", "dog", "lot", "log" };

    cout << solution(b, t, w) << endl;

}