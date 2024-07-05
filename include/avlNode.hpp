#include"AvlAgaci.hpp"
/** 
* @file avlNode 
* @description Doubly linked list in nodenu barındırır
* @course 2A
* @assignment 2.Ödev 
* @date 10.12.2023
* @author Mahmut Yiğit Aykol g201210350
*/
class avlNode{
	public:
		AvlAgaci avlTree;
		Stack a, cikti;
		int position;
		avlNode* next;
		avlNode* prev;
	avlNode();
    ~avlNode();
};