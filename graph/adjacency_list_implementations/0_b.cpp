#include <iostream>
#include <boost/graph/adjacency_list.hpp>

int main()
{
    typedef boost::adjacency_list<boost::vecS,
                                  boost::vecS,
                                  boost::undirectedS,
                                  boost::no_property,
                                  boost::property<boost::edge_weight_t, double>>
        MyGraphType;

    MyGraphType G;
    auto v1 = add_vertex(G);
    auto v2 = add_vertex(G);
    auto v3 = add_vertex(G);
    add_edge(v1, v2, 5.0, G); // Adding edge with weight 5.0
    add_edge(v2, v3, 3.13, G);

    std::cout << "Number of vertices: " << num_vertices(G) << std::endl;
    std::cout << "Number of edges: " << num_edges(G) << std::endl;

    // Print out the vertices
    std::cout << "Vertices: ";
    for (auto vd : boost::make_iterator_range(vertices(G)))
        std::cout << vd << " ";
    std::cout << std::endl;

    // Print out the edges with weights
    std::cout << "Edges: " << std::endl;
    for (auto ed : boost::make_iterator_range(edges(G)))
        std::cout << "\t" << source(ed, G) << "-" << target(ed, G) << " (weight: " << get(boost::edge_weight, G, ed) << ") " << std::endl;
    
    std::cout << std::endl;
}