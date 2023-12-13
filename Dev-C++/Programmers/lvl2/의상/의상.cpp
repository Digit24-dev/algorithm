#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // Key / value
    unordered_map<string, int> mm;

    // 같은 종류의 옷 -> 중복 불가
    // 다른 종류의 옷 -> 선택을 하건 말건 상관 없음
    /*
    알파벳: 옷 종류 / 숫자 : 그 옷 갯수
    a: 1
    b: 3
    c: 4
    
    선택을 안하는 경우를 추가하면 각 옷 갯수에 + 1
    순열 -> 2 * 4 * 5 - (모두 선택 안하는 경우) 1
    */

    for (auto& elem : clothes)
    {
        // 못 찾음
        if (mm.find(elem[1]) == mm.end()) {
            mm.insert(make_pair(elem[1], 1));
        }
        else { // 있음
            ++mm[elem[1]];
        }
    }

    for (auto& item : mm)
    {
        answer *= (item.second + 1);
    }

    return answer - 1;
}

int main() {
    cout << solution({ {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} }) << endl;
    cout << solution({ {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} }) << endl;
}