/*
@File Name: Node.cpp
@Author: BoHui Lu
@Assignment: EECS-268 Lab2
@Description: this file define all the methods in the Node.h file
@Date: 18/09/2018
*/
#define all methods

template<typename T>
T Node<T>::getEntry() const
  {
    return(m_entry);
  }

template<typename T>
Node<T>* Node<T>::getNext()
{
  return(m_next);
}

template<typename T>
void Node<T>::setEntry(T value)
  {
    m_entry=value;
  }

template<typename T>
void Node<T>::setNext(Node<T>*next)
  {
    m_next=next;
  }

template<typename T>
Node<T>::Node(T entry)
{
  m_entry=entry;
  m_next=nullptr;
}

template<typename T>
Node<T>::Node()
{
  m_next=nullptr;
}
