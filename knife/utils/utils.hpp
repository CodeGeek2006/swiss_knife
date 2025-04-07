namespace knife::utils {
    template<typename T>
    void swap(T& first, T& second){
        T temp = first;
        first = second;
        second = temp;
    }

    template<typename T>
    T min(const T& first, const T& second){
        return (first < second) ? first : second;  
    }

    template<typename T>
    T max(const T& first, const T& second){
        return (first > second) ? first : second;  
    }
} // knife::utils