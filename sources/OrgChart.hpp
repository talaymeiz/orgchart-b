#include <string>
#include <iostream>
#include "Node.hpp"
#include "iterator.hpp"

#ifndef ORGCHART_HEADER
#define ORGCHART_HEADER

using namespace std;

namespace ariel{

    class OrgChart{

        private:

            Node * root;

        public:

            OrgChart();

            OrgChart& add_root(const string &name);
            OrgChart& add_sub (const std::string &perent,const std::string &son);
            friend ostream& operator<<(ostream &out, const OrgChart&);

            Iterator begin();
            Iterator end();
            Iterator begin_level_order();
            Iterator end_level_order();
            Iterator begin_reverse_order();
            Iterator reverse_order();
            Iterator begin_preorder();
            Iterator end_preorder();

            bool perent_search(Node* root, const string& perent, const string& son);
            // void free_chart(Node *root);

            OrgChart &operator=(OrgChart const &other) = default;
            OrgChart &operator=(OrgChart &&other) = default;
            OrgChart(OrgChart&) = default;
            OrgChart(OrgChart&&) = default;

            ~OrgChart();
    };
}
#endif