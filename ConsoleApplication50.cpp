#include <iostream>

class CharQueue {
private:
    struct Node {
        char* data;
        Node* next;
        Node(const char* value) {
            int len = 0;
            while (value[len] != '\0') {
                len++;
            }
            data = new char[len + 1];
            for (int i = 0; i <= len; ++i) {
                data[i] = value[i];
            }
            next = nullptr;
        }
        ~Node() {
            delete[] data;
        }
    };

    Node* frontPtr;
    Node* rearPtr;

public:
    CharQueue() : frontPtr(nullptr), rearPtr(nullptr) {}

    ~CharQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    void enqueue(const char* value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            if (frontPtr == nullptr) {
                rearPtr = nullptr;
            }
        }
        else {
            std::cout << "Queue is empty, cannot dequeue.\n";
        }
    }

    const char* front() const {
        if (!isEmpty()) {
            return frontPtr->data;
        }
        else {
            std::cout << "Queue is empty, cannot retrieve front element.\n";
            return nullptr;
        }
    }
};

int main() {
    CharQueue queue;
    queue.enqueue("Hello");
    queue.enqueue("World");
    queue.enqueue("!");

    while (!queue.isEmpty()) {
        std::cout << queue.front() << " ";
        queue.dequeue();
    }
}