/*
@File Name: Queue.h
@Author: BoHui Lu
@Assignment: EECS-268 Lab3
@Description: this file includes all the methods in the Queue class
@Date: 25/09/2018
*/
#include"QueueInterface.h"
#include"LinkedList.h"
#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue:public QueueInterface<T>

{
  private:
      LinkedList<T>*m_list;

  public:

    /**
    * @initialize the LinkedList pointer under the private scope pointing to a LinkedList object
    */

    Queue();

    /**
    * @Destruct the object that is heap allocated in the private scope
    */

    ~Queue();

   /** Sees whether this queue is empty.
    @return True if the queue is empty, or false if not.
    */

   bool isEmpty() const;

   /** Adds a new entry to the back of this queue.
    @post If the operation was successful, newEntry is at the back of the queue.
    @param newEntry  The object to be added as a new entry.
    @throw PrecondViolatedExcep if no memory available for the new item
    */

   void enqueue(const T& newEntry);

   /** Removes the front of this queue.
    @post If the operation was successful, the front of the queue has been removed.
    @throw PrecondViolatedExcep if the queue is empty when called
    */

   void dequeue();

   /** Returns the front of this queue.
    @pre The queue is not empty.
    @post The front of the queue has been returned, and the queue is unchanged.
    @throw PrecondViolatedExcep if the queue is empty when called
    */

   T peekFront() const;

};
#include"Queue.cpp"
#endif
