#ifndef GRAPH_H
#define GRAPH_H
#include "Queue.h"
#include "Minheap.h"
#include "Disjoint.h"
#include <iostream>

    class Graph
  {
    int** m_arr;
    int nov;
    int noe;
    Edge** e_arr;
  public:
    Graph(int** m_graph, int n, int count);
    void BFS();
    void DFS();
    void DFS_recursive(int current, bool* visited, bool* traversal);
    void Kruskal();
    void Prim();
    ~Graph();
  };

    #endif
