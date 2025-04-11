#pragma once
#include <stdexcept>

namespace knife{
    template <typename T>
    class vector {
        T* data;
        unsigned int capacity;
        unsigned int length;

    public:

        //Default constructor
        vector() {
            capacity = 2;
            length = 0;
            data = new T[capacity];
        }

        // Constructor that takes an initializer list
        vector(std::initializer_list<T> init) {
            length = capacity = init.size();
            data = new T[capacity];
            unsigned int i = 0;
            for (const T& value : init) {
                data[i++] = value;
            }
        }

        //Constructor with initial size and value
        vector(unsigned int capacity, const T& value) {
            this->capacity = capacity;
            length = capacity;
            data = new T[capacity];
            for (std::size_t i = 0; i < length; i++) {
                data[i] = value;
            }
        }

        ~vector() {
            delete[] data;
        }

        //Constructor with initial size
        vector(unsigned int capacity) {
          this->capacity = capacity;
          length = 0;
          data = new T[capacity];
        }

        // Add value to the back
        void push_back(T value) {
            if (length == capacity) //If there is no capacity lefts, adds capacity (+1)
                resize(length + 1);
            data[length++] = value;
        }

        //Delete the last element
        void pop_back() {
            if (length > 0)
                length--;
        }

        //Return size
        int size() const {
            return length;
        }

        //Allows using [] operator (to use vec[index])
        T& operator[](int index) const{
            if (index < 0 || index >= length)
                throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        //Gives the address of first element
        T* begin() const {
            return data;
        }

        //Gives the address of last element + 1 to you for ranged loop
        T* end() const {
            return data + length;
        }

        //Change size of the vector
        void resize(int new_size) {
            if (new_size < length) {
                length = new_size; //If new_size is less than initial size, decreases the initial size to New_size
            }
            else if (new_size > length) {
                if (new_size > capacity) { // if new_size more than capacity, adds needed capacity
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

        // Resize the vector to a new size and fill new elements with the given value
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

        // Erase a single element at the given iterator
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