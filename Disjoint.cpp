#include "Disjoint.h"


  Disjoint::Disjoint(int t_size)
{
  size = t_size;
  m_arr = new Node_set*[size+1];
  for(int i=1; i<=size; i++)
  {
    m_arr[i] = new Node_set(i);
  }
}


  void Disjoint::Union(int value_0, int value_1)
{
  Node_set* u_1 = Find(value_0);
  Node_set* u_2 = Find(value_1);
  if(u_1 == nullptr || u_2 == nullptr)
  {
    //std::cout<<">Output: "<<value_0<<" and "<<value_1<<" can not be merged because one of the key enter does not exist on the Disjoint sets."<<'\n';
    return;
  }
  if(u_1->getValue() == u_2->getValue())
  {
    //std::cout<<">Output: "<<value_0<<" and "<<value_1<<" have the same representative. The representative element is "<<u_1->getValue()<<'.'<<'\n';
  }
  else if(u_1->getRank() < u_2->getRank())
  {
    u_1->setParent(u_2);
    //std::cout<<">Output: "<<value_0<<" and "<<value_1<<" have been merged. The representative element is "<<u_2->getValue()<<'.'<<'\n';
  }
  else if(u_1->getRank() == u_2->getRank())
  {
    u_1->setRank(u_1->getRank()+1);
    u_2->setParent(u_1);
    //std::cout<<">Output: "<<value_0<<" and "<<value_1<<" have been merged. The representative element is "<<u_1->getValue()<<'.'<<'\n';
  }
  else
  {
    u_2->setParent(u_1);
    //std::cout<<">Output: "<<value_0<<" and "<<value_1<<" have been merged. The representative element is "<<u_1->getValue()<<'.'<<'\n';
  }
}

  Node_set* Disjoint::Find(int key)
{
  Node_set* Ptr = Search_key(key);
  if(Ptr == nullptr)
  {
    std::cout<<">Ouput: Sorry, "<<key<<" is not found!"<<'\n';
  }
  else
  {
   while(1)
   {
    if((Ptr->getParent())->getValue() == Ptr->getValue())
    {
      break;
    }
    else
    {
      Ptr = Ptr->getParent();
    }
   }
  }
  return(Ptr);
}

  Node_set* Disjoint::Search_key(int key)
{
  Node_set* Ptr = nullptr;
  for(int i=1; i<=size; i++)
  {
    if(m_arr[i]->getValue() == key)
    {
      Ptr = m_arr[i];
      break;
    }
  }
  return(Ptr);
}

  int Disjoint::Find_ex(int key, bool& flag)
{
  Node_set* Ptr = Search_key(key);
  if(Ptr == nullptr)
  {
   std::cout<<">Ouput: Sorry, "<<key<<" is not found!"<<'\n';
   return(0);
  }
  else
  {
    flag = 1;
    while(1)
    {
      if((Ptr->getParent())->getValue() == Ptr->getValue())
      {
        break;
      }
       else
      {
        Ptr = Ptr->getParent();
      }
     }
   }
   return(Ptr->getValue());
}

  void Disjoint::PathCompression(int tobe_compress)
{
  Node_set* Ptr = Search_key(tobe_compress);
  Node_set* rep = nullptr;
  Node_set* Parent = Ptr;
  while((Ptr->getParent())->getValue() != Ptr->getValue())
  {
      Ptr = Ptr->getParent();
   }
   rep = Ptr;
   Ptr = Parent;
   while(rep->getValue() != Ptr->getValue())
   {
     Parent = Ptr->getParent();
     Ptr->setParent(rep);
     Ptr = Parent;
   }
   std::cout<<">Output: Path compression has been done successfully."<<'\n';
}

  void Disjoint::Start_expriment()
{
  for(int i=1; i<=size; i=i+2)
  {
    Union(i, i+1);
  }
  for(int i=3; i<=100; i=i+2)
  {
    Union(2, i);
  }
  for(int i=103; i<=200; i=i+2)
  {
    Union(101, i);
  }
  for(int i=203; i<=300; i=i+2)
  {
    Union(201, i);
  }
  for(int i=303; i<=400; i=i+2)
  {
    Union(301, i);
  }
  for(int i=403; i<=500; i=i+2)
  {
    Union(401, i);
  }
  for(int i=503; i<=600; i=i+2)
  {
    Union(501, i);
  }
  for(int i=603; i<=700; i=i+2)
  {
    Union(601, i);
  }
  for(int i=703; i<=800; i=i+2)
  {
    Union(701, i);
  }
  for(int i=803; i<=900; i=i+2)
  {
    Union(801, i);
  }
  for(int i=903; i<=1000; i=i+2)
  {
    Union(901, i);
  }
  Union(2, 102);
  Union(202, 302);
  Union(402, 502);
  Union(602, 702);
  Union(802, 902);
  Union(2, 202);
  Union(402, 602);
  Union(2, 802);
  Union(2, 402);
}

 Disjoint::~Disjoint()
{
  for(int i=1; i<=size; i++)
  {
    delete m_arr[i];
  }
  delete[] m_arr;
}
