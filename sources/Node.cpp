#include "iterator.hpp"
#include "Node.hpp"

using namespace std;

using namespace ariel;

    Node:: Node(std::string name){

        this->name= std::move(name);
        // this->is_root= false;
        vector<Node *> vec;
        this->children = vec;
        // this->next= nullptr;
        // this->perent= perent;

    }
    vector<Node*> Node:: get_children()const{

        return this->children;
    }
    void Node:: add_chaild(Node* node){
        
        this->children.push_back(node);
    }
    void Node:: set_name(string name){

        this->name= std::move(name);
    }
    std::string Node:: get_name()const{

        return this->name;
    }


    Node::~Node(){}