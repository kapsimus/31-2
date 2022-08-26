#pragma once
#include <memory>
#include <vector>
#include <unordered_set>
#include "IGraph.h"

class MatrixGraph;

class ListGraph: IGraph {
private:
    std::shared_ptr<std::vector<std::unordered_set<int>>> adjacencyList;
public:
    explicit ListGraph();
    ~ListGraph() override;
    explicit ListGraph(const std::vector<std::unordered_set<int>>& _adjacencyList);
    explicit ListGraph(const std::vector<std::vector<int>>& _adjacencyMatrix);
    ListGraph(const ListGraph &obj);
    explicit ListGraph(const MatrixGraph &obj);
    ListGraph& operator = (const ListGraph& obj);
    ListGraph& operator = (const MatrixGraph& obj);
    [[nodiscard]] std::shared_ptr<std::vector<std::unordered_set<int>>> GetList() const;
    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    void PrintAdjacencyList() const;
};