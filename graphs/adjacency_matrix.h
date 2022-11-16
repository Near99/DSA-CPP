#ifndef __GRAPH_ADJACENCY_MATRICES__
#define __GRAPH_ADJACENCY_MATRICES__

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

namespace gam {

class Graph {
   public:
    Graph(int vs) {
        vertices = vs;
        edges = 0;
        adjacency_matrices_init_(vertices);
    }

    void addEdge(int source, int target) {
        if (source >= vertices || target >= vertices) {
            std::cout << "Out of boundary" << std::endl;
            return;
        }
        adjacency_matrices[source][target] = 1;
        edges++;
    }

    void deleteEdge(int source, int target) {
        if (source >= vertices || target >= vertices) {
            std::cout << "Out of boundary" << std::endl;
            return;
        }
        adjacency_matrices[source][target] = 0;
        edges--;
    }

    void bfs(int source) {
        std::queue<int> verticesToBeVisited;
        std::unordered_map<int, bool> visited;
        verticesToBeVisited.push(source);
        visited.insert({source, true});
        while (!verticesToBeVisited.empty()) {
            int v = verticesToBeVisited.front();
            verticesToBeVisited.pop();
            std::cout << v << std::endl;
            for (int i = 0; i < adjacency_matrices[v].size(); i++) {
                if (adjacency_matrices[v][i] == 1 &&
                    visited.find(i) == visited.end()) {
                    visited.insert({i, true});
                    verticesToBeVisited.push(i);
                }
            }
        }
    }

    void print() {
        std::cout << "Vertices: " << vertices << std::endl;
        std::cout << "Edges: " << edges << std::endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjacency_matrices[i][j];
            }
            std::cout << std::endl;
        }
    }

   private:
    int vertices;
    int edges;

    std::vector<std::vector<int>> adjacency_matrices;

    void adjacency_matrices_init_(int vertices) {
        std::vector<std::vector<int>> m(vertices,
                                        std::vector<int>(vertices, 0));
        adjacency_matrices = m;
    }
};

}  // namespace gam
#endif