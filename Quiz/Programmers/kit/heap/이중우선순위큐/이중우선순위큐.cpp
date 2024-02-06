#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> simple;

    for (auto& order : operations)
    {
        if (order[0] == 'I')
        {
            simple.push_back(stoi(order.substr(2, order.size() - 2)));
        }
        else if (order == "D 1") {
            int maxNum = INT32_MIN, idx = -1;
            for (size_t i = 0; i < simple.size(); i++)
            {
                if (simple[i] >= maxNum) {
                    maxNum = simple[i];
                    idx = i;
                }
            }
            if (idx != -1) {
                simple.erase(simple.begin() + idx);
            }
        }
        else if (order == "D -1") {
            int minNum = INT32_MAX, idx = -1;
            for (size_t i = 0; i < simple.size(); i++)
            {
                if (simple[i] <= minNum) {
                    minNum = simple[i];
                    idx = i;
                }
            }
            if (idx != -1) {
                simple.erase(simple.begin() + idx);
            }
        }
    }

    if (!simple.empty()) {
        sort(simple.begin(), simple.end());
        return { simple[simple.size() - 1],simple[0] };
    }
    else {
        return { 0,0 };
    }
}

int main() {

    vector<string> p1 = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    vector<string> p2 = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
    vector<int> ret = solution(p2);
    //vector<int> ret = solution(p2);

    for (auto& i : ret)
    {
        cout << i << ", ";
    }

    return 0;
}