#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<pair<int, int>> map;
    map.push_back(pair<int, int>(3, 1));
    map.push_back(pair<int, int>(0, 0));
    map.push_back(pair<int, int>(0, 1));
    map.push_back(pair<int, int>(0, 2));
    map.push_back(pair<int, int>(1, 0));
    map.push_back(pair<int, int>(1, 1));
    map.push_back(pair<int, int>(1, 2));
    map.push_back(pair<int, int>(2, 0));
    map.push_back(pair<int, int>(2, 1));
    map.push_back(pair<int, int>(2, 2));
    map.push_back(pair<int, int>(3, 0));
    map.push_back(pair<int, int>(3, 2));
    
    pair<int, int> Lpos = map[10];
    pair<int, int> Rpos = map[11];
    
    for(int i=0; i<numbers.size(); ++i){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            Lpos = map[numbers[i]];
        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            Rpos = map[numbers[i]];
        }else{
            int posFirst = map[numbers[i]].first;
            int posSecond = map[numbers[i]].second;
            int Ldist = abs(posFirst - Lpos.first) + abs(posSecond - Lpos.second);
            int Rdist = abs(posFirst - Rpos.first) + abs(posSecond - Rpos.second);
            if(Ldist > Rdist){
                Rpos = map[numbers[i]];
                answer += "R";
            }else if(Ldist < Rdist){
                Lpos = map[numbers[i]];
                answer += "L";
            }else{
                if(hand == "left"){
                    Lpos = map[numbers[i]];
                    answer += "L";
                }else{
                    Rpos = map[numbers[i]];
                    answer += "R";
                }
            }
        }
    }
    
    return answer;
}
