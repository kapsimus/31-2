#pragma once
#include <memory>
#include <vector>
#include <unordered_set>
#include "IGraph.h"

class ListGraph;

class MatrixGraph: IGraph {
private:
    std::shared_ptr<std::vector<std::vector<int>>> adjacencyMatrix;
public:
    explicit MatrixGraph();
    ~MatrixGraph() override;
    explicit MatrixGraph(const std::vector<std::vector<int>>& _adjacencyMatrix);
    explicit MatrixGraph(const std::vector<std::unordered_set<int>> &_adjacencyList);
    MatrixGraph(const MatrixGraph &obj);
    explicit MatrixGraph(const ListGraph &obj);
    MatrixGraph& operator = (const MatrixGraph& obj);
    MatrixGraph& operator = (const ListGraph& obj);
    [[nodiscard]] std::shared_ptr<std::vector<std::vector<int>>> GetMatrix() const;
    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    void PrintAdjacencyMatrix() const;
};