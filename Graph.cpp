#include "Graph.h"

  Graph::Graph(int** m_graph, int n, int count)
{
  m_arr = m_graph;
  nov = n;
  noe = count/2;
  int track = 0;
  e_arr = new Edge*[noe];
  for(int i=1; i<nov; i++)
  {
    for(int j=1; j<nov; j++)
    {
      if(m_arr[i][j] != -1 && i != j)
      {
        if(i > j)
        {
          }
        else
        {
          e_arr[track] = new Edge(i, j, m_arr[i][j]);
          track++;
         }
      }
    }
  }
  // for(int k=0; k<noe; k++)
  // {
  //   std::cout<<'('<<e_arr[k]->getVertex0()<<", "<<e_arr[k]->getVertex1()<<')'<<' ';
  // }
  // std::cout<<'\n';
}

  void Graph::BFS()
{
  int current = 0;
  int track = 0;
  Queue<int> m_queue;
  int* traversal = new int[nov];
  bool* visited = new bool[nov];
  bool* b_edges = new bool[noe];
  for(int i=1; i<nov; i++)
  {
    visited[i] = 0;
  }
  for(int j=0; j<noe; j++)
  {
    b_edges[j] = 1;
  }
  m_queue.enqueue(1);
  visited[1] = 1;
  traversal[1] = 1;
  track = 2;
  while(!m_queue.isEmpty())
  {
    current = m_queue.peekFront();
    for(int k=1; k<nov; k++)
    {
      if(visited[k] != 1 && m_arr[current][k] != -1)
      {
        m_queue.enqueue(k);
        visited[k] = 1;
        traversal[track] = k;
        track++;
      }
    }
    m_queue.dequeue();
  }
  for(int k=1; k<nov; k++)
  {
    visited[k] = 0;
  }
  visited[1] = 1;
  std::cout<<"Tree Edges: ";
  for(int i = 1; i<nov; i++)
  {
    for(int j = i+1; j<nov; j++)
    {
      if(visited[j] == 0 && m_arr[traversal[i]][j] != -1)
      {
        visited[j] = 1;
        for(int k = 0; k<noe; k++)
        {
          if(e_arr[k]->getVertex0() == i && e_arr[k]->getVertex1() == j)
          {
            b_edges[k] = 0;
          }
        }
        std::cout<<'('<<i<<", "<<j<<')'<<' ';
      }
    }
  }
  std::cout<<'\n';
  std::cout<<"Cross Edges: ";
  for(int z = 0; z<noe; z++)
  {
    if(b_edges[z])
    {
      std::cout<<'('<<e_arr[z]->getVertex0()<<", "<<e_arr[z]->getVertex1()<<')'<<' ';
    }
  }
  std::cout<<'\n';
  delete[] visited;
  delete[] b_edges;
  delete[] traversal;
}

  void Graph::DFS()
{
  bool* visited = new bool[nov];
  bool* t_edges = new bool[noe];
  for(int i=1; i<nov; i++)
  {
    visited[i] = 0;
  }
  for(int j=0; j<noe; j++)
  {
    t_edges[j] = 1;
  }
  visited[1] = 1;
  DFS_recursive(1, visited, t_edges);
  std::cout<<"Tree Edges: ";
  for(int k=0; k<noe; k++)
  {
    if(t_edges[k] == 0)
   {
    std::cout<<'('<<e_arr[k]->getVertex0()<<", "<<e_arr[k]->getVertex1()<<')'<<' ';
   }
  }
  std::cout<<'\n'<<"Back Edges: ";
  for(int z=0; z<noe; z++)
  {
    if(t_edges[z] == 1)
   {
    std::cout<<'('<<e_arr[z]->getVertex0()<<", "<<e_arr[z]->getVertex1()<<')'<<' ';
   }
  }
  std::cout<<'\n';
  delete[] visited;
  delete[] t_edges;
}

  void Graph::DFS_recursive(int current, bool* visited, bool*traversal)
{
  for(int i = 1; i<nov; i++)
  {
    if(visited[i] == 0 && m_arr[current][i] != -1)
    {
      visited[i] = 1;
      for(int k=0; k<noe; k++)
      {
        if(e_arr[k]->getVertex0() == current && e_arr[k]->getVertex1() == i)
        {
          traversal[k] = 0;
        }
      }
      DFS_recursive(i, visited, traversal);
    }
  }
}

  void Graph::Kruskal()
{
  int n_edges = 0;
  bool* minimum = new bool[noe];
  Disjoint* m_set = new Disjoint(noe-1);
  Minheap* m_heap = new Minheap(noe, *(e_arr[0]));
  for(int i=1; i<noe; i++)
  {
    m_heap->insert(*(e_arr[i]));
  }
  for(int j=0; j<noe; j++)
  {
    minimum[j] = 0;
  }
  while(n_edges <= nov-2 && !(m_heap->isEmpty()))
  {
    Edge m_edge = m_heap->PQ_Lowest();
    int vertex0 = m_edge.getVertex0();
    int vertex1 = m_edge.getVertex1();
    if((m_set->Find(vertex0))->getValue() != (m_set->Find(vertex1))->getValue())
    {
      for(int k=0; k<noe; k++)
      {
        if(e_arr[k]->getVertex0() == vertex0 && e_arr[k]->getVertex1() == vertex1)
        {
          minimum[k] = 1;
        }
      }
      m_set->Union(vertex0, vertex1);
      n_edges++;
    }
    else
    {
      m_heap->Delete();
    }
  }
  if(n_edges == (nov-2))
  {
    int index = 0;
    int total = 0;
    for(int k=0; k<noe; k++)
    {
      if(minimum[k] == 1)
      {
        index = k;
        break;
      }
    }
    for(int i=0; i<n_edges; i++)
    {
      for(int j=0; j<noe; j++)
      {
        if(minimum[j] == 1 && e_arr[j]->getDistance() < e_arr[index]->getDistance())
        {
          index = j;
        }
      }
      minimum[index] = 0;
      total = total + e_arr[index]->getDistance();
      std::cout<<'('<<e_arr[index]->getVertex0()<<", "<<e_arr[index]->getVertex1()<<')'<<'{'<<e_arr[index]->getDistance()<<'}'<<' ';
      for(int k=0; k<noe; k++)
      {
        if(minimum[k] == 1)
        {
          index = k;
          break;
        }
      }
    }
    std::cout<<'\n';
    std::cout<<"Total cost: "<<total<<'\n';
  }
  else
  {
    std::cout<<"No such a solution."<<'\n';
  }
  delete m_set;
  delete m_heap;
  delete[] minimum;
}

  void Graph::Prim()
{
  int n_ver = 0;
  bool* temp = new bool[nov];
  int* tree = new int[noe];
  Minheap* m_heap = new Minheap(noe);
  for(int i=1; i<nov; i++)
  {
    temp[i] = 0;
  }
  for(int j=0; j<noe; j++)
  {
    tree[j] = 0;
  }
  temp[1] = 1;
  n_ver = 1;
  for(int k=0; k<noe; k++)
  {
    if(e_arr[k]->getVertex0() == 1 && temp[e_arr[k]->getVertex1()] == 0)
    {
      m_heap->insert(*(e_arr[k]));
    }
  }
  // while(!(m_heap->isEmpty()))
  // {
  //   std::cout<<(m_heap->PQ_Lowest()).getVertex0()<<','<<(m_heap->PQ_Lowest()).getVertex1()<<','<<(m_heap->PQ_Lowest()).getDistance()<<'\n';
  //   m_heap->Delete();
  // }
  Edge min;
  int vertex0 = 0;
  int vertex1 = 0;
  int tracker = 1;
  bool flag = 0;
  while(n_ver != nov-1 && !(m_heap->isEmpty()))
  {
    min = m_heap->PQ_Lowest();
    m_heap->Delete();
    vertex0 = min.getVertex0();
    vertex1 = min.getVertex1();
    if(temp[vertex0] == 1 && temp[vertex1] == 1)
    {
      flag = 1;
    }
    else
   {
    for(int z=0; z<noe; z++)
    {
      if(e_arr[z]->getVertex0() == vertex0 && e_arr[z]->getVertex1() == vertex1)
      {
        tree[z] = tracker;
        tracker++;
      }
    }
   }
   if(!flag)
  {
    n_ver++;
    temp[vertex1] = 1;
    for(int j=0; j<noe; j++)
    {
      if(e_arr[j]->getVertex0() == vertex1 && temp[e_arr[j]->getVertex1()] == 0)
      {
          m_heap->insert(*(e_arr[j]));
      }
      else if(temp[e_arr[j]->getVertex0()] == 0 && e_arr[j]->getVertex1() == vertex1)
      {
        m_heap->insert(*(e_arr[j]));
      }
    }
   }
   else
   {
     flag = 0;
   }
  }
  int max = tracker;
  int total = 0;
  for(int i = 1; i<max; i++)
  {
    for(int k=0; k<noe; k++)
    {
      if(tree[k] == i)
      {
        std::cout<<'('<<e_arr[k]->getVertex0()<<", "<<e_arr[k]->getVertex1()<<')'<<'{'<<e_arr[k]->getDistance()<<'}'<<' ';
        total = total + e_arr[k]->getDistance();
      }
    }
  }
  std::cout<<'\n';
  std::cout<<"Total cost: "<<total<<'\n';
  delete m_heap;
  delete[] temp;
  delete[] tree;
}

  Graph::~Graph()
{
  for(int i=0; i<nov; i++)
  {
    delete[] m_arr[i];
  }
  delete[] m_arr;
  for(int j=0; j<noe; j++)
  {
    delete e_arr[j];
  }
  delete[] e_arr;
}
