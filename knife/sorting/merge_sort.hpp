namespace knife::sorting {

    template <typename iterator, typename comparator>
    void merge(iterator* begin, iterator* mid, iterator* end, comparator comp) {
        const auto size = end - begin;
        iterator* temp = new iterator[size];
        iterator* temp_ptr = temp;
        
        iterator* left = begin;
        iterator* right = mid;
        
        while (left != mid && right != end) {
            if (comp(*left, *right)) {
                *temp_ptr++ = std::move(*left++);
            } else {
                *temp_ptr++ = std::move(*right++);
            }
        }
        
        while (left != mid) *temp_ptr++ = std::move(*left++);
        while (right != end) *temp_ptr++ = std::move(*right++);
        
        std::move(temp, temp + size, begin);
        delete[] temp;
    }

    template <typename iterator, typename comparator>
    void merge_sort(iterator* begin, iterator* end, comparator comp) {
        const auto size = end - begin;
        if (size <= 1) return;
        
        iterator* mid = begin + size / 2;
        
        merge_sort(begin, mid, comp);
        merge_sort(mid, end, comp);
        
        merge(begin, mid, end, comp);
    }

    template <typename iterator>
    void merge_sort(iterator* begin, iterator* end) {
        merge_sort(begin, end, [](const iterator& a, const iterator& b) {
            return a < b;
        });
    }
} // knife::sorting namespace