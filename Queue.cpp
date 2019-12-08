/*
@File Name: Queue.cpp
@Author: BoHui Lu
@Assignment: EECS-268 Lab3
@Description: this file defines all the methods in the Queue class
@Date: 25/09/2018
*/
#define all methods

template<typename T>
Queue<T>::Queue()
{
  m_list=new LinkedList<T>();
}

template<typename T>
  bool Queue<T>::isEmpty() const
{
  if(m_list->isEmpty())
   {
     return(1);
   }
   else
   {
     return(0);
   }
}

template<typename T>
void Queue<T>::enqueue(const T& newEntry)
{
    if(m_list->getLength()==0)
    {
      m_list->insert(1,newEntry);
    }
    else
    {
      m_list->insert(m_list->getLength()+1,newEntry);
    }
}

template<typename T>
void Queue<T>::dequeue()
{
  m_list->remove(1);
}

template<typename T>
T Queue<T>::peekFront() const
{
  return(m_list->getEntry(1));
}

template<typename T>
Queue<T>::~Queue()
{
  delete m_list;
}
