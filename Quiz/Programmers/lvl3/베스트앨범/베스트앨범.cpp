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
    map<string, int> playtime_of_genres;                // 장르별 총 플레이 타임 저장
    map<string, vector<pair<int, int>>> hall_of_fame;   // f: 고유번호, s: 플레이타임
    
    // processing data
    for (size_t i = 0; i < genres.size(); i++)  // i : 고유 번호
    {
        // 장르별 총 플레이 타임
        if (playtime_of_genres.find(genres[i]) != playtime_of_genres.end())
        {
            playtime_of_genres[genres[i]] += plays[i];
        }
        else
        {
            playtime_of_genres[genres[i]] = plays[i];
        }

        // 장르별 고유 아이디 삽입
        hall_of_fame[genres[i]].push_back(make_pair(i, plays[i]));
    }

    // 명예의 전당 정렬 : 2. 장르 내에서 많이 재생된 노래 순으로 정렬한다.
    for (auto& elem : hall_of_fame)
    {
        // 가장 많은 순으로 정렬 - 3. 재생 횟수가 같을 경우 고유번호가 낮은 순으로 정렬한다.
        sort(elem.second.begin(), elem.second.end(), [](pair<int,int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });
    }

    vector<pair<string, int>> sorted(playtime_of_genres.begin(), playtime_of_genres.end());

    // 1. 속한 노래가 많이 재생된 장르
    sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    // 삽입
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