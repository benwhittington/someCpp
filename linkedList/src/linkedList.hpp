#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>

#include "node.hpp"

namespace my {
    template<typename T> class LinkedList {
    private:
        Node<T>* firstNode;
        Node<T>* lastNode;

    public:
        size_t size;
        LinkedList();
        ~LinkedList();
        void push_back(T val);
        void clear();
        T& get(const size_t i);
        T& operator[](const size_t i);
        void operator+=(const T val);
    };
}