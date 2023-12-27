#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. ���Ǵ�θ� Ǯ��
int solution(string str1, string str2) {
    vector<string> s1;
    vector<string> s2;

    string _temp = "";
    
    // 2 x O(n)
    for (auto& c : str1)
    {
        c = tolower(c);
    }

    for (auto& c : str2)
    {
        c = tolower(c);
    }

    // 2 x O(n)
    for (int i=0; i < str1.size() - 1; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i] <= 'z')
        {
            _temp = str1[i];
            _temp += str1[i + 1];
            s1.push_back(_temp);
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
        {
            _temp = str2[i];
            _temp += str2[i + 1];
            s2.push_back(_temp);
        }
    }

    // �� �¿����� �����հ� ������

    auto& buck_1 = s1.size() <= s2.size() ? s1 : s2;
    auto& buck_2 = s1.size() > s2.size() ? s1 : s2;

    int c_union = s1.size() + s2.size();
    int c_intersection = s1.size() <= s2.size() ? s1.size() : s2.size();

    int dup = 0;

    for (auto& elem : buck_1)
    {
        auto it = find(buck_2.begin(), buck_2.end(), elem);
        if (it != buck_2.end()){
            ++dup;
            buck_2.erase(it);
        }
    }

    c_union -= dup;
    c_intersection = dup;
    
    if (c_union == 0 && c_intersection == 0) {
        return 65536;
    }

    // ** �������. int / int �� int ���� �������� ���������� ��ȯ�ȴ�. float �� ��ȯ�ϰ� �����ؾ� �Ҽ��� ��ȯ�ȴ�.
    return (int)(((float)c_intersection / c_union) * 65536);;
}

int main()
{
    cout << solution("FRANCE", "french") << endl;
    cout << solution("handshake", "shake hands") << endl;
    cout << solution("aa1+aa2", "AAAA12") << endl;
    cout << solution("E=M*C^2", "e=m*c^2") << endl;
}