#ifndef NODE_SET_H
#define NODE_SET_H



  class Node_set
{
  int value;
  int rank;
  Node_set* parent;
public:
  Node_set(int t_value);
  void setValue(int t_value);
  void setRank(int t_rank);
  void setParent(Node_set* new_parent);
  int getValue();
  int getRank();
  Node_set* getParent();
};

  #endif
