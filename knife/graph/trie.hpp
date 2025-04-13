#include <unordered_map> 

namespace knife::graph {
    template<typename T, typename value_type>
    class trie {
        public:    
            std::unordered_map<T, trie<T, value_type>*> children;
            std::optional<value_type> val;
            trie() = default;
            trie(const T& _val): val(std::move(_val)){}
    };
}