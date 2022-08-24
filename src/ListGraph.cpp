#include <iostream>
#include "ListGraph.h"

ListGraph::ListGraph(const std::vector<std::unordered_set<int>> &_adjacencyList) {
    if (!_adjacencyList.empty()) {
        adjacencyList = std::make_shared<std::vector<std::unordered_set<int>>>(_adjacencyList);
    }
}

void ListGraph::AddEdge(int from, int to) {
    if (adjacencyList->size() > from && adjacencyList->size() > to) {
        (*adjacencyList)[from].insert(to);
    } else {
        std::cout << "There is no such vertex" << std::endl;
    }
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (adjacencyList->size() > vertex) {
        vertices.clear();
        for (int num: (*adjacencyList)[vertex]) {
            vertices.push_back(num);
        }
    } else {
        std::cout << "There is no such vertex" << std::endl;
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (adjacencyList->size() > vertex) {
        vertices.clear();
        for (int i = 0; i < adjacencyList->size(); i++) {
            if ((*adjacencyList)[i].contains(vertex)) {
                vertices.push_back(i);
            }
        }
    } else {
        std::cout << "There is no such vertex" << std::endl;
    }
}

int ListGraph::VerticesCount() const {
    if (adjacencyList->empty()) {
        return 0;
    } else {
        return adjacencyList->size();
    }
}