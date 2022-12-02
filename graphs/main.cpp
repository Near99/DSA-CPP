#include "adjacency_list.h"
#include "adjacency_matrix.h"

void cb(int value) {
    // callback
    // std::cout << value << std::endl;
}

void matrix() {
    gam::Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 3);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 4);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(7, 6);
    g.addEdge(7, 5);
    // g.print();
    for (int i = 0; i < 8; i++) {
        g.bfs(i);
    }
}

void list() {
    gal::Graph g(true);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 0);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 6);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(7, 6);
    auto i = g.dfs(2);
    for (auto j : i) {
        std::cout << j << ' ';
    }
    std::cout << std::endl;
    auto parent = g.bfs(2, cb);
    g.shortest_path(2, 7, parent);
}

int main() {
    // matrix();
    list();
    return 0;
}
