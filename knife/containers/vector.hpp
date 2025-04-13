#pragma once
#include <stdexcept>
#include "range.hpp"

namespace knife::containers{
template <typename T>
    class vector : public virtual range<T> {
        T* data;
        unsigned int capacity;
        unsigned int length;

    public:

        vector() {
            capacity = 2;
            length = 0;
            data = new T[capacity];
        }

        vector(std::initializer_list<T> init) {
            length = capacity = init.size();
            data = new T[capacity];
            unsigned int i = 0;
            for (const T& value : init) {
                data[i++] = value;
            }
        }

        vector(unsigned int size, const T& value) {
            this->capacity = size;
            this->length = size;
            data = new T[capacity];
            for (unsigned int i = 0; i < length; ++i) {
                data[i] = value;
            }
        }

        vector(unsigned int size) {
            capacity = size;
            length = size;
            data = new T[capacity];
            for (unsigned int i = 0; i < length; ++i) {
                data[i] = T();
            }
        }

        ~vector() {
            delete[] data;
        }

        void push_back(T value) {
            if (length == capacity) 
                resize(length + 1);
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

        T at(int index) const {
            if (index < 0 || index >= length)
                throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        T* begin() const {
            return data;
        }

        T* end() const {
            return data + length;
        }

        friend std::ostream& operator<<(std::ostream& os, const stack& stack);

        void resize(int new_size) {
            if (new_size < length) {
                length = new_size;
            }
            else if (new_size > length) {
                if (new_size > capacity) { 
                    capacity += new_size-capacity;
                    T* _data = new T[capacity];
                    for (int i = 0; i < length; i++)
                        _data[i] = data[i];
                    delete[] data;
                    data = _data;
                }
                for (int i = length; i < new_size; ++i) {
                    data[i] = T();
                }
                length = new_size;
            }
        }

    void resize(unsigned int new_size, const T& value) {
            if (new_size < length) {
                length = new_size;
            }
            else if (new_size > length) {
                if (new_size > capacity) {
                    capacity += new_size-capacity;
                    T* _data = new T[capacity];
                    for (int i = 0; i < length; i++)
                        _data[i] = data[i];
                    delete[] data;
                    data = _data;
                }
                for (int i = length; i < new_size; ++i) {
                    data[i] = value;
                }
                length = new_size;
            }
        }

    void erase(T* pos) {
            if (pos < data || pos >= data + length)
                throw std::out_of_range("Iterator out of bounds");
            // Shift elements left to fill the gap
            for (T* p = pos; p < data + length - 1; ++p) {
                *p = *(p + 1);
            }

            // Decrease length
            --length;
        }
};
}