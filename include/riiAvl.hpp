#include"avlNode.hpp"
/** 
* @file Main 
* @description riiAvl avl agacını ve stack yapısını barıdıran doubly linked list
* @course 2A
* @assignment 2.Ödev 
* @date 14.12.2023
* @author Mahmut Yiğit Aykol g201210350
*/
class riiAvl
{
	public:
		avlNode* head;
        int sizeo;
        int son;
        int position1;
		riiAvl() : head(nullptr), sizeo(0), son(0), position1(0) {}
        ~riiAvl(){
            //std::cout << "silindi"<< std::endl;
            delete head;
        }
		void newNode();
		avlNode *returnLastNode();

		void print();

        void removeAt(int index) ;

        void pop_at() ;
        void pop_Back();


        void removeAti(avlNode* current3) ;
        
    

};