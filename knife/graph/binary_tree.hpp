#pragma once
namespace knife::graph {
    template<typename T>
    class binary_tree {
        public: 
            binary_tree<T>* left;
            binary_tree<T>* right;
            T val;
            binary_tree(const T& val): val(val), left(nullptr), right(nullptr){}

            binary_tree():left(nullptr), right(nullptr){}

            ~binary_tree(){
                if(this->left!=nullptr){
                    delete left;
                }
                if(this->right!=nullptr){
                    delete right;
                }
            }
    };
} // namespace knife::graph