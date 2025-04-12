namespace knife::sorting{
    template <typename M>
    std::vector<M> merge(std::vector<M> left, std::vector<M> right){
        std::vector<M> result;
        int l=0,r=0;
        while(l!=left.size() || r!=right.size()){
            if(l==left.size()){
                result.push_back(right[r]);
                r++;
            } else if(r == right.size()){
                result.push_back(left[l]);
                l++;
            } else if(left[l]<right[r]){
                result.push_back(left[l]);
                l++;
            } else {
                result.push_back(right[r]);
                r++;
            }
        }
        return result;
    }

    template <typename G>
    std::vector<G> merge_recursion(int begin, int end, std::vector<G> arr){
        if(begin==end){
            return {arr[begin]};
        }
        int mid = (begin+end)/2;
        std::vector<G> left = merge_recursion(begin, mid, arr);
        std::vector<G> right = merge_recursion(mid+1, end, arr);
        return merge(left, right);
    }

    template <typename T>
    std::vector<T> merge_sort(std::vector<T> arr) {
        if(arr.size()==0){
            return {};
        }
        return merge_recursion(0, int(arr.size()-1), arr);
    }
}

