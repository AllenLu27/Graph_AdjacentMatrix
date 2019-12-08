/*
@File Name: ListInterface.h
@Author: BoHui Lu
@Assignment: EECS-268 Lab2
@Description: this file include all the virtual methods in the ListInterface class
@Date: 18/09/2018
*/
#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H
#include<stdexcept>

template <typename T>
class ListInterface
{

     public:

     /**
     * @post All memory allocated by the implementing class should be freed.
     *       This, as with all virtual destrucors, is an empty definition since we
     *       have no knowledge of specific implementation details.
     */
     virtual ~ListInterface(){}

     /**
     * @check whether the list is empty or not
     **/

     virtual bool isEmpty() const = 0;

     /**
     * @return the length of the list
     **/
     virtual int getLength() const = 0;
     /**
     * @pre The position is between 1 and the list's length+1
     * @post The new Node object is created at the given position with the new entry
     * @param position:  1<= position <= length+1
     * @param newEntry: A new entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual void insert(int position, T entry) = 0; //throw (std::runtime_error) = 0;

     /**
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is removed
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual void remove(int position) = 0;//throw (std::runtime_error) = 0;

     /**
     * @pre The LinkedList that calls this method must not be empty
     * @post All the information stored in the Node objects in the LinkedList is now being removed
     **/
     virtual void clear() = 0;

     /**
     * @pre The position is between 1 and the list's length
     * @post return the value storing in the Node at the given position
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual T getEntry(int position) const = 0;//throw (std::runtime_error) = 0;

     /**
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is replaced with the new entry
     * @param position:  1<= position <= length
     * @param newEntry: A new entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual void replace(int position, T newEntry) = 0;//throw (std::runtime_error) = 0;
};

#endif
