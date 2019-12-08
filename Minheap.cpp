#include "Minheap.h"

  Minheap::Minheap(int size)
{
  m_min = new Edge[size];
  next_pos = 0;
  heap_size = size;
}

  Minheap::Minheap(int size, Edge root_item)
{
  m_min = new Edge[size];
  m_min[0] = root_item;
  next_pos = 1;
  heap_size = size;
}

  bool Minheap::insert(Edge m_edge)
{
  if(next_pos == heap_size)
{
  return(0);
}
  else
{
  m_min[next_pos] = m_edge;
  next_pos=next_pos+1;
  Heapify(next_pos-1);
  return(1);
 }
}

  int Minheap::parent_index(int child_index)
{
  int parent = (child_index-1)/3;
  return(parent);
}

  void Minheap::Heapify(int index)
{
  if(index > 0)
{
  int parent=parent_index(index);
  if(m_min[index].getDistance() < m_min[parent].getDistance())
{
  Edge temp = m_min[index];
  m_min[index] = m_min[parent];
  m_min[parent] = temp;
  Heapify(parent);
  }
 }
}

  void Minheap::Delete()
{
  m_min[0] = m_min[next_pos-1];
  next_pos=next_pos-1;
  down_heap(0);
}

void Minheap::down_heap(int index)
{
  int f_child = (3*index)+1;
  int s_child = (3*index)+2;
  int t_child = (3*index)+3;
  int smallest = index;
  if(f_child < next_pos && m_min[f_child].getDistance() < m_min[smallest].getDistance())
  {
    smallest = f_child;
  }
  if(s_child < next_pos && m_min[s_child].getDistance() < m_min[smallest].getDistance())
  {
    smallest = s_child;
  }
  if(t_child < next_pos && m_min[t_child].getDistance() < m_min[smallest].getDistance())
  {
    smallest = t_child;
  }
  if(smallest != index)
  {
    Edge temp = m_min[index];
    m_min[index] = m_min[smallest];
    m_min[smallest] = temp;
    down_heap(smallest);
  }
}

 bool Minheap::isEmpty()
{
  if(next_pos == 0)
  {
    return(1);
  }
  return(0);
}



 Edge Minheap::PQ_Lowest()
{
  return(m_min[0]);
}

// int Minheap::PQ_Highest()
// {
// //   int largest = m_min[next_pos-1];
// //   int next = next_pos-1;
// //   while(1)
// // {
// //   if(3*next <= next_pos)
// //   {
// //     break;
// //   }
// //   next--;
// //   if(m_min[next] > largest)
// //   {
// //     largest = m_min[next];
// //   }
// // }
// //   return(largest);
//   int largest_index = ((next_pos - 2)/3)+1;
//   int largest = m_min[largest_index];
//   while(1)
// {
//   largest_index++;
//   if(largest_index >= next_pos)
// {
//   break;
// }
//   if(m_min[largest_index] > largest)
// {
//   largest = m_min[largest_index];
// }
//  }
//   return(largest);
// }

// bool Minheap::isDuplicate(int item)
// {
//   for(int i = 0; i<next_pos; i++)
// {
//   if(m_min[i] == item)
//   {
//     return(1);
//   }
// }
//   return(0);
// }

//   void Minheap::Levelorder()
// {
//   std::cout<<m_min[0]<<'\n'<<'\n';
//   int sum = 3;
// for(int i=1; i<next_pos; i++)
// {
//   std::cout<<m_min[i]<<' ';
//   if(i == sum)
//   {
//     sum = sum*3;
//     std::cout<<'\n'<<'\n';
//   }
//  }
// }

  Minheap::~Minheap()
{
  delete[] m_min;
}
