#include <iostream>
#include <string>
#include <vector>
#include "graph.hpp"

void display_list_graph(Graph::WeightedGraph graph)
{
    for (auto const &[vertex, edges] : graph.adjacency_list)
    {
        std::cout << vertex << " -> ";
        for (auto const &edge : edges)
        {
            std::cout << edge.to << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // test matrice d'adjacence
    std::cout << "création du graphe à partir d'une matrice" << std::endl;
    const std::__1::vector<std::__1::vector<float>> &adjacency_matrix{
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 0}};
    Graph::WeightedGraph graph_matrix{Graph::build_from_adjacency_matrix(adjacency_matrix)};
    display_list_graph(graph_matrix);

    // test en ajoutant manuellement les sommets
    std::cout << "création du graphe en ajoutant manuellement les sommets" << std::endl;
    Graph::WeightedGraph graph{};
    graph.add_vertex(0);
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);

    graph.add_undirected_edge(0, 1);
    graph.add_directed_edge(0, 2);
    graph.add_undirected_edge(1, 2);
    graph.add_undirected_edge(1, 3);
    graph.add_directed_edge(3, 2);

    display_list_graph(graph);

    if (graph == graph_matrix){
        std::cout << "les graphes sont égaux" << std::endl;
    } else {
        std::cout << "les graphes ne sont pas égaux" << std::endl;
    }
    
    return 0;
}