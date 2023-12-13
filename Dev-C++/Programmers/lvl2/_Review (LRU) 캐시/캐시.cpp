#include <iostream>

#include <unordered_map>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;

class LRUCahce
{
public:
    LRUCahce(int c) : capacity(c) {};

    bool matchCheck(string key) {
        auto it = find(data.begin(), data.end(), key);

        if (it == data.end()) { // 없는 경우
            if (data.size() < capacity) {
                data.push_back(key);
            }
            else {
                data.erase(data.begin());
                data.push_back(key);
            }
            return false;
        }
        else {
            data.erase(it);
            data.push_back(key);
            return true;
        }
    }

    void insert(string key) {
        if (cache_HitOrNot(key)) {
            
        }
        else {
            if (data.size() < capacity) {
                data.push_back(key);
            }
            else {
                data.erase(data.begin());
                data.push_back(key);
            }
        }
    }

    bool cache_HitOrNot(string key) {
        auto it = std::find(data.begin(), data.end(), key);
       
        if (it == data.end())
            return false;
        else
            return true;
    }

private:
    int capacity;
    list<string> data;

    LRUCahce() {};
};

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (cacheSize == 0)
        return cities.size() * 5;

    LRUCahce cache(cacheSize);
    
    for (auto& elem : cities)
    {
        for (auto& c : elem)
        {
            c = tolower(c);
        }

        if (cache.matchCheck(elem)) {
            answer += 1;
        }
        else {
            answer += 5;
        }
    }

    return answer;
}

int main()
{
    int size = 5;
    vector<string> sample = { "a", "b", "c", "b", "a" };
    
    cout << solution(size, sample) << endl;
    //cout << solution(3, ) << endl;

}