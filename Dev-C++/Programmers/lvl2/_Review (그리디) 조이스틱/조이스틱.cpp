#include <iostream>


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int turn = n - 1;

    // Å½»ö
    for (int i = 0; i < name.size(); i++)
    {
        // ÁÂ¿ì·Î ÆîÄ¡¸é¼­ 0ÀÌ ¾Æ´Ñ °ª Ã£À½.
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;

        int ind = i + 1;
        while (ind < n && name[ind] == 'A') ind++;

        turn = min(turn, i + n - ind + min(i, n - ind));
    }

    return answer + turn;
}

int main() {

    //cout << solution("JEROEN") << endl;
    //cout << solution("JAN") << endl;
    cout << solution("NOTBAAAAD") << endl;

}