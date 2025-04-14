#pragma once

#include <stdexcept>
#include "range.hpp"
#include "../graph/list_node.hpp"

namespace knife::containers {
    template<typename T>
    class stack : public virtual range<graph::list_node<T>> {
    protected:
        graph::list_node<T>* stack_pointer;
        unsigned int length;
    
    public:
        stack() : range<graph::list_node<T>>() {
            stack_pointer = nullptr;
            length = 0;
        }
        
        bool empty() const {
            return stack_pointer == nullptr;
        }
        
        void push(T val) {
            graph::list_node<T>* nn = new graph::list_node<T>(val);
            nn->next = stack_pointer;
            stack_pointer = nn;
            length++;
        }
        
        T top() const {
            if (empty()) {
                throw std::runtime_error("Can't access top element on an empty stack");
            }
            return stack_pointer->val;
        }

        void pop() {
            if (empty()) {
                throw std::runtime_error("Can't pop from an empty stack");
            }
            graph::list_node<T>* tn = stack_pointer;
            stack_pointer = stack_pointer->next;
            delete tn;
            length--;
        }
        
        T at(int index) const {
            if (0 > index || index >= length) {
                throw std::out_of_range("Index is out of bounds");
            }
            graph::list_node<T>* cn = stack_pointer;
            for (int i = 0; i < index; i++) {
                cn = cn->next;
            }
            return cn->val;
        }
        
        T& operator[](int index) {
            if (0 > index || index >= length) {
                throw std::out_of_range("Index is out of bounds");
            }
            graph::list_node<T>* cn = stack_pointer;
            for (int i = 0; i < index; i++) {
                cn = cn->next;
            }
            return cn->val;
        }

        void insert(T val, int index) {
            if (index < 0 || index > length) {
                return;
            }
            
            if (index == 0) {
                push(val);
                return;
            }
            
            graph::list_node<T>* cn = stack_pointer;
            for (int i = 0; i < index - 1; i++) {
                cn = cn->next;
            }
            graph::list_node<T>* nn = new graph::list_node<T>(val);
            nn->next = cn->next;
            cn->next = nn;
            length++;
        }
        
        int size() const {
          return length;
        }

        friend std::ostream& operator<<(std::ostream& os, const stack& stack);
        
        graph::list_node<T>* begin() const {
            return stack_pointer;
        }

        graph::list_node<T>* end() const {
            return nullptr;
        }
        
        ~stack() {
            while (stack_pointer != nullptr) {
                graph::list_node<T>* tn = stack_pointer;
                stack_pointer = stack_pointer->next;
                delete tn;
            }
        }
    
    };
} //knife::containers
