/*
@File Name: LinkedList.h
@Author: BoHui Lu
@Assignment: EECS-268 Lab2
@Description: this file include all the methods in the LinkedList class
@Date: 18/09/2018
*/
#include"ListInterface.h"
#include"Node.h"
template<typename T>
#ifndef LinkedList_H
#define LinkedList_H
     class LinkedList:public ListInterface<T>
        {
           Node<T>*m_front;
           int m_length;
         public:

           /**
           * @all the private members variables are initialized
           **/
           LinkedList();

           /**
           * @pre  The list being passed in has to be empty
           * @post make a deep copy of the origina list
           **/
           LinkedList<T>& operator=(const ListInterface<T>& copyHistory);

           /**
           * @pre  The list being passed in has to be empty
           * @post make a deep copy of the origina list
           **/
           LinkedList(const LinkedList<T>& original);

           /**
           * @check whether the list is empty or not
           **/
           bool isEmpty() const;

           /**
           * @return the length of the list
           **/
           int getLength() const;

           /**
           * @pre The position is between 1 and the list's length+1
           * @post The new Node object is created at the given position with the new entry
           * @param position:  1<= position <= length+1
           * @param newEntry: A new entry to put in the list
           * @throw std::runtime_error if the position is invalid.
           **/
           void insert(int position, T entry); //throw (std::runtime_error);

           /**
           *@pre The position is between 1 and the list's length
           * @post The entry at the given position is removed
           * @param position:  1<= position <= length
           * @throw std::runtime_error if the position is invalid.
           **/
           void remove(int position); //throw (std::runtime_error);

           /**
           * @pre The LinkedList that calls this method must not be empty
           * @post All the information stored in the Node objects in the LinkedList is now being removed
           **/
           void clear();

           /**
           * @pre The position is between 1 and the list's length
           * @post return the value storing in the Node at the given position
           * @param position:  1<= position <= length
           * @throw std::runtime_error if the position is invalid.
           **/
           T getEntry(int position) const; //throw (std::runtime_error);

           /**
           * @pre The position is between 1 and the list's length
           * @post The entry at the given position is replaced with the new entry
           * @param position:  1<= position <= length
           * @param newEntry: A new entry to put in the list
           * @throw std::runtime_error if the position is invalid.
           **/
           void replace(int position, T newEntry); //throw (std::runtime_error);

           /**
           * @pre The position the entry to be put in has be 1
           * @post The first Node store the new entry, and the front pointer now pointing to the new Node
           * @param Entry: A new entry to put in the list
           **/
           void addFront(T entry);

           /**
           * @pre The position the entry to be put in has be list's length+1
           * @post A new node in the very end is created, and it stores the new entry.
           * @param Entry: A new entry to put in the list
           **/
           void addBack(T entry);
           /**
           * @pre The list can not be empty
           * @post The Node at the end of list will be removed
           **/
           void removeBack();

           /**
           * @Clearing the list
           **/
           ~LinkedList();
        };
          #include"LinkedList.cpp"
          #endif
