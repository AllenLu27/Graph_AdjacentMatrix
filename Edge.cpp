#include "Edge.h"

  Edge::Edge()
{
  vertex_0 = 0;
  vertex_1 = 0;
  distance = 0;
}

  Edge::Edge(int v, int w, int d)
{
  vertex_0 = v;
  vertex_1 = w;
  distance = d;
}

  int Edge::getVertex0()
{
  return(vertex_0);
}

  int Edge::getVertex1()
{
  return(vertex_1);
}

  int Edge::getDistance()
{
  return(distance);
}

  bool Edge::operator==(Edge& temp)
{
  if(vertex_0 == temp.vertex_0 && vertex_1 == temp.vertex_1)
  {
    return(1);
  }
  else
  {
    return(0);
  }
}
