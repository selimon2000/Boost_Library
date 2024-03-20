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
    typedef boost::adjacency_list<  boost::vecS,
                                    boost::vecS,
                                    boost::directedS,
                                    VertexData,
                                    EdgeData
                                 >MyGraphType;

    // when instantiating without args, don't make the mistake of writing
    // MyGraphType G();
    // you'll get cryptic/misleading errors if you do.
    MyGraphType G; 

    VertexData vd = {"my name", 42};
    add_vertex(vd, G);

    vd = {"my second name", 43};
    int v1 = add_vertex(G);
    G[v1] = vd;

    int v2 = add_vertex({"my last name", 44}, G);

    // don't forget the .first
    auto e = add_edge(v1, v2, {"the edge", 77.3}, G).first;

    std::cout << "name getter0 " << get(&VertexData::first_name, G)[0] << std::endl;
    std::cout << "name getter1 " << get(&VertexData::first_name, G)[1] << std::endl;

    std::cout << "dist getter " << get(&EdgeData::dist, G)[e] << std::endl;
}