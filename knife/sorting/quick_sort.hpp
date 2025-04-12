#include "../utils/utils.hpp"
#include <iostream>

namespace knife::sorting {
    template <typename iterator, typename comparator>
    void quick_sort(const iterator& begin, const iterator& end, const comparator& compare){
        if (begin >= end || end - begin <= 1) return;
        
        iterator pivot = begin + (end - begin)/2;
        iterator right = end - 1;
        iterator left = begin;

        while (left <= right){
            while (compare(*left, *pivot)){
                ++left;
            }
            while (compare(*pivot, *right)){
                --right;
            }
            if (left <= right){
                utils::swap(*left, *right);

                if (left == pivot){
                    pivot = right;
                } else if (right == pivot){
                    pivot = left;
                }

                ++left;
                --right;
            }
        }
        
        iterator _end = utils::min(right + 1, end);
        quick_sort(begin, _end, compare);
        quick_sort(left, end, compare);
    }

    template <typename iterator>
    void quick_sort(iterator* begin, iterator* end) {
        quick_sort(begin, end, [](const iterator& a, const iterator& b) {
            return a < b;
        });
    }
} // knife::sorting namespace
