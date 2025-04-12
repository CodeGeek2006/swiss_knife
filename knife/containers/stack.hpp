#include <iostream>
#include <stdexcept>

namespace knife::containers {
    template<typename T>
    class stack {
    protected:
        class stack_node {
        public:
            stack_node* next;
            T data;
            
            stack_node() {
                next = nullptr;
            }
            stack_node(T data) {
                next = nullptr;
                this->data = data;
            }
        };
    
        stack_node* stack_pointer;
        int size;
    
    public:
        // initializes stack
        stack() {
            stack_pointer = nullptr;
            size = 0;
        }
        
        // checks if stack is empty
        bool is_empty() const {
            return stack_pointer == nullptr;
        }
        
        // adds new node
        void stack_push(T data) {
            stack_node* nn = new stack_node(data);
            nn->next = stack_pointer;
            stack_pointer = nn;
            size++;
        }
        
        // deletes first node and returns its value
        T stack_pop() {
            if (is_empty()) {
                throw std::runtime_error("Can't pop from an empty stack");
            }
            stack_node* tn = stack_pointer;
            T val = tn->data;
            stack_pointer = stack_pointer->next;
            delete tn;
            size--;
            return val;
        }
        
        // gets value at index (stack pointer = 0)
        T get_val_at_index(int index) {
            if (0 > index || index >= size) {
                throw std::out_of_range("Index is out of bounds");
            }
            stack_node* cn = stack_pointer;
            for (int i = 0; i < index; i++) {
                cn = cn->next;
            }
            return cn->data;
        }
        
        // inserts at index
        void insert_at_index(T data, int index) {
            if (index < 0 || index > size) {
                return; // invalid index
            }
            
            if (index == 0) {
                stack_push(data); // insert at top
                return;
            }
            
            stack_node* cn = stack_pointer;
            for (int i = 0; i < index - 1; i++) {
                cn = cn->next;
            }
            stack_node* nn = new stack_node(data);
            nn->next = cn->next;
            cn->next = nn;
            size++;
        }
        
        // returns the size of stack
        int stack_size() const {
          return size;
        }
        
        // outputs the stack
        void print_stack() const{
            if (is_empty()) {
                std::cout << "Stack is empty" << std::endl;
                return;
            }
            stack_node * cn = stack_pointer;
            while (cn != nullptr) {
                std::cout << cn -> data << " ";
                cn = cn -> next;
            }
            std::cout << std::endl;
        }
        
        stack_node* begin() const {
            return stack_pointer;
        }

        stack_node* end() const {
            return nullptr;
        }
        
        // destructor
        ~stack() {
            while (stack_pointer != nullptr) {
                stack_node* tn = stack_pointer;
                stack_pointer = stack_pointer->next;
                delete tn;
            }
        }
    
    };
} //knife::containers
