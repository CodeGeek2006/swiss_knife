#pragma once
#include <unordered_map>
#include <stdexcept>

namespace knife::graph {
    template<typename T>
    class disjoint_set {
    private:
        std::unordered_map<T, T> parent;

    public:
        void make_set(const T& item) {
            if (parent.find(item) == parent.end()) {
                parent[item] = item; 
            }
        }

        T find(const T& item) {
            if(parent.find(item)==parent.end()){
                parent[item] = item;
            }
            // path compression
            if (parent[item] != item) {
                parent[item] = find(parent[item]); 
            }
            return parent[item];
        }

        bool join(const T& a, const T& b) {
            T rootA = find(a);
            T rootB = find(b);
            if (rootA == rootB) return false;

            parent[rootB] = rootA;
            return true;
        }

        bool connected(const T& a, const T& b) {
            return find(a) == find(b);
        }
    };
} // namespace knife::graph