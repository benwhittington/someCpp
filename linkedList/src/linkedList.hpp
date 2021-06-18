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
        
        LinkedList() {
            this->size = 0;
            this->firstNode = NULL;
            this->lastNode = NULL;
        }

        ~LinkedList() {
            clear();
        }

        void push_back(T val) {
            Node<T>* newNode = new Node<T>(val);
            if (this->size == 0) {
                this->firstNode = newNode;
                this->lastNode = newNode;
            }
            else {
                this->lastNode->setNextNode(newNode);
                this->lastNode = newNode;
            }
                ++(this->size); 
        }

        void clear() {
            Node<T>* currentNode = firstNode;
            Node<T>* nextNode = NULL;
            while (currentNode != NULL) {
                nextNode = currentNode->getNextNode();
                delete currentNode;
                currentNode = nextNode;
            }
        }

        T get(const size_t i) const {
            if (i < this->size) {
                Node<T>* temp = this->firstNode;
                for (size_t j = 0; j < i; ++j) {
                    temp = temp->getNextNode();
                }
                double data = temp->getData();
                return data;
            }
            else {
                throw std::out_of_range(
                    "index " 
                    + std::to_string(i) 
                    + " out of range for linked list of size " 
                    + std::to_string(this->size)
                );
            }
        }

        T operator[](size_t i) {
            return get(i);
        }

        void operator+=(T val) {
            this->push_back(val);
        }
    };
}