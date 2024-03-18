#pragma once

#include  <iostream>
using namespace std;

class Array {
protected:
	static const int SIZE = 10;
	unsigned int arr[SIZE]{};
	unsigned int elementsCount = 0;

public:
	int getSize() const {
		return elementsCount;
	}

	void addElement(unsigned int value) {
		arr[elementsCount++] = value;
	}

	void print() const {
		for (int i = 0; i < elementsCount; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	unsigned int operator[] (unsigned int index) const {
		return arr[index];
	}

	virtual Array sum(const Array& right) {
		return Array();
	}
};

class ArratFirst : public Array {
public:
	Array sum(const Array& right) override {
		Array result;

		for (int i = 0; i < this->elementsCount; i++) {
			result.addElement(arr[i] + right[i]);
		}
		return result;
	}
};

class Task1 {
public:
	static void run() {
		Array arr1;
		arr1.addElement(5);
		arr1.addElement(2);
		arr1.addElement(10);

		ArratFirst arr2;
		arr2.addElement(2);
		arr2.addElement(7);
		arr2.addElement(20);

		Array arrayResult = arr2.sum(arr1);
		arrayResult.print();
	}
};
