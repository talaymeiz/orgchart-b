#include "iterator.hpp"
#include "Node.hpp"
#include "OrgChart.hpp"
#include <queue>

using namespace std;

using namespace ariel;

    Iterator:: Iterator(int flag, Node *mode){
 
        if (mode != nullptr) {
            switch (flag) {
                case 0:  
                    LO(mode);
                    break;
                case 1:
                    RO(mode);
                    break;
                case 2:
                    PO(mode);
                    break;
            }
            this->current = order_tree.at(0);
            order_tree.erase(order_tree.begin());
        } else {
            this->current = nullptr;
        }
                
    }

    void Iterator::LO(Node* root){
        
        vector<Node*> tree;
        tree.push_back(root);
        while(!tree.empty()){ 
            Node* curret =  tree[0];
            this->order_tree.push_back(curret); 
            for(unsigned long i = 0; i < (*curret).get_children().size(); i++){
                tree.push_back((*curret).get_children().at(i));
            }
            tree.erase(tree.begin());
        }  
    }
    
    void Iterator::RO(Node* root){
        
        vector<Node*> tree;
        tree.push_back(root);
        int vec_sive = tree.size();  
        for(unsigned int i= 0; i<vec_sive; i++){
            Node* current =  tree[i];
            for(int  j = (int)(*current).get_children().size()-1; j >= 0; j--) {
                tree.push_back((*current).get_children().at((unsigned)j));
            }
            vec_sive = tree.size();   
        } 
        for(int i = (int)tree.size()-1; i >= 0; i--) {
            order_tree.push_back(tree.at((unsigned)i));
        }
    }
    
    void Iterator::PO(Node* root){
        
        this->order_tree.push_back(root);
        int vec_sive = (*root).get_children().size(); //unsigned
        for(unsigned int i=0; i< vec_sive; i++) {
            Node* current = (*root).get_children().at(i);
            PO(current);
        }
    }

    Iterator Iterator::operator++(int){
        
        Iterator node = *this;
        return node;
    }
    Iterator& Iterator::operator++(){
        if (order_tree.empty()) {
            this->current = nullptr;
        }
        else {
            this->current = order_tree.at(0);
            order_tree.erase(order_tree.begin());
        }
        return *this;                
    }      
    const string* Iterator::operator->(){

        return &current->name;;
    }

    bool Iterator::operator==(const Iterator& iterator){
        
        return this->current == iterator.current;
    }
    bool Iterator::operator!=(const Iterator& iterator){

        return this->current != iterator.current;
    }
    string Iterator::operator*() {
        return (*this->current).get_name(); 
    }

    // Iterator:: Iterator(){
   //     
    // }
 //
    // void Iterator:: fix_next_LO(){
//
    //     queue<Node&> q;
    //     q.push(this->root);
    //     Node& curent= this->root;
    //     while (curent){
    //         vector<Node *> vec= curent->children;
    //         for (auto i = vec.begin(); i != vec.end(); ++i){
    //             q.push(this->*i);  
    //         } 
    //         if (q.empty()){
    //             curent->next= nullptr; 
    //             curent= nullptr; 
    //         }
    //         else{
    //             Node& next= q.pop(); 
    //             curent->next= next; 
    //             curent= next;
    //         }
    //     }
    // }
    // // void Iterator:: fix_next_RO();
    // // void Iterator:: fix_next_PO(){    
    // //     queue<Node&> q;
    // //     q.push(this->root);
    // //     Node& curent= nullptr;
    // //     while (curent != this->root)
    // //     {      
    // //     }
    // // }
    // // void Iterator:: recurs_PO(){
    // // }
    // Node& Iterator:: operator++(){
    //     Node* n= this->root;
    //     this->root= this->root.next;
    //     return n;
    // }
    // Node& Iterator:: operator++(int){
    //     this->root= this->root.next;
    //     return this->root;
    // }
    // bool Iterator:: operator==(const Node &node) const{
    //     if(this->root.name == node.name){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    // bool Iterator:: operator!=(const Node &node) const{
    //     if(this->root.name == node.name){
    //         return false;
    //     }
    //     else{
    //         return true;
    //     }
    // }
    
    // Iterator::~Iterator(){}