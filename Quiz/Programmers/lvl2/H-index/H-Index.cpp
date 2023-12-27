#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.rbegin(), citations.rend());

    for (auto& item : citations)
    {
        if (answer < item)
            ++answer;
        else
            break;
    }
    
    return answer;
}

int main()
{
    cout << solution({ 3,0,6,1,5 }) << endl;
}