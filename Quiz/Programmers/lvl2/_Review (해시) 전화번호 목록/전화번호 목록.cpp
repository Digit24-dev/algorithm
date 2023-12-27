#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

//bool solution(vector<string>& phone_book) {
//
//    sort(phone_book.begin(), phone_book.end(), [](string a, string b) { return a.size() < b.size(); });
//
//    for (auto i = phone_book.begin(); i != phone_book.end(); i++)
//    {
//        for (auto j = (i + 1); j != phone_book.end(); j++)
//        {
//            string _FromFind = *j;
//            string _ToFind = *i;
//            auto temp = _FromFind.find(_ToFind);
//            if (temp != string::npos)
//                return false;
//        }
//    }
//
//    return true;
//}
// 정확성 16/20 
// 효율성 2/4

//bool solution(vector<string> phone_book) {
//    sort(phone_book.begin(), phone_book.end(), [](string a, string b) { return a.size() < b.size(); });
//
//    unordered_map<string, int> m;
//    vector<int> searchLenArray;
//
//    for (auto& i : phone_book)
//    {
//        searchLenArray.push_back(i.size());
//
//        if (m.empty())
//            m[i] = 0;
//        else {
//            for (auto j = searchLenArray.begin(); j != searchLenArray.end() - 1; j++)
//            {
//                if (m.find(i.substr(0, *j)) != m.end())
//                    return false;
//            }
//            m[i] = 0;
//        }
//    }
//    return true;
//}
// 정확성 20/20
// 효율성 2/4

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), [](string a, string b) { return a.size() < b.size(); });

    unordered_map<string, int> m;
    unordered_set<int> searchLenArray;

    for (auto& i : phone_book)
    {
        searchLenArray.insert(i.size());

        if (m.empty())
            m[i] = 0;
        else {
            for (auto j = searchLenArray.begin(); j != searchLenArray.end(); j++)
            {
                if (i.size() == *j) continue;
                if (m.find(i.substr(0, *j)) != m.end())
                    return false;
            }
            m[i] = 0;
        }
    }
    return true;
}
// 정확성 20/20
// 효율성 4/4

int main() {

    vector<string> param = { "1195524421","119", "97674223" };
    vector<string> param2 = {"123", "456", "789"};
    vector<string> param3 = {"12", "123", "1235", "567", "88"};

    cout << solution(param) << endl;
    cout << solution(param2) << endl;
    cout << solution(param3) << endl;

}

/*
// 1. 정렬로 쉽게 짤 수 있었다.. -> set이 필요 없음

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());

    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
    {
        if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) )
        {
            answer = false;
            break;
        }
    }

    return answer;
}

*/