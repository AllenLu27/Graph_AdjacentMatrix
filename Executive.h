#ifndef EXECUTIVE_H
#define EXECTUVIE_H
#include <fstream>
#include <string>
#include "Graph.h"

  class Executive
{
  Graph* m_graph;
  public:
    Executive(std::string filename);
    ~Executive();
};

  #endif
