#ifndef __GRAPH_ADJACENCY_LIST__
#define __GRAPH_ADJACENCY_LIST__

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

namespace gal {

class EdgeNode {
   public:
    EdgeNode(int target, EdgeNode* curr_edges)
        : y(target), weight(0), next(curr_edges) {}
    int y;
    int weight;
    EdgeNode* next;
};

class Graph {
   public:
    Graph(bool d)
        : nedges_(0),
          nvertices_(0),
          directed_(d),
          degree_(max, 0),
          edges_(max, nullptr) {}

    void addEdge(int source, int target) {
        auto* edge_node =
            new EdgeNode(target, edges_[source]); /* insert at head of list */
        edges_[source] = edge_node;
        degree_[source]++;
        nedges_++;
    }

    void print() {
        for (auto edge : edges_) {
            if (edge) {
                auto temp_head = edge;
                while (temp_head) {
                    std::cout << temp_head->y << std::endl;
                    temp_head = temp_head->next;
                }
            }
        }
    }

   private:
    const int max = 10;
    int nedges_;
    int nvertices_;
    bool directed_;
    std::vector<int> degree_;
    std::vector<EdgeNode*> edges_;
};

}  // namespace gal
#endif