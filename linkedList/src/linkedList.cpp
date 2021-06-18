#include "linkedList.hpp"

namespace my {
    template<typename T>
    LinkedList<T>::LinkedList() {
        this->size = 0;
        this->firstNode = NULL;
        this->lastNode = NULL;
    }

    template<typename T>
    LinkedList<T>::~LinkedList() {
        clear();
    }

    template<typename T>
    void LinkedList<T>::push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (this->size == 0) {
            this->firstNode = newNode;
        }
        else {
            this->lastNode->setNextNode(newNode);
        }
        this->lastNode = newNode;
        ++(this->size); 
    }

    template<typename T>
    void LinkedList<T>::clear() {
        Node<T>* currentNode = firstNode;
        Node<T>* nextNode = NULL;
        while (currentNode != NULL) {
            nextNode = currentNode->getNextNode();
            delete currentNode;
            currentNode = nextNode;
        }
    }

    template<typename T>
    T& LinkedList<T>::get(const size_t i) {
        if (i < this->size) {
            Node<T>* temp = this->firstNode;
            for (size_t j = 0; j < i; ++j) {
                temp = temp->getNextNode();
            }
            T &data = temp->getData();
            return data;
        }
        else {
            throw std::out_of_range(
                "index " +
                std::to_string(i) +
                " out of range for linked list of size " +
                std::to_string(this->size)
            );
        }
    }

    template<typename T>
    T& LinkedList<T>::operator[](size_t i) {
        return get(i);
    }

    template<typename T>
    void LinkedList<T>::operator+=(const T val) {
        this->push_back(val);
    }

    // only just found out that it's this easy to put your
    // template class impl in the cpp with out link errors
    // makes sense when you think about it
    template class LinkedList<int>;
    template class LinkedList<double>;
    template class LinkedList<long>;
    template class LinkedList<std::string>;
}