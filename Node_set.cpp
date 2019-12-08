#include "Node_set.h"

  Node_set::Node_set(int t_value)
{
  value = t_value;
  rank = 0;
  parent = this;
}

  void Node_set::setValue(int t_value)
{
  value = t_value;
}

  void Node_set::setRank(int t_rank)
{
  rank = t_rank;
}

  void Node_set::setParent(Node_set* new_parent)
{
  parent = new_parent;
}

  int Node_set::getValue()
{
  return(value);
}

  int Node_set::getRank()
{
  return(rank);
}

  Node_set* Node_set::getParent()
{
  return(parent);
}
