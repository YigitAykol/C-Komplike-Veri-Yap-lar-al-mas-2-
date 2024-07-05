#include"riiAvl.hpp"

void riiAvl::newNode()
{
			if(head==NULL)
			{
				head = new avlNode();
                sizeo++;
                head->position=sizeo;
				return;
			}
			else{

			avlNode* newNode = new avlNode();
        	newNode->next = nullptr;
        	
            avlNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
			
            

            sizeo++;
            newNode->position=sizeo;
			}
		}

		avlNode* riiAvl::returnLastNode()
		{
			avlNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }

			return current;
		}

		void riiAvl::print()
		{
			avlNode* current = head;
            while (current->next != nullptr) {
				//current->avlTree.inOrder();
				current->avlTree.postorderTraversal();
				
                current = current->next;
            }
			//current->avlTree.inOrder();
			current->avlTree.postorderTraversal();
			
		}

        void riiAvl::removeAt(int index) {

            if (index < 0) {
                std::cerr << "Invalid index" << std::endl;
                return;
            }

            avlNode* current = head;
            int currentIndex = 0;

            while (current && currentIndex < index) {
                current = current->next;
                currentIndex++;
            }

            if (!current) {
                std::cerr << "Index out of bounds" << std::endl;
                return;
            }

            if (current->next!=NULL) {
                current->next->prev = current->prev;
            }

            if (current->prev!=NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            current->next=NULL;
            current->prev=NULL;
        }

        void riiAvl::pop_at() {     
            avlNode* temp=head;
            int ascii;

            while(temp!=NULL)
            {
                
                //temp->cikti.print();
                while (temp->cikti.returnState()!=-1)
                {
                   temp->a.push(temp->cikti.top());
                   temp->cikti.pop();
                }
                //temp->a.print();
                //std::cout<< std::endl;
                ascii = temp->avlTree.d%(90-65 + 1) + 65;
                std::cout << (char)ascii<<"  ";
                son=ascii;
                position1=temp->position;
                temp=temp->next;
            }
            system("cls");
            
            std::cout<< std::endl;
        }
        void riiAvl::pop_Back() {     
            avlNode* temp=head;
            int ascii;

            while(temp!=NULL)
            {
                std::cout << temp->avlTree.d<<"  ";
                ascii = temp->avlTree.d%(90-65 + 1) + 65;
                std::cout << (char)ascii<<"  ";
                temp=temp->next;
            }
            std::cout<< std::endl;
        }
        

        void riiAvl::removeAti(avlNode* current3) {
            if(current3==head)//******************
            {
                if(current3->next!=NULL)
                {
                    avlNode* temp=head;
                    head=head->next;
                    head->prev=NULL;
                    
                    temp->next=NULL;
                    temp->prev=NULL;
                    delete temp;
                    return;
                }
                
            }
            
            if(current3 -> next == NULL)  
            {
                
                current3->prev->next=NULL;
                current3->next=NULL;
                current3->prev=NULL;
                delete current3;
                

                return;   
            }  
            if (current3->next!=NULL) {
                current3->next->prev = current3->prev;
            }

            if (current3->prev!=NULL) {
                current3->prev->next = current3->next;
               
            } else {
                head = current3->next;

            }

            current3->next=NULL;
            current3->prev=NULL;
            delete current3;

        }