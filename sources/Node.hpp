#include <string>
#include <iostream>
#include <vector>

#ifndef NODE_HEADER
#define NODE_HEADER

using namespace std;

namespace ariel{

    class Node{

        
        public:
            
            vector <Node *> children;
            string name;

            Node(std::string name);
            vector<Node*> get_children()const;
            void add_chaild(Node* node);
            void set_name(string name);
            std::string get_name()const;

            friend ostream &operator<<(ostream &output, Node *current_node) {
                output << current_node->name;
                return output;
            }

            Node &operator=(Node const &other_node) = default;
            Node &operator=(Node &&other_node) = default;
            Node(Node&) = default;
            Node(Node&&) = default;

            ~Node();
    };
}
#endif