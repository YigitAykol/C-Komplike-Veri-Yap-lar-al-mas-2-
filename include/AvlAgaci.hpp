#ifndef AvlAgaci_HPP
#define AvlAgaci_HPP

#include"Node.hpp"
#include"Stack.hpp"
//#include<iostream>
using namespace std;
/** 
* @file AvlAgaci 
* @description Avl agacını barındırır
* @course 2A
* @assignment 2.Ödev 
* @date 10.12.2023
* @author Mahmut Yiğit Aykol g201210350
*/

class AvlAgaci{
    //public: 
    
    Node* root;
    
    
    int getHeight(Node* node);

    int getBalanceFactor(Node* node);

    void updateHeight(Node* node) ;

    Node* sagRotate(Node* y) ;

    Node* solRotate(Node* x);

    Node* insert(Node* node, int key) ;

    void inOrderTraversal(Node* node);
    
    void postorderTraversal(Node* node) const;

    void  postorderTraversalLeaf(Node* node) ;



public:
    int size, ki;
    int j=0;
    
    int d;
    Stack b;
   
    AvlAgaci();
    
    
    ~AvlAgaci();

    void insert(int key);
    
    void inOrder();

    void postorderTraversal() const;

    void postorderLeafTraversalLeaf() ;


   
};
#endif
