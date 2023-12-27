#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1 = 0, idx2 = 0;

    for (auto& elem : goal)
    {
        if (cards1[idx1] == elem)
        {
            ++idx1;
            continue;
        }
        if (cards2[idx2] == elem)
        {
            ++idx2;
            continue;
        }
        return "No";
    }

    return "Yes";
}

/*
* 
* // 1. DFS 로 생각해 볼 수도 있다.
#include <string>
#include <vector>

using namespace std;

vector<string> cards1;
vector<string> cards2;
vector<string> goal;

string answer{ "No" };

void dfs(int index1, int index2, int index)
{
    if (index == goal.size()) answer = "Yes";

    if (index1 < cards1.size() && cards1[index1] == goal[index])
    {
        dfs(index1 + 1, index2, index + 1);
    }

    if (index2 < cards2.size() && cards2[index2] == goal[index])
    {
        dfs(index1, index2 + 1, index + 1);
    }
}

string solution(vector<string> c1, vector<string> c2, vector<string> g) {
    cards1 = c1;
    cards2 = c2;
    goal = g;


    dfs(0, 0, 0);
    return answer;
}
*/