#include <iostream>
#include <vector>

using namespace std;

/*
1) 메모리상이유로 short로 배열 100만개를 전역으로 잡습니다 ( 최대 100만개 데이터, 각 데이터는 최대값 10000 임을 고려)
2) 현재위치를 idx = 0 으로 고정시키고 아래를 반복합니다.
2-1) idx 부터 배열끝까지 최대값 max을 구합니다 그리고 그위치를 max_idx 라고 합니다
2-2) idx ~ max_idx-1 까지 각각 이익을 더합니다.
2-3) 만약 idx == max_idx 일경우 각각 + 1씩 해줍니다.
2-4) idx를 max_idx+1로 최신화 합니다. max값도 마찬가지로 최신화합니다
*/

int main()
{
  int T, answer = 0;
  int n, temp;
  int max_price;
  vector<int> v;
  
  cout << "testing.." << endl;
  
  cin >> T;
  while (T--)
  {
    cin >> n;
    while (n--)
    {
      cin >> temp;
      v.push_back(temp);
    }
    max_price = v[0];

    for (size_t i = 0; i < v.size()-1; i++)
    {
      if (v[i] > max_price)
      {
        max_price = v[i];
        answer += max_price - v[i];
      }

    }
    
    cout<<"#"<< T << answer;
    v.clear();
    answer = 0;
  }
  
  return 0;
}
