// No Property Graph

#include <iostream>
#include <boost/graph/adjacency_list.hpp>


struct VertexData {
    std::string first_name;
    int num;
};

int main() {
    typedef boost::adjacency_list<boost::vecS,
                                  boost::vecS,
                                  boost::undirectedS,
                                  VertexData,
                                  boost::property<boost::edge_weight_t, double>
                                  > MyGraphType;

    MyGraphType G(5);
    G[0].first_name = "Jeremy";
    G[0].num = 313;

    // add_edge returns a pair, where first element is a descriptor for added edge, and
    // second is a bool to indicate whether edge was successfully added
    auto e = add_edge(1,2,G).first;

    // the weight can be assigned using a weight map.
    boost::property_map<MyGraphType, boost::edge_weight_t>::type weightmap = get(boost::edge_weight, G);
    weightmap[e] = 10.1;

    std::cout << "vertex first name parameter: " << G[0].first_name << std::endl;
    std::cout << "vertex num parameter:" << G[0].num << std::endl << std::endl;

    std::cout << "edge-weight " << weightmap[e] << std::endl;  
    put(weightmap, e, 20);
    std::cout << "new edge-weight " << weightmap[e] << std::endl;
}