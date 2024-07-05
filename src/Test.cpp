
//#include <iostream>
//#include"AvlAgaci.hpp"
/** 
* @file Main 
* @description Main i barındırır.Dosya okuması yapılır.Program in önemli bazı fonksiyonları çağrılır
* @course 2A
* @assignment 2.Ödev 
* @date 10.12.2023
* @author Mahmut Yiğit Aykol g201210350
*/

#include"riiAvl.hpp"
#include"stack.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <iostream> 

void separate(std::string a, avlNode* current2)
{
	std::string inputString = a;
    std::istringstream iss(inputString);

    
    int num;
    while (iss >> num) {
        
		current2->avlTree.insert(num);
	    
		
    }
}

int stackOperations(avlNode* current3, bool switcher)
{
    
    int ad = current3->a.top();
    
    int far=0;//1
    int ko=0;//ko=0 , -1
    int u=0;
    
    while(current3!=NULL)
    {

        
        if(current3->next!=NULL)
        {
            

            if(ad<current3->next->a.top()&&switcher==true)
            {
                ad = current3->next->a.top();
                ko=far;

                
            }
            else if(ad>current3->next->a.top()&&switcher==false)
            {
                ad = current3->next->a.top();
                ko=far;
                
            }
            else
            {
                //std::cout << ad<<"en basta " <<ko << std::endl;
            }
                
                
            //far++;
        }
        else{
            
        }
        far++;
        u++;
        current3 = current3->next;    
        

    }
    
    return ad;

}

void removes(avlNode* current3, int k)
{
    int i=0;
   
    while(current3!=NULL&& i!=k)
    {


        current3 = current3->next;
        i++;
    } 
    current3->a.print();
    current3->a.pop();
    current3->a.print();
       
}

int main(){ 
    
	
	
	std::ifstream fin ("Veri.txt");
	std::string temp;
	char c;
	int ar;
	
	int number;
	riiAvl rr;

	if (fin.is_open()) {
        std::string line;
        while (std::getline(fin, line)) {
            
			rr.newNode();
			avlNode* current2 = rr.returnLastNode();

			separate(line, current2);
			
            current2->avlTree.postorderLeafTraversalLeaf();
            current2->a = current2->avlTree.b;
            

        
            //std::cout << current2->avlTree.d << std::endl;

        }
        fin.close();
    } else {
        std::cerr << "Unable to open file: " << std::endl;
    }

    avlNode* current3 = rr.head;
    
    
    bool switcht = false;
    bool ayniDurumu;
    int o=0;//çıkarılanları ayrı stack e koy 
    
    int s=0;
    int deletesionNum=0;//1

    bool a=false;
    //rr.pop_at();
    while(deletesionNum!=rr.sizeo)
    {
        
        o = stackOperations(rr.head, switcht);

        
        ayniDurumu=false;
        
        current3 = rr.head;
        int y=0;//0
        while (current3!=NULL)//current3!=NULL
        {  
            a=false;
            if(current3->a.returnState()!=-1)//current3->a.isEmpty()!=-1
            {
                if(current3->a.top()==o && ayniDurumu==false)
                {
                    ayniDurumu=true;
                    //std::cout << " bos degil tepedeki"<<current3->a.top()<< std::endl;
                    current3->cikti.push(o); 
                    current3->a.pop();
                    if(current3->a.returnState()==-1)
                    {
                        
                        if(rr.head!=current3)
                        {
                            
                            avlNode* current2 = current3;
                            current3=current3->prev;
                            rr.removeAti(current2);

                            switcht = true;

                            rr.pop_at();
                            a=false;
                            deletesionNum++;
                            
                            
                        }
                        else {
                            avlNode* current2 = current3;
                            if(current3->next!=NULL) {
                                current3=current3->next;
                                rr.removeAti(current2);
                                rr.pop_at();
                               
                                switcht = true;

                                deletesionNum++;
                            }
                            else {
                                deletesionNum++;
                                
                            }
                            
                        }

                        
                        
                        
                    }
                    
                   
                }
                
                

            }
            
            if(a!=true)
            {
                //std::cout << current3->avlTree.d << std::endl;
                current3 = current3->next;
            }
            
           
            //std::cout << current3->avlTree.d <<" ";
            y++;
            
           
        }
        
        

        

        if(switcht == true)
        {
            switcht = false;
        }
        else
            switcht = true;

        s++;
    }

    

    if(rr.head->a.returnState()!=-1)
    {
        rr.head->a.pop();
    }
    
    std::cout << "===================================="<<std::endl;
    std::cout << "|                                  |"<<std::endl;
    std::cout << "|                                  |"<<std::endl;
    std::cout << "|     Son Karakter:"<<(char)rr.son<<"               |"<<std::endl;
    std::cout << "|                 "<<  rr.position1 <<"            |"<<std::endl;
    std::cout << "|                                  |"<<std::endl;
    std::cout << "===================================="<<std::endl;
	
    system("PAUSE");    
    system("cls");
	return 0;
}
