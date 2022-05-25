#include <string>
#include <iostream>
#include "Node.hpp"

#ifndef ITERATOR_HEADER
#define ITERATOR_HEADER

using namespace std;

namespace ariel{

    // const int LEVEL_ORDER = 0;
    // const int REVERSE_ORDER = 1;
    // const int PREORDER = 2;

    class Iterator{

        private:

            Node* current;
            vector<Node*> order_tree;

        public:
            
            Iterator(int flag, Node *mode = nullptr);

            void LO(Node* root);
            void RO(Node* root);
            void PO(Node* root);

            bool operator!=(const Iterator& iterator);
            bool operator==(const Iterator& iterator);
            string operator*() ;
            Iterator operator++(int);
            Iterator& operator++();       
            const string* operator->();

            // Iterator(Node &root, int flag);
            // Node& operator++();
            // Node& operator++(int);
            // bool operator==(const Node &node) const;
            // bool operator!=(const Node &node) const;
            // void fix_next_LO();
            // void fix_next_RO();
            // void fix_next_PO();
            // ~Iterator();
    };
}

#endif