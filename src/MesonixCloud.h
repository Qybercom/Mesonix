#pragma once

#include <Arduino.h>
#include <Mesonix.h>

// https://esp32.com/viewtopic.php?t=30226
namespace Qybercom {
	namespace Mesonix {
		class MesonixCloud {

		};
	}
}
/*
template <typename T>
class ListValue {
public:
	ListValue() {
		capacity = 4;
		count = 0;
		items = new T[capacity];
	}

	~ListValue() {
		delete[] items;
	}

	bool add(const T& value) {
		if (count >= capacity) grow();
		items[count++] = value;
		return true;
	}

	T get(int index) const {
		return (index >= 0 && index < count) ? items[index] : T();
	}

	int size() const {
		return count;
	}

private:
	T* items;
	int count;
	int capacity;

	void grow() {
		int newCap = capacity * 2;
		T* newItems = new T[newCap];
		for (int i = 0; i < count; ++i)
			newItems[i] = items[i];
		delete[] items;
		items = newItems;
		capacity = newCap;
	}
};

template <typename T>
class ListPtr {
public:
	ListPtr() {
		capacity = 4;
		count = 0;
		items = new T*[capacity];
	}

	~ListPtr() {
		for (int i = 0; i < count; ++i) delete items[i];
		delete[] items;
	}

	bool emplaceNew(...) = delete; // forbidden (?) if the type is pointer (???)
	template <typename... Args>
	bool emplace(Args... args) {
		if (count >= capacity) {
			if (!grow()) return false;
		}
		items[count++] = new T(args...);
		return true;
	}

	bool add(T* ptr) {
		if (count >= capacity) grow();
		items[count++] = ptr;
		return true;
	}

	T* get(int index) {
		return (index >= 0 && index < count) ? items[index] : 0;
	}

	int size() const {
		return count;
	}

private:
	T** items;
	int count;
	int capacity;

	void grow() {
		int newCap = capacity * 2;
		T** newItems = new T*[newCap];
		for (int i = 0; i < count; ++i)
			newItems[i] = items[i];
		delete[] items;
		items = newItems;
		capacity = newCap;
	}
};
*/


/*
int main() {
	List<int> nums;
	nums.add(10);
	nums.add(20);
	nums.add(30);

	for (int i = 0; i < nums.size(); ++i) {
		std::cout << nums.get(i) << std::endl;
	}

	return 0;
}

int main() {
	List<Item> list;

	list.emplace(1);
	list.emplace(2);
	list.emplace(3);
	list.emplace(4);
	list.emplace(5); // trigger grow

	for (int i = 0; i < list.size(); ++i) {
		Item* item = list.get(i);
		if (item) item->print();
	}

	return 0;
}
*/