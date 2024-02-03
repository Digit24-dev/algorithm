#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 100000
#define MAX_D 22
#define DEBUG

int n, q;

//  ���� Ʈ���� 2���� �迭 ���·� �����Ͽ� ������ �� �ִ�.
//  i��° ��忡 �ڽİ� �θ� ��带 map[i][x] ���·� �����Ͽ� ������ �� �ִ�.
//  ó������ �ٽ�!

// 1. �ڽ� ������ ���� ���� �� �ִ� Ʈ���� �����Ѵ�.

int map[MAX_N + 1];
int parents[MAX_N + 1];
int authority[MAX_N + 1];
int ans[MAX_N + 1];
bool alam[MAX_N + 1];

// �ʱ� ���� ���� �޾ƿɴϴ�.
void init() {
    int temp;
    
    // �θ� ���� ����
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        parents[i] = temp;
    }

    // ���� ���� ����
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        // ä���� ������ 20�� �ʰ��ϴ� ��� 20���� �����մϴ�.
        if (temp > 20) temp = 20;
        authority[i] = temp;
    }

    // �ʿ� ������ ����
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

// ä���� �˸� ���¸� ����մϴ�.
void toggle_noti(int chat) {
    /*
    �˸� ������ ���
    1) �˶��� �����־��� ���
        
    2) �˶��� �����־��� ���
        
    �˶� ���¸� ����Ѵ�.
        �����־����� �ڽ� ������ ���°� �θ� ���鿡 ������ �Ǿ� �־��� ����.
        �����־����� �ڽ� ������ ���µ� �ݿ��ؾ���.
        �ڽ� ���� ���� ��ϵ� Ʈ���� ������ ���� ������?
    */
}

// ä���� ������ ũ�⸦ �����մϴ�.
void change_power(int chat, int power) {
    

}

// �� ä���� �θ� ��ü�մϴ�.
void change_parent(int chat1, int chat2) {

    
}

// �ش� ä���� val ���� ����մϴ�.
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
