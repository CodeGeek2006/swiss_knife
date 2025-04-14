#pragma once

namespace knife::graph {
    // cautious, this class does not have destructor
    template<typename T>
    class list_node {
        public:
            list_node* next;
            list_node* prev;
            T val;
            
            list_node() {
                next = nullptr;
                prev = nullptr;
            }
            list_node(T val) {
                next = nullptr;
                prev = nullptr;
                this->val = val;
            }
    };
} // namespace knife::graph
