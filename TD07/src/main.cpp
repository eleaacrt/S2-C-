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

    if (graph == graph_matrix)
    {
        std::cout << "les graphes sont égaux" << std::endl;
    }
    else
    {
        std::cout << "les graphes ne sont pas égaux" << std::endl;
    }

    graph.print_DFS(0);
    graph.print_BFS(0);

    // test du dijkstra
    Graph::WeightedGraph dijkstra_graph{};
    dijkstra_graph.add_vertex(0);
    dijkstra_graph.add_vertex(1);
    dijkstra_graph.add_vertex(2);
    dijkstra_graph.add_vertex(3);
    dijkstra_graph.add_vertex(4);
    dijkstra_graph.add_vertex(5);

    // A
    dijkstra_graph.add_directed_edge(0, 1, 1);
    dijkstra_graph.add_directed_edge(0, 2, 5);
    dijkstra_graph.add_directed_edge(0, 3, 2);

    // B
    dijkstra_graph.add_directed_edge(1, 2, 4);
    dijkstra_graph.add_directed_edge(1, 3, 5);

    // C
    dijkstra_graph.add_directed_edge(2, 4, 3);
    dijkstra_graph.add_directed_edge(2, 5, 3);

    // D
    dijkstra_graph.add_directed_edge(3, 2, 2);
    dijkstra_graph.add_directed_edge(3, 4, 5);

    // E
    dijkstra_graph.add_directed_edge(4, 5, 3);

    display_list_graph(dijkstra_graph);

    std::unordered_map<int, std::pair<float, int>> shortest_path{Graph::dijkstra(dijkstra_graph, 0, 5)};
    for (auto const &[vertex, pair] : shortest_path)
    {
        std::cout << "distance de 0 à " << vertex << " : " << pair.first << " via " << pair.second << std::endl;
    }

    return 0;
}