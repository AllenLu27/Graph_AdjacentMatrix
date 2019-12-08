#ifndef DISJOINT_H
#define DISJOINT_H
#include "Node_set.h"
//#include "LinkedList.h"
#include<iostream>

  class Disjoint
{
  Node_set** m_arr;
  int size;

public:
  Disjoint(int t_size);
  void Union(int value_0, int value_1);
  void PathCompression(int tobe_compress);
  Node_set* Find(int key);
  int Find_ex(int key, bool& flag);
  Node_set* Search_key(int key);
  void Start_expriment();
  ~Disjoint();
};

  #endif
