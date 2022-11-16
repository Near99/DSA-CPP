#ifndef __GRAPH_ADJACENCY_LIST__
#define __GRAPH_ADJACENCY_LIST__

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

namespace gal {

class EdgeNode {
    int y;
    int weight;
    EdgeNode* next;
};

class Graph {
   public:
   private:
    bool directed;
    int nedges;
    int nvertices;
    std::vector<int> degree;
    std::vector<EdgeNode*> edges;
};

}  // namespace gal
#endif