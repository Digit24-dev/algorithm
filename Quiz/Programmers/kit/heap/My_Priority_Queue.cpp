#include <vector>

// �켱 ���� ť ����

template <typename T>
class MyPriorityQueue
{
public:
	MyPriorityQueue() : size(0) {
		_v.push_back(0);					// index 1���� ��Ʈ ���
	}
	void push(const T& elem) {
		_v.push_back(elem);
		
		if (empty())
			return;
		
		// ����

	}
	void pop() {
		// ����
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