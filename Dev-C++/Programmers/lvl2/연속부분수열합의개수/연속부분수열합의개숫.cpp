#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;

    int n = elements.size();

    for (int i = 0 ; i < n ; ++i) {
        int sum = 0;
        for (int j = i ; j < i + n ; ++j) {
            sum += elements[j % n];
            s.insert(sum);
        }
    }

    return s.size();
}
