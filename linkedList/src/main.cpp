#include <iostream>
#include <string>

#include "node.hpp"
#include "linkedList.hpp"

int main() {
    my::LinkedList<std::string> list;
    list.push_back("test");

    for (size_t i = 0;i < 10; ++i) {
        // list.push_back(i);
        // list += "a";
        list[i] = "should err";
    }

    for (size_t i = 0;i < 10; ++i) {
        std::cout << list[i] << std::endl;
    }

    list[0] = "test2";

    for (size_t i = 0; i < 10; ++i) {
        std::cout << list[i] << std::endl;
    }

    return 0;
}