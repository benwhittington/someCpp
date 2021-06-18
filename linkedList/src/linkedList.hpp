#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>

#include "node.hpp"

namespace my {
    template<typename T> class LinkedList {
    private:

    public:
        Node<T>* firstNode;
        Node<T>* lastNode;
        size_t size;
        LinkedList();
        ~LinkedList();
        void push_back(T val);
        T pop_front();
        void clear();
        T& get(const size_t i);
        T& operator[](const size_t i);
        void operator+=(const T val);
    };
}