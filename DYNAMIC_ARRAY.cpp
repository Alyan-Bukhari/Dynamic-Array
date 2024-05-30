#include <iostream>

class DynamicArray {
private:
  int capacity;
  int size;
  int* data;

  void resize(int newCapacity) {
    int* newData = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
  }

public:
  DynamicArray(int initialCapacity = 2) : capacity(initialCapacity), size(0) {
    data = new int[capacity];
  }

  ~DynamicArray() {
    delete[] data;
  }

  bool isEmpty() {
    return size == 0;
  }

  int getSize() {
    return size;
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      std::cerr << "Error: Index out of bounds!" << std::endl;
      return -1; // Or a specific value to indicate error
    }
    return data[index];
  }

  int push(int element) {
    if (size == capacity) {
      resize(capacity * 2);
    }
    data[size++] = element;
    return 0; // Or a specific value to indicate success (optional)
  }

  int pop() {
    if (isEmpty()) {
      std::cerr << "Error: Array is empty!" << std::endl;
      return -1; // Or a specific value to indicate error
    }
    return data[--size];
  }
};

int main() {
  DynamicArray arr;
  arr.push(10);
  arr.push(20);
  arr.push(30);

  std::cout << arr.get(1) << std::endl;  // Output: 20

  arr.pop();
  arr.pop();

  std::cout << arr.getSize() << std::endl;  // Output: 1

  if (arr.get(5) == -1) {
    std::cerr << "Error: Out-of-bounds access!" << std::endl;
  }

  return 0;
}
