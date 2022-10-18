#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Hash map�� ������� �ʰ� array�� ����� ��� �޸� ��� �ʰ��� ȿ���� �Ǻ����� ������ �Ҵ´�.

Map�� ����� �� �ִ� ���������� Hash�� ����ϴ� ���� �ξ� ������. 
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
