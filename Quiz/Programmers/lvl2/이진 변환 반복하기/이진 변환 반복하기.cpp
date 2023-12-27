#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline string toBinary(int n) {
    string ret;

    while (n!=0)
    {
        ret = ((n & 0x01) == 1 ? "1" : "0") + ret;
        n >>= 1;
    }
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt_dzero = 0, cnt_transform = 0;
    string temp = s;
    int cnt_1;

    while (temp != "1")
    {
        cnt_1 = 0;
        for (int i = 0; i < temp.size(); i++)
            if (temp[i] == '1')
                cnt_1++;
        cnt_dzero += temp.size() - cnt_1;

        temp = toBinary(cnt_1);
        cnt_transform++;
    }
    answer.push_back(cnt_transform);
    answer.push_back(cnt_dzero);
    return answer;
}

int main()
{
    vector<int> a = solution("110010101001");

    for (auto& i : a)
    {
        cout << i << endl;
    }

}