#ifndef EDGE_H
#define EDGE_H

  class Edge
{
  int vertex_0;
  int vertex_1;
  int distance;
public:
  Edge();
  Edge(int v, int w, int d);
  int getDistance();
  int getVertex0();
  int getVertex1();
  bool operator==(Edge& temp);
};

  #endif
