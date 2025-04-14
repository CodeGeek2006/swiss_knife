#pragma once

namespace knife::graph {
    // cautious, this class does not have destructor
    template<typename T>
    class list_node {
        public:
            list_node* next;
            T val;
            
            list_node() {
                next = nullptr;
            }
            list_node(T val) {
                next = nullptr;
                this->val = val;
            }
    };
} // namespace knife::graph
