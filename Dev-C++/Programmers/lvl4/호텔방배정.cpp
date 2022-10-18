#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Hash map을 사용하지 않고 array를 사용할 경우 메모리 사용 초과와 효율성 판별에서 점수를 잃는다.

Map을 사용할 수 있는 구현에서는 Hash를 사용하는 것이 훨씬 빠르다. 
*/

//bool rooms[];
long long findRooms(long long idx, bool rooms[]);
vector<long long> solution(long long k, vector<long long> room_number_request);

int main() {

    vector<long long> a;

    a = solution(10, { 1,3,4,1,3,1 });

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    
    return 0;
}

unordered_map<long long, long long> rooms;
 
long long findRooms(long long index)
{
    if (rooms[index] == 0) return index;
    return rooms[index] = findRooms(rooms[index]);
}

vector<long long> solution(long long k, vector<long long> room_number_request) {

    vector<long long> answer;
    long long idx;
    
    for (idx = 0; idx < room_number_request.size(); idx++)
    {
        long long roomNumber = room_number_request[idx];
        if ( rooms[roomNumber] == 0 )
        {
            answer.push_back(roomNumber);
            rooms[roomNumber] = findRooms(roomNumber + 1);
        }
        else
        {
            long long nextRoomNumber = findRooms(roomNumber);
            answer.push_back(nextRoomNumber);
            rooms[nextRoomNumber] = findRooms(nextRoomNumber + 1);
        }
    }

    return answer;
}
