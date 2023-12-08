#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> p;
    for (auto& i : participant)
    {
        if (p.find(i) == p.end())
            p.insert(make_pair(i, 1));
        else {
            ++p[i];
        }
    }

    for (auto& i : completion)
    {
        --p[i];
    }

    for (auto& i : p)
    {
        if (i.second > 0)
            return i.first;
    }

    return "";
}

int main()
{
    vector<string> p = { "mislav", "mislav", "mislav", "mislav" };
    vector<string> c = { "mislav", "mislav", "mislav" };


    //cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl;
    //cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "marina", "josipa", "nikola", "filipa" }) << endl;
    //cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "mislav", "stanko", "ana" }) << endl;
    cout << solution(p, c) << endl;
}

/* 
//1. �׻� ������ ���ĵ� �����غ���.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];
    //return answer;
}

//2. ��Ƽ�� �ڷ����� �ִ�.
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> names;

    for(int i = 0; i < participant.size(); i++)
    {
        names.insert(participant[i]);
    }

    for(int i = 0; i < completion.size(); i++)
    {
        unordered_multiset<string>::iterator itr = names.find(completion[i]);
        names.erase(itr);
    }

    return *names.begin();
}

//3. ���� �Ⱑ ���� �ڵ�. 
//Serial Scrambler Ȥ�� Randomizer �� XOR ������ ������ ���ѻ����� �Ⱑ ������ �� �̿��ߴ�.

#include <string>
#include <vector>

using namespace std;
char c[29];
string solution(vector<string> a, vector<string> b) {
    for(int j=0;j<21;j++){
        c[j] = 0;
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            c[j]^=a[i][j];
        }
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            c[j]^=b[i][j];
        }
    }
    return string(c);
}

*/