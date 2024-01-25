#include<iostream>
using namespace std;
class Node {
    public:
    Node* l_child;
    Node* r_child;
    int data;
    int height;
    Node() {
        this->l_child = NULL;
        this->r_child = NULL;
        this->data = 0;
        this->height = 0;
    }
    Node(int data) {
        this->data = data;
        this->height = 1;
        this->l_child = NULL;
        this->r_child = NULL;
    }
};

class AVL {
    public:
    Node* root;
    AVL() {
        this->root = NULL;
    }
    Node* r_insert_node(Node* , int);
    int height_of_node(Node*);
    int balanced_factor(Node*);
    Node* LLRotation(Node*);
    Node* RRRotation(Node*);
    Node* LRRotation(Node*);
    Node* RLRotation(Node*);
    Node* delete_node(Node*,int);
    void in_order(Node*);
};

void AVL::in_order(Node* root) {
    if(root == NULL) {
        return;
    }
    in_order(root->l_child);
    cout << root->data << " ";
    in_order(root->r_child);
}

Node* AVL::LLRotation(Node* p) {
    Node* pl = p->l_child;
    Node* plr = pl->r_child;

    pl->r_child = p;
    p->l_child = plr;

    p->height = height_of_node(p);
    pl->height = height_of_node(pl);


    if(p == root) {
        root = pl;
    }
    return pl;
}

Node* AVL::RRRotation(Node* p) {
    Node* pl = p->r_child;
    Node* plr = pl->l_child;

    pl->l_child = p;
    p->r_child = plr;

    p->height = height_of_node(p);
    pl->height = height_of_node(pl);

    if(p == root) {
        root = pl;
    }
    return pl;
}

Node* AVL::LRRotation(Node* p) {
    Node* pl = p->l_child;
    Node* plr = pl->r_child;

    p->l_child = plr->r_child;
    pl->r_child = plr->l_child;
    
    plr->r_child = p;
    plr->l_child = pl;

    p->height = height_of_node(p);
    pl->height = height_of_node(pl);
    plr->height = height_of_node(plr);

    if(root == p) {
        root = plr;
    }
    return plr;
}

Node* AVL::RLRotation(Node* p) {
    Node* pr = p->r_child;
    Node* prl = pr->l_child;

    p->r_child = prl->r_child;
    pr->l_child = prl->l_child;

    prl->r_child = pr;
    prl->l_child = p;

    p->height = height_of_node(p);
    pr->height = height_of_node(pr);
    prl->height = height_of_node(prl);

    if(root == p) {
        root = prl;
    }
    return prl;

}

int AVL::balanced_factor(Node* root) {
    int l_height;
    int r_height;
    l_height = root && root->l_child?root->l_child->height:0;
    r_height = root && root->r_child?root->r_child->height:0;
    return l_height-r_height;
}

int AVL:: height_of_node(Node* root) {
    int l_height;
    int r_height;
    l_height = root && root->l_child?root->l_child->height:0;
    r_height = root && root->r_child?root->r_child->height:0;
    return (max(l_height,r_height)+1);
}

Node* AVL:: r_insert_node(Node* root,int key) {
    if (root == NULL) {
        Node* new_node = new Node(key); 
        root = new_node;
        return root;
    }
    if(key < root->data) {
        root->l_child = r_insert_node(root->l_child,key);
    }
    if(key > root->data) {
        root->r_child = r_insert_node(root->r_child,key);
    }
    else if(key > root->data) {
        root->r_child = r_insert_node(root->r_child ,key);
    }  
    root->height = height_of_node(root);
    if(balanced_factor(root) == 2 && balanced_factor(root->l_child) == 1) {
        return LLRotation(root);
    }
    if(balanced_factor(root) == -2 && balanced_factor(root->r_child) == -1) {
        return RRRotation(root);
    } 
    if(balanced_factor(root) == 2 && balanced_factor(root->l_child) == -1)  {
        return LRRotation(root);
    }
    if(balanced_factor (root) == -2 && balanced_factor(root->r_child) == 1) {
        return RLRotation(root);
    }
    return root; 
}

Node* inorder_successor(Node* root) {
    Node* temp = root;
    while(temp && temp->l_child != NULL) {
        temp = temp->l_child;
    }
    return temp;
}

Node* AVL::delete_node(Node* root,int key) {
    if((key) > root->data) {
        root->r_child = delete_node(root->r_child,key);
    }
    if((key) < root->data) {
        root->l_child = delete_node(root->l_child,key);
    }
    if(key == root->data) {
        if(root->l_child == NULL) {
            Node* temp = root->r_child;
            delete root;
            return temp;
        }
        else if(root->r_child == NULL) {
            Node* temp = root->l_child;
            delete root;
            return temp;
        }
        Node* temp = inorder_successor(root->r_child);
        root->data = temp->data;
        root->r_child = delete_node(root->r_child,temp->data);
    }
    root->height = height_of_node(root);
    if(balanced_factor(root) > 1 && balanced_factor(root->l_child) >= 0) {
        return LLRotation(root);
    }
    if(balanced_factor(root) > 1 && balanced_factor(root->r_child) < 0) {
        return RRRotation(root);
    }
    if(balanced_factor(root) < -1 && balanced_factor(root->l_child) <= 0)  {
        return LRRotation(root);
    }
    if(balanced_factor (root) == -2 && balanced_factor(root->r_child) > 0) {
        return RLRotation(root);
    }
    return root; 
}

main() {
    AVL a;
    cout << "-----------Before Deletion-----------" << endl;
    a.root = a.r_insert_node(a.root,30);
    a.root = a.r_insert_node(a.root,20);
    a.root = a.r_insert_node(a.root,10);
    a.root = a.r_insert_node(a.root,5);
    a.in_order(a.root);
    cout << endl;
    cout << "-----------After Deletion-------------" << endl;
    a.root = a.delete_node(a.root,5);
    a.in_order(a.root);
}