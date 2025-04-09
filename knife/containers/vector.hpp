#pragma once
#include <iostream>

namespace knife{
    #include <iostream>
    template <typename T>
    class vector {
        T* data;
        int capacity;
        int length;

        void resize() {
            capacity += 1;
            T* _data = new T[capacity];
            for (int i = 0; i < length; i++)
                _data[i] = data[i];
            delete[] data;
            data = _data;
        }

    public:
        vector() {
            capacity = 2;
            length = 0;
            data = new T[capacity];
        }

        ~vector() {
            delete[] data;
        }

        void push_back(T value) {
            if (length == capacity)
                resize();
            data[length++] = value;
        }

        void pop_back() {
            if (length > 0)
                length--;
        }

        int size() const {
            return length;
        }

        T& operator[](int index) {
            if (index < 0 || index >= length)
                throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        T* begin() {
            return data;
        }

        T* end() {
            return data + length;
        }

        void resize(int new_size) {
            if (new_size < length) {
                length = new_size;
            }
            else if (new_size > length) {
                if (new_size > capacity) {
                    while (capacity < new_size) {
                        resize();
                    }
                }
                for (int i = length; i < new_size; ++i) {
                    data[i] = T();
                }
                length = new_size;
            }
        }
        void resize(int new_size, const T& value) {
            if (new_size < length) {
                length = new_size;
            }
            else if (new_size > length) {
                if (new_size > capacity) {
                    while (capacity < new_size) {
                        resize();
                    }
                }
                for (int i = length; i < new_size; ++i) {
                    data[i] = value;
                }
                length = new_size;
            }
        }
        void erase(int index) {
            if (index < 0 || index >= length)
                throw std::out_of_range("Index out of bounds");

            for (int i = index; i < length - 1; i++) {
                data[i] = data[i + 1];
            }

            length--;
        }
    };
}
