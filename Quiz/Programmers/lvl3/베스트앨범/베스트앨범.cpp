#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> playtime_of_genres;                // �帣�� �� �÷��� Ÿ�� ����
    map<string, vector<pair<int, int>>> hall_of_fame;   // f: ������ȣ, s: �÷���Ÿ��
    
    // processing data
    for (size_t i = 0; i < genres.size(); i++)  // i : ���� ��ȣ
    {
        // �帣�� �� �÷��� Ÿ��
        if (playtime_of_genres.find(genres[i]) != playtime_of_genres.end())
        {
            playtime_of_genres[genres[i]] += plays[i];
        }
        else
        {
            playtime_of_genres[genres[i]] = plays[i];
        }

        // �帣�� ���� ���̵� ����
        hall_of_fame[genres[i]].push_back(make_pair(i, plays[i]));
    }

    // ���� ���� ���� : 2. �帣 ������ ���� ����� �뷡 ������ �����Ѵ�.
    for (auto& elem : hall_of_fame)
    {
        // ���� ���� ������ ���� - 3. ��� Ƚ���� ���� ��� ������ȣ�� ���� ������ �����Ѵ�.
        sort(elem.second.begin(), elem.second.end(), [](pair<int,int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });
    }

    vector<pair<string, int>> sorted(playtime_of_genres.begin(), playtime_of_genres.end());

    // 1. ���� �뷡�� ���� ����� �帣
    sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    // ����
    for (auto& elem : sorted)
    {
        if (hall_of_fame[elem.first].size() == 1) answer.push_back(hall_of_fame[elem.first][0].first);
        else {
            answer.push_back(hall_of_fame[elem.first][0].first);
            answer.push_back(hall_of_fame[elem.first][1].first);
        }
    }

    return answer;
}


int main() {

    vector<string> g = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> p = { 500, 600, 150, 800, 2500 };

    vector<int> ret = solution(g,p);

    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}