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

    MyGraphType G;
    
    boost::add_vertex({"Harry", 14}, G);
    boost::add_vertex({"Draco", 15}, G);
    boost::add_vertex({"Hagrid", 80}, G);

    add_edge(1, 2, 1.1, G);
    add_edge(1, 3, 2.2, G);
    add_edge(3, 2, 3.3, G);

    boost::property_map<MyGraphType, boost::edge_weight_t>::type weightmap = boost::get(boost::edge_weight, G);

    boost::graph_traits<MyGraphType>::edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = boost::edges(G); ei != ei_end; ++ei) {
        std::cout << "Edge (" << boost::source(*ei, G) << ", " << boost::target(*ei, G) << ") ";
        std::cout << "Weight: " << weightmap[*ei] << std::endl;
    }
} 