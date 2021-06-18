#pragma once

#include <string>

namespace my {
    template<typename T> class Node {
    private:
        Node* nextNode;

    public:
        T data;
        Node();
        Node(const T data);
        void setData(const T data);
        T& getData();
        void setNextNode(Node* nextNode);
        Node* getNextNode() const;
        void removeNextNode();
    };
}