#pragma
#include <memory>
#include <vector>
#include <unordered_set>
#include "IGraph.h"

class MatrixGraph: IGraph {
private:
    std::shared_ptr<std::vector<std::vector<int>>> adjacencyMatrix;
public:
    MatrixGraph(const std::vector<std::vector<int>>& _adjacencyMatrix);
    MatrixGraph(const std::vector<std::unordered_set<int>> &_adjacencyList);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};