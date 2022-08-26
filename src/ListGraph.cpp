#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"

ListGraph::ListGraph() {
    adjacencyList = std::make_shared<std::vector<std::unordered_set<int>>>();
}

ListGraph::~ListGraph() {
    adjacencyList.reset();
}

ListGraph::ListGraph(const std::vector<std::unordered_set<int>> &_adjacencyList) {
    if (!_adjacencyList.empty()) {
        adjacencyList = std::make_shared<std::vector<std::unordered_set<int>>>(_adjacencyList);
    }
}

ListGraph::ListGraph(const std::vector<std::vector<int>> &_adjacencyMatrix) {
    if (!_adjacencyMatrix.empty()) {
        adjacencyList = std::make_shared<std::vector<std::unordered_set<int>>>();
        int size = _adjacencyMatrix.size();
        for (int i = 0; i < size; i++) {
            adjacencyList->push_back(std::unordered_set<int>());
            for (int j = 0; j < size; j++) {
                if (_adjacencyMatrix[i][j] != 0) {
                    (*adjacencyList)[i].insert(j);
                }
            }
        }
    }
}

ListGraph::ListGraph(const ListGraph &obj) {
    adjacencyList = obj.adjacencyList;
}

ListGraph::ListGraph(const MatrixGraph &obj) {
    adjacencyList = std::make_shared<std::vector<std::unordered_set<int>>>();
    int size = obj.GetMatrix()->size();
    for (int i = 0; i < size; i++) {
        adjacencyList->push_back(std::unordered_set<int>());
        for (int j = 0; j < size; j++) {
            if ((*obj.GetMatrix())[i][j] != 0) {
                (*adjacencyList)[i].insert(j);
            }
        }
    }
}

ListGraph &ListGraph::operator=(const ListGraph &obj) {
    if (this == &obj) {
        return *this;
    }
    if (adjacencyList != nullptr) {
        adjacencyList.reset();
    }
    adjacencyList = obj.adjacencyList;
}

ListGraph &ListGraph::operator=(const MatrixGraph &obj) {
    if (adjacencyList != nullptr) {
        adjacencyList.reset();
    }
    adjacencyList = ListGraph(obj).GetList();
}

std::shared_ptr<std::vector<std::unordered_set<int>>> ListGraph::GetList() const {
    return adjacencyList;
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

void ListGraph::PrintAdjacencyList() const {
    if (!adjacencyList->empty()) {
        for (int i = 0; i < adjacencyList->size(); i++) {
            std:: cout << i << "->" << "\t";
            for (int j = 0; j < adjacencyList->size(); j++) {
                if ((*adjacencyList)[i].contains(j)) {
                    std::cout << j << "\t";
                }
            }
            std::cout << std::endl;
        }
    }
}