#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

int q;
int n;

// 현재 채점 대기 큐에 있는 task의 개수를 관리합니다.
int ans;

struct Url{
    
};


// 채점기를 준비합니다.
void Init() {
    
}

// 새로운 url을 입력받아 레디큐에 추가해줍니다.
void NewUrl() {
    
}

// 다음 도메인을 찾아 assign합니다.
void Assign() {
    
}

// 채점 하나를 마무리합니다.
void Finish() {
    
}

// 현재 채점 대기 큐에 있는 url의 개수를 출력해줍니다.
void Check() {
    
}

int main() {
    cin >> q;

    while(q--) {
        int query;
        cin >> query;

        if(query == 100) {
            // 채점기를 준비합니다.
            Init();
        }
        if(query == 200) {
            // 새로운 url을 입력받아 레디큐에 추가해줍니다.
            NewUrl();
        }
        if(query == 300) {
            // 다음 도메인을 찾아 assign합니다.
            Assign();
        }
        if(query == 400) {
            // 채점 하나를 마무리합니다.
            Finish();
        }
        if(query == 500) {
            // 현재 채점 대기 큐에 있는 url의 개수를 출력해줍니다.
            Check();
        }
    }
}
