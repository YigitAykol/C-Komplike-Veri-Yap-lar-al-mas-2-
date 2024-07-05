#include"AvlAgaci.hpp"

int AvlAgaci::getHeight(Node* node) {
        return (node) ? node->height : 0;
    }

    int  AvlAgaci::getBalanceFactor(Node* node) {
        return getHeight(node->sol) - getHeight(node->sag);
    }

    void  AvlAgaci::updateHeight(Node* node) {
        node->height = 1 + std::max(getHeight(node->sol), getHeight(node->sag));
    }

    Node*  AvlAgaci::sagRotate(Node* y) {
        Node* x = y->sol;
        Node* T2 = x->sag;

        x->sag = y;
        y->sol = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node*  AvlAgaci::solRotate(Node* x) {
        Node* y = x->sag;
        Node* T2 = y->sol;

        y->sol = x;
        x->sag = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node*  AvlAgaci::insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->sol = insert(node->sol, key);
            size++;
        } else if (key > node->key) {
            node->sag = insert(node->sag, key);
            size++;
        } else {
            
            return node;
        }

        
        updateHeight(node);

        
        int balance = getBalanceFactor(node);

        // sol Heavy
        if (balance > 1) {
            if (key < node->sol->key) {
                return sagRotate(node);
            } else {
                node->sol = solRotate(node->sol);
                return sagRotate(node);
            }
        }

        // sag Heavy
        if (balance < -1) {
            if (key > node->sag->key) {
                return solRotate(node);
            } else {
                node->sag = sagRotate(node->sag);
                return solRotate(node);
            }
        }

        return node;
    }

    void  AvlAgaci::inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->sol);
            std::cout << node->key << " ";
            inOrderTraversal(node->sag);
        }
    }
      void  AvlAgaci::postorderTraversal(Node* node) const {
        if (node != nullptr) {
            postorderTraversal(node->sol);
            postorderTraversal(node->sag);
            std::cout << node->key << " ";
        }
    }

    void  AvlAgaci::postorderTraversalLeaf(Node* node)  {//void

        
        if (node != nullptr) {
            
           
            postorderTraversalLeaf(node->sol);
            postorderTraversalLeaf(node->sag);

            

            if (node->sol == nullptr && node->sag == nullptr) {
                
                b.push(node->key );
                

                 
            }else
            {
                d+= node->key;
            }
        }
       
    }

    AvlAgaci::AvlAgaci() : root(nullptr), size(0), ki(0),d(0) {}
    
    
    AvlAgaci::~AvlAgaci()
    {
        delete root;
        //delete e;
    }

    void AvlAgaci::insert(int key) {
        root = insert(root, key);
    }
    
    void AvlAgaci::inOrder() {
        std::cout << "n-order traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
    void AvlAgaci::postorderTraversal() const {
        postorderTraversal(root);
        std::cout << std::endl;
    }

    void AvlAgaci::postorderLeafTraversalLeaf()  {//void7
        
        
        postorderTraversalLeaf(root);

    }