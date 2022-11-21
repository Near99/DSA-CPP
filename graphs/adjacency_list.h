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

    void bfs(int source) {
        if (source < 0 || source >= max) {
            std::cout << "Out of boundary!" << std::endl;
        }
        std::unordered_map<int, bool> map;
        std::queue<int> queue;
        map.insert({source, true}), queue.push(source);
        while (!queue.empty()) {
            std::cout << queue.front() << ' ';
            if (edges_[queue.front()]) {
                auto v = edges_[queue.front()];
                while (v) {
                    if (map.find(v->y) == map.end()) {
                        queue.push(v->y);
                        map.insert({v->y, true});
                    }
                    v = v->next;
                }
            }
            queue.pop();
        }
        std::cout << std::endl;
    }

    void print() {
        for (int i = 0; i < edges_.size(); i++) {
            if (edges_[i]) {
                std::cout << "Source: " << i << std::endl;
                auto temp_head = edges_[i];
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
    std::vector<int> degree_;  // outdegree of each vertex
    std::vector<EdgeNode*> edges_;
};

}  // namespace gal
#endif
