#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "./graph.hpp"

namespace Graph
{
    bool WeightedGraphEdge::operator==(WeightedGraphEdge const &other) const
    {
        return to == other.to && weight == other.weight;
    }
    bool WeightedGraphEdge::operator!=(WeightedGraphEdge const &other) const
    {
        return !(*this == other);
    }

    bool WeightedGraph::operator==(WeightedGraph const &other) const
    {
        return adjacency_list == other.adjacency_list;
    }

    bool WeightedGraph::operator!=(WeightedGraph const &other) const
    {
        return !(*this == other);
    }
}

void Graph::WeightedGraph::add_vertex(int id)
{
    if (adjacency_list.find(id) == adjacency_list.end())
    {
        adjacency_list[id] = {};
    }
}

void Graph::WeightedGraph::add_directed_edge(int from, int to, float weight)
{
    add_vertex(from);
    add_vertex(to);

    adjacency_list[from].push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int from, int to, float weight)
{
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(const std::__1::vector<std::__1::vector<float>> &adjacency_matrix)
{
    Graph::WeightedGraph graph;

    for (size_t i = 0; i < adjacency_matrix.size(); i++)
    {
        graph.add_vertex(i);
        for (size_t j = 0; j < adjacency_matrix[i].size(); j++)
        {
            if (adjacency_matrix[i][j] != 0)
            {
                graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
            }
        }
    }

    return graph;
}

void Graph::WeightedGraph::print_DFS(int start) const
{
    std::stack<int> stack;
    std::vector<bool> visited(adjacency_list.size(), false);

    stack.push(start);
    visited[start] = true;

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();

        std::cout << current << " ";

        for (auto const &edge : adjacency_list.at(current))
        {
            if (!visited[edge.to])
            {
                stack.push(edge.to);
                visited[edge.to] = true;
            }
        }
    }

    std::cout << std::endl;
}

void Graph::WeightedGraph::print_BFS(int start) const
{
    std::queue<int> queue;
    std::vector<bool> visited(adjacency_list.size(), false);

    queue.push(start);
    visited[start] = true;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        std::cout << current << " ";

        for (auto const &edge : adjacency_list.at(current))
        {
            if (!visited[edge.to])
            {
                queue.push(edge.to);
                visited[edge.to] = true;
            }
        }
    }
    std::cout << std::endl;
}