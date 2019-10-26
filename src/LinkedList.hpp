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
    /*Allocate Space*/
    this->head = new Node<T>;
    this->tail = new Node<T>;

    /*Assign pointers*/
    this->head->next = this->getTail();
    this->tail->prev = this->getHead();

    this->head->prev = NULL;
    this->tail->next = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
    this->head = new Node<T>;
    this->head->prev = NULL;

    Node<T> *traverseObj = obj.getHead()->next;
    Node<T> *current = this->getHead();

    while (traverseObj != NULL){
        current->next = new Node<T>(traverseObj->element, current, NULL);
        current = current->next;
        traverseObj = traverseObj->next;
    }
    this->tail = new Node<T>;
    this->tail->next = NULL;

    current->next = this->tail;
    this->tail->prev = current;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    Node<T> *current = this->getHead();
    Node<T> *nextPtr;

    while (current != NULL){
        nextPtr = current->next;
        delete current;
        current = nextPtr;
    }
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if (this->head->next == this->tail){
        return NULL;
    }
    else{
        return this->head->next;
    }

}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
    return this->head;
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
    return this->tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() 
{
    /* TODO */
    int i = 0;

    Node<T> *current = this->head->next;

    while (current != this->tail){
        i++;
        current = current->next;
    }

    return i;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    /* TODO */
    if (this->head->next == this->tail){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    /* TODO */
    Node<T> *toInsert = new Node<T>(data, this->head, this->head->next);
    this->head->next = toInsert;
    toInsert->next->prev = toInsert;
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
    Node<T> *toInsert = new Node<T>(data, this->tail->prev, this->tail);
    toInsert->prev->next = toInsert;
    this->tail->prev = toInsert;
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{   
    /* TODO */
    Node<T> *toInsert = new Node<T>(data, prev, prev->next);
    toInsert->prev->next = toInsert;
    toInsert->next->prev = toInsert;
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    /*Reassign links*/
    node->prev->next = node->next;
    node->next->prev = node->prev;

    /*Deallocate node memory*/
    node->prev = node->next = NULL;
    delete node;
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    Node<T> *current = this->head->next;
    Node<T> *nextPtr;

    while (current != this->tail){
            nextPtr = current->next;
            this->removeNode(current);
            current = nextPtr;
    }
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */
    Node<T> *current = this->head->next;

    while (current != this->tail){
        if (current->element == data){
            return current;
        }

        current = current->next; 
    }

    return NULL;
}

template<class T>
void LinkedList<T>::printAllNodes()
{
    /* TODO */
    Node<T> *current = this->head->next;

    while (current != this->tail){
        std::cout << current->element << std::endl;
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::printReversed()
{
    /* TODO */
    Node<T> *current = this->tail->prev;

    while (current != this->head){
        std::cout << current->element << std::endl;
        current = current->prev;
    }
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    /* TODO */
    this->removeAllNodes();

    Node<T> *rhsCurrent = rhs.getHead()->next;
    Node<T> *current = this->head;

    while (rhsCurrent != rhs.getTail()){
        current->next = new Node<T>(rhsCurrent->element, current, NULL);
        current = current->next;
        rhsCurrent = rhsCurrent->next;
    }

    this->tail->prev = current;
    current->next = this->tail;

}

#endif //LINKED_LIST_HPP
