// No Property Graph

#include <iostream>
#include <boost/graph/adjacency_list.hpp>


int main() {
    typedef boost::adjacency_list<  boost::vecS,
                                    boost::vecS,
                                    boost::undirectedS,
                                    boost::no_property,
                                    boost::no_property
                                    > MyGraphType;

    MyGraphType G;
    auto v1 = add_vertex(G);
    auto v2 = add_vertex(G);
    auto e = add_edge(v1, v2, G);

    std::cout << "Number of vertices: " << num_vertices(G) << std::endl;
    std::cout << "Number of edges: " << num_edges(G) << std::endl;

    // Print out the vertices
    std::cout << "Vertices: ";
    for (auto vd : boost::make_iterator_range(vertices(G)))
        std::cout << vd << " ";
    std::cout << std::endl;

    // Print out the edges
    std::cout << "Edges: ";
    for (auto ed : boost::make_iterator_range(edges(G)))
        std::cout << source(ed, G) << "-" << target(ed, G) << " ";
    std::cout << std::endl;
} 