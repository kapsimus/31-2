#include <iostream>
#include <memory>
#include "MatrixGraph.h"
#include "ListGraph.h"

MatrixGraph::MatrixGraph() {
    adjacencyMatrix = std::make_shared<std::vector<std::vector<int>>>();
}

MatrixGraph::~MatrixGraph() {
    adjacencyMatrix.reset();
}

MatrixGraph::MatrixGraph(const std::vector<std::vector<int>> &_adjacencyMatrix) {
    if (!_adjacencyMatrix.empty()) {
        adjacencyMatrix = std::make_shared<std::vector<std::vector<int>>>(_adjacencyMatrix);
    }
}

MatrixGraph::MatrixGraph(const std::vector<std::unordered_set<int>> &_adjacencyList) {
    if (!_adjacencyList.empty()) {
        adjacencyMatrix = std::make_shared<std::vector<std::vector<int>>>();
        int size = _adjacencyList.size();
        for (int i = 0; i < size; i++) {
            std::vector<int> node(size);
            adjacencyMatrix->push_back(node);
            for (int j = 0; j < size; j++) {
                if (_adjacencyList[i].contains(j)) {
                    (*adjacencyMatrix)[i][j] = 1;
                } else {
                    (*adjacencyMatrix)[i][j] = 0;
                }
            }
        }
    }
}

MatrixGraph::MatrixGraph(const MatrixGraph &obj) {
    adjacencyMatrix = obj.adjacencyMatrix;
}

MatrixGraph::MatrixGraph(const ListGraph &obj) {
    adjacencyMatrix = std::make_shared<std::vector<std::vector<int>>>();
    int size = obj.GetList()->size();
    for (int i = 0; i < size; i++) {
        std::vector<int> node(size);
        adjacencyMatrix->push_back(node);
        for (int j = 0; j < size; j++) {
            if ((*obj.GetList())[i].contains(j)) {
                (*adjacencyMatrix)[i][j] = 1;
            } else {
                (*adjacencyMatrix)[i][j] = 0;
            }
        }
    }
}

MatrixGraph &MatrixGraph::operator=(const MatrixGraph &obj) {
    if (this == &obj) {
        return *this;
    }
    if (adjacencyMatrix != nullptr) {
        adjacencyMatrix.reset();
    }
    adjacencyMatrix = obj.adjacencyMatrix;
}

MatrixGraph &MatrixGraph::operator=(const ListGraph &obj) {
    if (adjacencyMatrix != nullptr) {
        adjacencyMatrix.reset();
    }
    adjacencyMatrix = MatrixGraph(obj).GetMatrix();
}

std::shared_ptr<std::vector<std::vector<int>>> MatrixGraph::GetMatrix() const {
    return adjacencyMatrix;
}

void MatrixGraph::AddEdge(int from, int to) {
    if (adjacencyMatrix->size() > from && adjacencyMatrix->size() > to) {
        (*adjacencyMatrix)[from][to] = 1;
    } else {
        std::cout << "There is no such vertex" << std::endl;
    }
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (adjacencyMatrix->size() > vertex) {
        vertices.clear();
        for (int i = 0; i < (*adjacencyMatrix)[vertex].size(); i++) {
            if ((*adjacencyMatrix)[vertex][i] == 1)
            vertices.push_back(i);
        }
    } else {
        std::cout << "There is no such vertex" << std::endl;
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (adjacencyMatrix->size() > vertex) {
        vertices.clear();
        for (int i = 0; i < adjacencyMatrix->size(); i++) {
            if ((*adjacencyMatrix)[i][vertex] == 1)
                vertices.push_back(i);
        }
    } else {
        std::cout << "There is no such vertex" << std::endl;
    }
}

int MatrixGraph::VerticesCount() const {
    if (adjacencyMatrix->empty()) {
        return 0;
    } else {
        return adjacencyMatrix->size();
    }
}

void MatrixGraph::PrintAdjacencyMatrix() const {
    if (!adjacencyMatrix->empty()) {
        for (int i = 0; i < adjacencyMatrix->size(); i++) {
            for (int j = 0; j < adjacencyMatrix->size(); j++) {
                std::cout << (*adjacencyMatrix)[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
}