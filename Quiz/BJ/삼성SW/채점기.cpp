#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

int q;
int n;

// ���� ä�� ��� ť�� �ִ� task�� ������ �����մϴ�.
int ans;

struct Url{
    
};


// ä���⸦ �غ��մϴ�.
void Init() {
    
}

// ���ο� url�� �Է¹޾� ����ť�� �߰����ݴϴ�.
void NewUrl() {
    
}

// ���� �������� ã�� assign�մϴ�.
void Assign() {
    
}

// ä�� �ϳ��� �������մϴ�.
void Finish() {
    
}

// ���� ä�� ��� ť�� �ִ� url�� ������ ������ݴϴ�.
void Check() {
    
}

int main() {
    cin >> q;

    while(q--) {
        int query;
        cin >> query;

        if(query == 100) {
            // ä���⸦ �غ��մϴ�.
            Init();
        }
        if(query == 200) {
            // ���ο� url�� �Է¹޾� ����ť�� �߰����ݴϴ�.
            NewUrl();
        }
        if(query == 300) {
            // ���� �������� ã�� assign�մϴ�.
            Assign();
        }
        if(query == 400) {
            // ä�� �ϳ��� �������մϴ�.
            Finish();
        }
        if(query == 500) {
            // ���� ä�� ��� ť�� �ִ� url�� ������ ������ݴϴ�.
            Check();
        }
    }
}
