#pragma once

namespace my {
    template<typename T> class Node {
    private:
        Node* nextNode;
        T data;

    public:
        Node() {
            nextNode = 0;
        }

        Node(T data) {
            nextNode = 0;
            setData(data);
        }

        void setData(T data) {
            this->data = data;
        }

        T getData() const {
            return this->data;
        }

        void setNextNode(Node* nextNode) {
            this->nextNode = nextNode;
        }

        Node* getNextNode() {
            return this->nextNode;
        }

        void removeNextNode() {
            this->nextNode = 0;
        }
    };
}