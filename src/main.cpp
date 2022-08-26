#include <iostream>
#include <string>
#include "MatrixGraph.h"
#include "ListGraph.h"

int main() {
    std::vector<std::unordered_set<int>> list = {{1, 2},
                                                 {2},
                                                 {0}};
    std::vector<std::vector<int>> matrix = {{0, 1, 1},
                                            {0, 0, 1},
                                            {1, 0, 0}};
    std::vector<std::unordered_set<int>> list2 = {{1},
                                                 {2},
                                                 {0}};
    std::vector<std::vector<int>> matrix2 = {{0, 1, 0},
                                            {0, 0, 1},
                                            {1, 0, 0}};

    MatrixGraph graph = *(new MatrixGraph(list));
    MatrixGraph graph2 = *(new MatrixGraph(matrix));
    ListGraph graph3 = *(new ListGraph(list));
    ListGraph graph4(graph);
    MatrixGraph graph5(graph4);
    ListGraph graph6(list2);
    MatrixGraph graph7;

    graph5 = graph6;
    graph7 = graph;

    std::cout << "1" << std::endl;
    graph.PrintAdjacencyMatrix();
    std::cout << "2" << std::endl;
    graph2.PrintAdjacencyMatrix();
    std::cout << "3" << std::endl;
    graph3.PrintAdjacencyList();
    std::cout << "4" << std::endl;
    graph4.PrintAdjacencyList();
    std::cout << "5" << std::endl;
    graph5.PrintAdjacencyMatrix();
    std::cout << "6" << std::endl;
    graph6.PrintAdjacencyList();
    std::cout << "7" << std::endl;
    graph7.PrintAdjacencyMatrix();
    return 0;
}
