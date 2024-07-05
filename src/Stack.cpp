#include"Stack.hpp"

void Stack:: push(int value) {
        if (topIndex < MAX_SIZE - 1) {
            elements[++topIndex] = value;
        } else {
            std::cout << "Stack overflow. Cannot push." << std::endl;
        }
    }

    void Stack:: pop() {
        if (!isEmpty()) {
            --topIndex;
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    bool Stack:: isEmpty() const {
        return topIndex == -1;
    }

    int Stack::top() const {
        if (!isEmpty()) {
            return elements[topIndex];
        } else {
            
            return -1;//0
        }
    }

	void Stack::print() const {
        if (!isEmpty()) {
            std::cout << "Stack elements: ";
            for (int i = 0; i <= topIndex; ++i) {
                std::cout << elements[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Stack is empty." << std::endl;
        }
    }
    int Stack::returnState() 
    {
        return topIndex;
    }