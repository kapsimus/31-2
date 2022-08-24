#pragma once
#include <memory>
#include <vector>
#include <unordered_set>
#include "IGraph.h"

class ListGraph: IGraph {
private:
    std::shared_ptr<std::vector<std::unordered_set<int>>> adjacencyList;
public:
    ListGraph(const std::vector<std::unordered_set<int>>& _adjacencyList);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};