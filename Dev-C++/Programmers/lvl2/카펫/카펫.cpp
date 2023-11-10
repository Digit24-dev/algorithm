#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int cnt_brown = 0;
    // ÃÖ´ë x, y -> 1249
    for (int y = 3; y <= 1249; y++)
    {
        for (int x = y; x <= 2498; x++)
        {
            // upper
            int upper_brown = y - 1;
            int left_brown = x - 1;
            cnt_brown = upper_brown * 2 + left_brown * 2;

            int upper_yellow = y - 2;
            int left_yellow = x - 2;
            int cnt_yellow = upper_yellow * left_yellow;

            if (cnt_brown == brown && cnt_yellow == yellow) {
                answer.push_back(y);
                answer.push_back(x);
            }
        }
    }

    return answer;
}