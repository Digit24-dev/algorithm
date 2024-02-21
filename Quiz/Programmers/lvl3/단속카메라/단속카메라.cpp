#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    
    int camera = routes[0][0];
    int range = routes[0][1];

    for (int i = 1; i < routes.size(); i++)
    {
        if (routes[i][0] <= range) {
            range = min(range, routes[i][1]);
            if (routes[i][0] > camera)
                camera = routes[i][0];
        }
        else {
            ++answer;
            range = routes[i][1];
            camera = routes[i][0];
        }
    }

    return answer;
}


int main() {

    //vector<vector<int>> p = { {-20,-15}, {-14,-5}, {-18,-13}, {-5,-3} };
    vector<vector<int>> p = { {-20, 0}, {-15,-12}, {-16,-2}, {-15,-3} };

    cout << solution(p) << endl;

}