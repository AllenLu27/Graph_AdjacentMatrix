#ifndef MINHEAP_H
#define MINHEAP_H
#include<iostream>
#include"Edge.h"


  class Minheap
{
  Edge* m_min;
  int next_pos;
  int heap_size;
  public:

      Minheap(int size);
      Minheap(int size, Edge root_item);
      void Heapify(int index);
      bool insert(Edge m_edge);
      void Delete();
      void down_heap(int index);
      bool isEmpty();
      //int PQ_Highest();
      Edge PQ_Lowest();
      //void Levelorder();
      //double Time_LowestPQ();
      int parent_index(int child_index);
      //bool isDuplicate(int item);
      ~Minheap();
  };

#endif
