#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 100000
#define MAX_D 22
#define DEBUG

int n, q;

//  이진 트리를 2차원 배열 형태로 선언하여 생각할 수 있다.
//  i번째 노드에 자식과 부모 노드를 map[i][x] 형태로 선언하여 관리할 수 있다.
//  처음부터 다시!

// 1. 자식 노드들을 쉽게 구할 수 있는 트리를 구성한다.

int map[MAX_N + 1];
int parents[MAX_N + 1];
int authority[MAX_N + 1];
int ans[MAX_N + 1];
bool alam[MAX_N + 1];

// 초기 설정 값을 받아옵니다.
void init() {
    int temp;
    
    // 부모 관계 설정
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        parents[i] = temp;
    }

    // 권한 세기 설정
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        // 채팅의 권한이 20을 초과하는 경우 20으로 제한합니다.
        if (temp > 20) temp = 20;
        authority[i] = temp;
    }

    // 맵에 데이터 갱신
    for (int i = 1; i <= n; i++)
    {
        int a = authority[i];
        int cur = parents[i];
        while (a--)
        {
            ans[cur]++;
            cur = parents[cur];
        }
    }

#ifdef DEBUG
    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
#endif // DEBUG
}

// 채팅의 알림 상태를 토글합니다.
void toggle_noti(int chat) {
    /*
    알림 상태의 토글
    1) 알람이 꺼져있었을 경우
        
    2) 알람이 켜져있었을 경우
        
    알람 상태를 토글한다.
        켜져있었으면 자식 노드들의 상태가 부모 노드들에 연관이 되어 있었을 거임.
        꺼져있었으면 자식 노드들의 상태도 반영해야함.
        자식 노드들 까지 등록된 트리를 구성할 수는 없을까?
    */
}

// 채팅의 권한의 크기를 변경합니다.
void change_power(int chat, int power) {
    

}

// 두 채팅의 부모를 교체합니다.
void change_parent(int chat1, int chat2) {

    
}

// 해당 채팅의 val 값을 출력합니다.
void print_count(int chat) {
    
}

int main() {
    cin >> n >> q;
    while (q--) {
        int query;
        cin >> query;
        if (query == 100) {
            init();
        }
        else if (query == 200) {
            int chat;
            cin >> chat;
            toggle_noti(chat);
        }
        else if (query == 300) {
            int chat, power;
            cin >> chat >> power;
            change_power(chat, power);
        }
        else if (query == 400) {
            int chat1, chat2;
            cin >> chat1 >> chat2;
            change_parent(chat1, chat2);
        }
        else if (query == 500) {
            int chat;
            cin >> chat;
            print_count(chat);
        }
    }
    return 0;
}
