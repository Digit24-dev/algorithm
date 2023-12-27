#include <iostream>

namespace MultiDemensionArray {
	class Array;
	class Int;

	class Array
	{
		friend Int;

	private:
		const int dim;
		int* size;

		struct Address {
			int level;
			void* next;
		};

		Address* top;

	public:
		Array(int dim, int* array_size) : dim(dim) {
			size = new int[dim];
			for (int i = 0; i < dim; i++)
			{
				size[i] = array_size[i];
			}

			top = new Address;
			top->level = 0;

			initialize_address(top);
		}
		Array(const Array& arr) : dim(arr.dim) {
			size = new int[dim];
			for (int i = 0; i < dim; i++)
			{
				size[i] = arr.size[i];
			}

			top = new Address;
			top->level = 0;

			initialize_address(top);
			copy_address(top, arr.top);
		}

		void copy_address(Address* dst, Address* src) {
			if (dst->level == dim - 1) {
				for (int i = 0; i < size[dst->level]; ++i)
					static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
				return;
			}
			for (int i = 0; i != size[dst->level]; i++)
			{
				Address* new_dst = static_cast<Address*>(dst->next) + i;
				Address* new_src = static_cast<Address*>(src->next) + i;
				copy_address(new_dst, new_src);
			}
		}

		void initialize_address(Address* current) {
			if (!current) return;
			if (current->level == dim - 1) {
				current->next = new int[size[current->level]];
				return;
			}

			// arr[3][4][5] 의 경우, 첫 배열 [3]에 대한 사이즈 만큼의 배열 생성
			current->next = new Address[size[current->level]];

			// 해당 레벨의 사이즈만큼만 반복함. 레벨 0의 경우 사이즈가 3이므로 3번 반복
			for (int i = 0; i != size[current->level]; i++)
			{
				// 다음 배열의 노드들의 레벨을 1씩 증가 켜줌.
				(static_cast<Address*>(current->next) + i)->level = current->level + 1;
				// dfs 처럼 재귀함수를 호출하여 같은 작업을 반복함.
				initialize_address(static_cast<Address*>(current->next) + i);
			}
		}

		void delete_address(Address* current) {
			if (!current) return;
			for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++)
			{
				delete_address(static_cast<Address*>(current->next) + i);
			}
			if (current->level == dim - 1)
			{
				delete[] static_cast<int*>(current->next);
			}
			delete[] static_cast<Address*>(current->next);
		}

		Int operator[](const int index);

		~Array() {
			delete_address(top);
			delete[] size;
		}
	};

	class Int
	{
		void* data;
		int level;
		Array* array;

	public:
		Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL) 
			: level(_level), data(_data), array(_array) {
			if (_level < 1 || index >= array->size[_level - 1])
			{
				data = NULL;
				return;
			}
			if (level == array->dim)
			{
				// data에 int 자료형을 저장하도록한다.
				data = static_cast<void*>(
					(static_cast<int*>(static_cast<Array::Address*>(data)->next) + index));
			}
			else {
				// 그렇지 않을 경우 data 에 다음 address를 넣는다.
				data = static_cast<void*>(
					static_cast<Array::Address*>(static_cast<Array::Address*>(data)->next) + index);
			}
		}
		Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

		operator int() {
			if (data) return *static_cast<int*>(data);
			return 0;
		}
		Int& operator=(const int& a) {
			if (data) *static_cast<int*>(data) = a;
			return *this;
		}
		Int operator[](const int index) {
			if (!data)return 0;
			return Int(index, level + 1, data, array);
		}
	};

	
	Int Array::operator[](const int index)
	{
		return Int(index, 1, static_cast<void*>(top), this);
	}

}

int main()
{
	int size[] = { 2, 3, 4 };
	MultiDemensionArray::Array arr(3, size);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				std::cout << i << " " << j << " " << k << " " << arr[i][j][k]
					<< std::endl;
			}
		}
	}
}