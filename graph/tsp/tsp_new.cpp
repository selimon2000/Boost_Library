#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/metric_tsp_approx.hpp>

using Graph = boost::adjacency_list<boost::setS, boost::listS, boost::undirectedS,
                                    boost::property<boost::vertex_index_t, int>,
                                    boost::property<boost::edge_weight_t, double>,
                                    boost::no_property>;

using VertexDescriptor = Graph::vertex_descriptor;

int main() {
    std::vector points { std::pair
        { 4., 9. }, // these can be randomized
        { 2., 6. },
        { 4., 1. },
        { 1., 1. },
    };

    Graph graph;
    for (auto i = 0u; i < points.size(); ++i) {
        add_vertex(i, graph);
    }

    for (auto i = 0u; i < points.size(); ++i) {
        auto va = vertex(i, graph);

        // undirected, so only need traverse higher vertices for connections
        for (auto j = i+1; j < points.size(); ++j) {
            auto vb = vertex(j, graph);

            auto const [ax, ay] = points.at(i);
            auto const [bx, by] = points.at(j);
            auto const dx = bx - ax;
            auto const dy = by - ay;

            add_edge(va, vb, sqrt(dx*dx + dy*dy), graph); // weight is euclidean distance
        }
    }

    print_graph(graph);

    std::vector<VertexDescriptor> tsp_path(num_vertices(graph));  //VertexDescriptor is adjacency_list::vertex_descriptor
    metric_tsp_approx_tour(graph, back_inserter(tsp_path));

    auto idmap = get(boost::vertex_index, graph);
    for (auto vd : tsp_path) {
        if (vd != graph.null_vertex()) {
            auto [x,y] = points.at(idmap[vd]); 
            std::cout << " {" << x << "," << y << "}";
        }
    }
}