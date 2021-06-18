#include "node.hpp"

namespace my {
    template <typename T>
    Node<T>::Node() {
        nextNode = 0;
    }

    template <typename T>
    Node<T>::Node(T data) {
        nextNode = 0;
        setData(data);
    }

    template <typename T>
    void Node<T>::setData(T data) {
        this->data = data;
    }

    template <typename T>
    T& Node<T>::getData() {
        return this->data;
    }

    template <typename T>
    void Node<T>::setNextNode(Node* nextNode) {
        this->nextNode = nextNode;
    }

    template <typename T>
    Node<T>* Node<T>::getNextNode() const {
        return this->nextNode;
    }

    template <typename T>
    void Node<T>::removeNextNode() {
        this->nextNode = 0;
    }

    template class Node<int>;
    template class Node<double>;
    template class Node<long>;
    template class Node<std::string>;
}