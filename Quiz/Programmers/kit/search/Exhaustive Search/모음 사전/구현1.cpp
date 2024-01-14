#include <assert.h>
#include <string>
#include <vector>

using namespace std;

int solution(string word)
{
    const int weights[5] = { 781, 156, 31, 6, 1 };
    int answer = 0;
    for (int i = 0; i < word.length(); ++i)
    {
        int current;
        switch (word[i])
        {
        case 'A':
            current = 0;
            break;
        case 'E':
            current = 1;
            break;
        case 'I':
            current = 2;
            break;
        case 'O':
            current = 3;
            break;
        case 'U':
            current = 4;
            break;
        default:
            assert(false);
        }
        ++answer;
        answer += current * weights[i];
    }
    return answer;
}