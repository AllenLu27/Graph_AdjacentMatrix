#include "Executive.h"

Executive::Executive(std::string filename)
{
  int** despcrition;
  m_graph = nullptr;
  std::ifstream infile;
  int UserChoice = 0;
  int size = 0;
  int m_num = 0;
  int matrix = 0;
  int count = 0;
  infile.open(filename);
  if(infile.is_open())
  {
    infile>>size;
    matrix = size+1;
    despcrition = new int*[matrix];
    for(int k=0; k<matrix; k++)
    {
      despcrition[k] = new int[matrix];
    }
    for(int i=1; i< matrix; i++)
   {
     for(int j=1; j< matrix; j++)
    {
      infile>>m_num;
      despcrition[i][j] = m_num;
      if(m_num != -1 && m_num != 1)
      {
        count++;
      }
    }
   }
  }
  infile.close();
  m_graph = new Graph(despcrition, matrix, count);
  std::cout<<'\n'<<'\n'<<'\n';
  while(1)
  {
    std::cout<<"Please choose one of the following commands:"<<'\n'<<'\n';
    std::cout<<"6- BFS"<<'\n'<<"7- DFS"<<'\n'<<"8- Kruskal MST"<<'\n';
    std::cout<<"9- Prim MST"<<'\n'<<"10- Exit"<<'\n'<<'\n'<<">Enter your choice:"<<'\n'<<'>';
    std::cin>>UserChoice;
    if(UserChoice == 6)
    {
      m_graph->BFS();
    }
    else if(UserChoice == 7)
    {
      m_graph->DFS();
    }
    else if(UserChoice == 8)
    {
      m_graph->Kruskal();
    }
    else if(UserChoice == 9)
    {
      m_graph->Prim();
    }
    else
    {
      break;
    }
    std::cout<<'\n'<<'\n';
  }
  std::cout<<"Bye Bye!"<<'\n'<<'\n';
}

  Executive::~Executive()
{
  if(m_graph!=nullptr)
  {
    delete m_graph;
  }
}
