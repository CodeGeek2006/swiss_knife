#pragma once

namespace knife {
    template<typename T>

    class node {
    public:
        T val;
        node* next;
        node* prev;

        node( T value = nullptr) : val(value), next(nullptr), prev(nullptr) {}
    };



    }