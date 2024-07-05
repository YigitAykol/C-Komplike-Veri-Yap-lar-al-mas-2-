#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
/** 
* @file Stack 
* @description Yığıt veri yapısını bulundurur
* @course 2A
* @assignment 2.Ödev 
* @date 10.12.2023
* @author Mahmut Yiğit Aykol g201210350
*/
const int MAX_SIZE = 100; // Adjust the maximum size as needed

class Stack {
private:
    int elements[MAX_SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    
    void push(int value);

    void pop() ;

    bool isEmpty() const ;

    int top() const ;

	void print() const ;
    int returnState();
};

#endif
