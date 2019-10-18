#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
    public: // DO NOT CHANGE THIS PART.
        LinkedList();
        LinkedList(const LinkedList &obj);

        ~LinkedList();

        Node<T> *getFirstNode() const; //
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        int getNumberOfNodes();
        bool isEmpty(); //

        void insertAtTheFront(const T &data); //
        void insertAtTheEnd(const T &data); //
        void insertAfterGivenNode(const T &data, Node<T> *prev); //

        void removeNode(Node<T> *node);
        void removeAllNodes();

        Node<T> *findNode(const T &data); //

        void printAllNodes();
        void printReversed();

        LinkedList &operator=(const LinkedList &rhs);

    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

    private: // DO NOT CHANGE THIS PART.
        Node<T> *head;
        Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
}

template<class T>
int LinkedList<T>::getNumberOfNodes() 
{
    /* TODO */
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    /* TODO */
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    /* TODO */
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{   
    /* TODO */
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */
}

template<class T>
void LinkedList<T>::printAllNodes()
{
    /* TODO */
}

template<class T>
void LinkedList<T>::printReversed()
{
    /* TODO */
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    /* TODO */
}

#endif //LINKED_LIST_HPP
