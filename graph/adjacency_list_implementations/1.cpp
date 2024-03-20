#include <iostream>
#include <boost/graph/adjacency_list.hpp>


struct VertexData
{
  std::string first_name;
  int num;
};

struct EdgeData
{
  std::string edge_name;
  double dist;
};


int main() {
    typedef boost::adjacency_list<boost::vecS, boost::vecS,
                                boost::directedS,
                                VertexData,
                                boost::property<boost::edge_weight_t, double, EdgeData>
                                > MyGraphType;
    MyGraphType G(5);
    G[0].first_name = "Jeremy";

    // first is the edge. second is a bool telling you whether this is a new edge
    // or an existing one.
    auto e = add_edge(1,2,G).first;
    G[e].edge_name = "the edge";

    boost::property_map<MyGraphType, boost::edge_weight_t>::type weightmap =
    get(boost::edge_weight, G);
    weightmap[e] = 10.1;

    std::cout << "vertex name " << G[0].first_name << std::endl;
    std::cout << "name getter " << get(&VertexData::first_name, G)[0] << std::endl;

    std::cout << "saved edge name " << G[e].edge_name << std::endl;
    std::cout << "edge name getter " << get(&EdgeData::edge_name, G)[e] << std::endl;
    // add example using get to get the property value
    std::cout << "saved weight " << weightmap[e] << std::endl;
} 