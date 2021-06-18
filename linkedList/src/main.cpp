#include <iostream>

#include "node.hpp"
#include "linkedList.hpp"

int main() {
    my::LinkedList<int> list;
    list.push_back(100);

    for (size_t i = 0;i < 10; ++i) {
        // list.push_back(i);
        list += i;
    }

    for (size_t i = 0;i < 10; ++i) {
        std::cout << list[i] << std::endl;
    }

    std::cout << list[list.size] << std::endl;

    return 0;
}