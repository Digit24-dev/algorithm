#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, x=1, y=1;
    string order;

    cin >> N;
    getline(cin, order);

    for (size_t i = 0; i < order.size(); i++)
    {
        switch (order[i])
        {
        case 'L':
            if(y-1 < 1)
                continue;
            else
                --y;
            break;
        case 'R':
            if(y+1 > N)
                continue;
            else
                ++y;
            break;
        case 'U':
            if(x-1 < 1)
                continue;
            else
                --x;
            break;
        case 'D':
            if(x+1 > N)
                continue;
            else
                ++x;
            break;
        default:
            break;
        }
    }
    cout << x << " " << y;    

    return 0;
}