/*

<algorithm STL, sort 문제점>

불안정 정렬로 구현되어 있다.

정렬할 데이터의 기존 순서를 보장하여 반환하지 않는다.

stable_sort 함수를 사용하여야 함.

*/


#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    string head;
    string cmp;
    string num;
    string tail;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<info> fm(files.size()); // fileName head / number / tail / head_cmp
    int _tempIdx = 0;
    int state = 0; // 0: head 1: num 2: tail
    string head, number, tail, head_cmp;
    
    // 1. 파일명 HEAD NUM TAIL 로 나눔.
    for (auto& fileName : files)
    {
        state = 0;
        head = "";
        number = "";
        tail = "";
        head_cmp = "";
        
        // Find index of HEAD
        for (int i = 0; i < fileName.size(); i++)
        {
            switch (state)
            {
            case 0:
                if (isdigit(fileName[i + 1])) {
                    state = 1;
                }
                head_cmp += tolower(fileName[i]);
                head += fileName[i];
                break;

            case 1:
                if (number.size() < 4 && isdigit(fileName[i + 1])) {
                    ;
                }
                else {
                    state = 2;
                }
                number += fileName[i];
                break;

            case 2:
                tail += fileName[i];
                break;

            default:
                break;
            }
        }
        fm[_tempIdx].cmp = head_cmp;
        fm[_tempIdx].head = head;
        fm[_tempIdx].num = number;
        fm[_tempIdx].tail = tail;

        ++_tempIdx;
    }

    // fileName head / number / tail / head_cmp
    // 2. sort
    stable_sort(fm.begin(), fm.end(), [](info a, info b) {
        if (a.cmp == b.cmp) return stoi(a.num) < stoi(b.num); 
        else {
            return a.cmp < b.cmp;
        }
    });

    // 3. back to answer
    for (auto& elem : fm)
    {
        answer.push_back(elem.head + elem.num + elem.tail);
    }

    return answer;
}

int main() {
    vector<string> ret;
    //vector<string> param = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    //vector<string> param = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };
    //vector<string> param = { "A500001", "A50000" };
    //vector < string > param = { "F13.png", "F14", "f013", "F014", "F013.TXT" };
    vector<string> param = { "a0001", "a001", "a000001" };

    ret = solution(param);
    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}