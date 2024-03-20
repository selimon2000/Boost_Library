#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

using boost::property_tree::ptree;


int main() {
    ptree pt;
    read_xml("child_data.xml", pt);

    BOOST_FOREACH(ptree::value_type& child, pt.get_child("local_info.player_info")) {
        std::cout << "Node name: " << child.first << std::endl;

        std::cout << "Pass value: " << child.second.get<std::string>("<xmlattr>.pass") << std::endl;
        std::cout << "isSave value: " << child.second.get<bool>("<xmlattr>.isSave") << std::endl;
        std::cout << "isLastLogin value: " << child.second.get<bool>("<xmlattr>.isLastLogin") << std::endl;
        std::cout << "account value: " << child.second.get<int>("<xmlattr>.account") << std::endl;

        std::cout << "data: " << child.second.data() << std::endl << std::endl << std::endl;
    }
}