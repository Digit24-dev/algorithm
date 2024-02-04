#include <vector>

// 우선 순위 큐 구현

template <typename T>
class MyPriorityQueue
{
public:
	MyPriorityQueue() : size(0) {
		_v.push_back(0);					// index 1부터 루트 노드
	}
	void push(const T& elem) {
		_v.push_back(elem);
		
		if (empty())
			return;
		
		// 구현

	}
	void pop() {
		// 구현
	}
	T top() {
		return _v[1];
	}
	int size() {
		return size;
	}
	bool empty() {
		if (size) return false;
		else return true;
	}
private:
	size_t size;
	std::vector<T> _v;
};