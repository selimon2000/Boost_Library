#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/metric_tsp_approx.hpp>

int main() {
    typedef boost::adjacency_list<boost::vecS,
                                  boost::vecS,
                                  boost::undirectedS,
                                  boost::no_property,
                                  boost::property<boost::edge_weight_t,
                                                  int>>
        Graph;
    typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

    // Create a graph
    Graph g(4);
    enum { A, B, C, D };
    const int num_vertices = 4;
    const char* name = "ABCD";
    int weights[num_vertices][num_vertices] = {{0, 1000, 15, 20},
                                               {10, 0, 35, 25},
                                               {15, 35, 0, 30},
                                               {20, 25, 30, 0}};

    // Add edges with weights
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = i + 1; j < num_vertices; ++j) {
            auto edge = boost::add_edge(i, j, g).first;
            boost::put(boost::edge_weight, g, edge, weights[i][j]);
        }
    }

    // Solve TSP
    std::vector<Vertex> tour;
    boost::metric_tsp_approx_tour(g, std::back_inserter(tour));

    // Output tour
    std::cout << "Approximate TSP Tour: ";
    for (auto v : tour) {
        std::cout << name[v] << " ";
    }
    std::cout << std::endl;

    return 0;
}