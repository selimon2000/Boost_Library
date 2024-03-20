#include <iostream>
#include <boost/graph/adjacency_list.hpp>


struct EdgeData
{
  std::string edge_name;
  double dist;
};


int main() {
    typedef boost::adjacency_list<boost::vecS,
                                  boost::vecS,
                                  boost::undirectedS,
                                  boost::property<boost::vertex_distance_t, int, boost::property<boost::vertex_distance2_t, int>>,
                                  boost::property<boost::edge_weight_t, double, EdgeData>
                                  > MyGraphType;

    MyGraphType G(5);

    boost::property_map<MyGraphType, boost::vertex_distance_t>::type distance_map = get(boost::vertex_distance, G);
    boost::property_map<MyGraphType, boost::vertex_distance2_t>::type distance_map2 = get(boost::vertex_distance2, G);


    auto v = add_vertex(G);
    distance_map[v] = 10;
    distance_map2[v] = 20;

    std::cout << "distance " << get(boost::vertex_distance, G)[v] << std::endl;
    std::cout << "distance2 " << get(boost::vertex_distance2, G)[v] << std::endl; 
}