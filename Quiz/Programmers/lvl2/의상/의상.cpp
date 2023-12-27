#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // Key / value
    unordered_map<string, int> mm;

    // ���� ������ �� -> �ߺ� �Ұ�
    // �ٸ� ������ �� -> ������ �ϰ� ���� ��� ����
    /*
    ���ĺ�: �� ���� / ���� : �� �� ����
    a: 1
    b: 3
    c: 4
    
    ������ ���ϴ� ��츦 �߰��ϸ� �� �� ������ + 1
    ���� -> 2 * 4 * 5 - (��� ���� ���ϴ� ���) 1
    */

    for (auto& elem : clothes)
    {
        // �� ã��
        if (mm.find(elem[1]) == mm.end()) {
            mm.insert(make_pair(elem[1], 1));
        }
        else { // ����
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