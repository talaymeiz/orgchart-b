#include "iterator.hpp"
#include "Node.hpp"
#include "OrgChart.hpp"

using namespace std;

namespace ariel{

    OrgChart:: OrgChart(){
        
        this->root=nullptr;
    }

    OrgChart& OrgChart::add_root(const string &name){
        
        if (name.empty()) {
            throw invalid_argument("ampty name");
        }

        if(this->root == nullptr) {
            this->root = new Node(name);
        }
        else {
            (*this->root).set_name(name);
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub (const std::string &perent,const std::string &son){
        
        if (this->root == nullptr) {
            throw invalid_argument("no root");
        }
        if(!perent_search(this->root ,perent,son)) {
            throw invalid_argument("perent isn't exist");
        }
        if (perent.empty() || son.empty()) {
            throw invalid_argument("ampty name");
        }
        return *this;
    }

    ostream& operator<<(ostream &out, const OrgChart& obj) {return cout<<"123";}

    Iterator OrgChart::begin() {

        if (this->root ==nullptr) {//chack
            throw invalid_argument("no root");
        }
        return Iterator{0, this->root};
    }
    Iterator OrgChart::end() {

        if (this->root ==nullptr) {//chack
            throw invalid_argument("no root");
        }
        return Iterator{0, nullptr};
    }
       
    Iterator OrgChart::begin_level_order(){
        
        if (this->root == nullptr) {
            throw invalid_argument("no root");
        }
        return Iterator{0, this->root}; 
    }
    Iterator OrgChart::end_level_order(){
        
        if (this->root == nullptr) {
            throw invalid_argument("no root");
        }
        return Iterator{0, nullptr}; 
    }
    Iterator OrgChart::begin_reverse_order(){
        
        if (this->root == nullptr) {
            throw invalid_argument("no root");
        }
        return Iterator{1,this->root}; 
    }
    Iterator OrgChart::reverse_order(){
        
        if (this->root == nullptr) {
            throw invalid_argument("no root");
        }
        return Iterator{1, nullptr}; 
    }
    Iterator OrgChart::begin_preorder(){
        
        if (this->root == nullptr) {
            throw invalid_argument("no root");
        }
        return Iterator{2,this->root}; 
    }
    Iterator OrgChart::end_preorder(){
        
        if (this->root == nullptr) {
            throw invalid_argument("no root");
        }
        return Iterator{2, nullptr}; 
    }
            
    bool OrgChart::perent_search(Node* root, const string& perent, const string& son) {
        
        if((*root).get_name()==perent){
            Node* son_new = new Node(son);
            (*root).add_chaild(son_new);
            return true;
        }
        for (size_t i = 0; i < (*root).get_children().size(); i++) { //size_t 
            if (perent_search( (*root).get_children().at(i), perent, son)) {
                return true;
            }
        }
        return false;
    }

    OrgChart::~OrgChart(){}
}