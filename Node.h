/*
@File Name: Node.h
@Author: BoHui Lu
@Assignment: EECS-268 Lab2
@Description: this file include all the methods in the Node class
@Date: 18/09/2018
*/
template<typename T>
#ifndef NODE_H
#define NODE_H

               class Node
            {
                T m_entry;
                Node<T>*m_next;

                public:

                 /**
                 * @return the entry stored in the Node
                 */
                 T getEntry() const;

                 /**
                 * @return the the memory address the private member variables Node pointer is point to
                 */
                 Node<T>*getNext();

                 /**
                 * @pre none
                 * @post the value will be stored in a Node object
                 * @param value, a template value representing any type of entry can be stored in the Node
                 */
                 void setEntry(T value);

                  /**
                  * @pre none
                  * @post set the pointer in one Node pointing to the memory address another Node pointer is pointing to
                  * @param next, a Node pointer representing a memory address it is pointing to
                  */
                  void setNext(Node<T>*next);

                  /**
                  * @private member variables under the Node class scope is initialized with the entry
                  */
                  Node(T entry);

                  /**
                  * @private member variables under the Node class scope is initialized
                  */
                  Node();
               };
         #include"Node.cpp"
         #endif
