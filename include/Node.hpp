#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
/** 
* @file Node 
* @description Agac nodelarını barındırır
* @course 2A
* @assignment 2.Ödev 
* @date 10.12.2023
* @author Mahmut Yiğit Aykol g201210350
*/
class Node{
    public:
    
    int key, height;
    Node* sol;
    Node* sag;
    
    ~Node()
    {
        delete sol;
        delete sag;
    }
    Node(int k){
        height = 1;
        key = k;
        sol = NULL;
        sag = NULL;
    }

};



#endif