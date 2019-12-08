/*
@File Name: LinkedList.cpp
@Author: BoHui Lu
@Assignment: EECS-268 Lab2
@Description: this file define methods in LinkedList.h and ListInterface
@Date: 18/09/2018
*/
#define all methods

template<typename T>
void LinkedList<T>::addFront(T entry)
{
  Node<T>*temp=m_front;
  m_front=new Node<T>();
  m_front->setEntry(entry);
  m_front->setNext(temp);
  m_length=m_length+1;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
 clear();
}

template<typename T>
void LinkedList<T>::addBack(T entry)
{
  Node<T>*temp=m_front;
  T entry1=entry;
  while(temp->getNext()!=nullptr)
    {
      temp=temp->getNext();
    }//while loop...
    temp->setNext(new Node<T>(entry1));
    m_length=m_length+1;
}

template<typename T>
void LinkedList<T>::removeBack()
{
  Node<T>*temp=m_front;
  while(temp->getNext()!=nullptr)
   {
     temp=temp->getNext();
   }//while loop...
   delete temp;
   m_length=m_length-1;
   temp=m_front;
   while(temp->getNext()!=nullptr)
    {
      temp=temp->getNext();
    }//while loop...
    temp->setNext(nullptr);
}

  template<typename T>
bool LinkedList<T>::isEmpty() const
   {
      if(m_length==0)
        {
          return(true);
        }
      else
      {
        return(false);
      }
   }

   template<typename T>
  int LinkedList<T>::getLength() const
    {
      return(m_length);
    }

    template<typename T>
    void LinkedList<T>::insert(int position, T entry) //throw (std::runtime_error)
      {
          Node<T>*temp=m_front;
          if(position<1 && position>m_length+1)
          {
            throw(std::runtime_error("Invalid position"));
          }
          else if(position>1 && position<=m_length)
           {
             Node<T>*temp2=nullptr;
             for(int i=1;i<position-1;i++)
              {
                temp=temp->getNext();
              }//for loop...
              temp2=temp->getNext();
              temp->setNext(new Node<T>(entry));
              temp=temp->getNext();
              temp->setNext(temp2);
              m_length=m_length+1;
           }
           else if(position==1)
           {
              addFront(entry);
           }
           else if(position==m_length+1)
            {
              addBack(entry);
            }
      }


      template<typename T>
      void LinkedList<T>::remove(int position) //throw (std::runtime_error)
      {
         if(position<1 && position>m_length)
          {
            throw(std::runtime_error("Invalid position"));
          }
          else if(position==1)
           {
             Node<T>*temp=m_front;
             m_front=m_front->getNext();
             delete temp;
             m_length=m_length-1;
           }
           else if(position==m_length)
           {
             removeBack();
           }
             else if(position>1 && position<m_length)
              {
                Node<T>*temp=m_front;
                Node<T>*temp2=m_front;
                Node<T>*temp3=nullptr;
                for(int i=1;i<position;i++)
                  {
                    temp=temp->getNext();
                  }//for loop...
                  for(int j=1;j<position-1;j++)
                  {
                    temp2=temp2->getNext();
                  }//for loop...
                   temp3=temp->getNext();
                   temp2->setNext(temp3);
                   delete temp;
                   m_length=m_length-1;
            }
         }


            template<typename T>
            void LinkedList<T>::clear()
            {
              if(isEmpty())
              {

              }
              else
              {
               while(m_front->getNext()!=nullptr)
               {
                 remove(1);
               }
               Node<T>*temp=m_front;
               m_front=nullptr;
               delete temp;
               m_length=m_length-1;
             }
            }

            template<typename T>
            T LinkedList<T>::getEntry(int position) const //throw (std::runtime_error)
            {
              if(position<1 && position>m_length)
              {
                throw(std::runtime_error("Invalid position"));
              }
              else
            {
              Node<T>*temp=m_front;
              for(int i=1;i<position;i++)
                {
                  temp=temp->getNext();
                }//for loop...
                return(temp->getEntry());
            }

          }

          template<typename T>
          void LinkedList<T>::replace(int position, T newEntry) //throw (std::runtime_error)
          {
            if(position<1 && position>m_length)
            {
              throw(std::runtime_error("Invalid position"));
            }
            else
            {
              Node<T>*temp=m_front;
              for(int i=1;i<position;i++)
                {
                  temp=temp->getNext();
                }//for loop...
                temp->setEntry(newEntry);
            }
          }

          template<typename T>
          LinkedList<T>& LinkedList<T>::operator=(const ListInterface<T>& rhs)
        {
          if(isEmpty()==false)
          {
            clear();
          }

         for(int i=1;i<=rhs.m_length;i++)
         {
           this->insert(i,rhs.getEntry(i));
         }
          return((*this));
        }


          template<typename T>
         LinkedList<T>::LinkedList(const LinkedList<T>& original)
         {
           for(int i=1;i<=original.m_length;i++)
           {
             insert(i,original.getEntry(i));
           }
         }

         template<typename T>
         LinkedList<T>::LinkedList()
         {
           m_front=nullptr;
            m_length=0;
        }
