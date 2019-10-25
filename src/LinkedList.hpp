#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
	LinkedList();
	LinkedList(const LinkedList& obj);

	~LinkedList();

	Node<T>* getFirstNode() const; //
	Node<T>* getHead() const;
	Node<T>* getTail() const;
	int getNumberOfNodes();
	bool isEmpty(); //

	void insertAtTheFront(const T& data); //
	void insertAtTheEnd(const T& data); //
	void insertAfterGivenNode(const T& data, Node<T>* prev); //

	void removeNode(Node<T>* node);
	void removeAllNodes();

	Node<T>* findNode(const T& data); //

	void printAllNodes();
	void printReversed();

	LinkedList& operator=(const LinkedList& rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
	Node<T>* head;
	Node<T>* tail;
};

template<class T>
LinkedList<T>::LinkedList()
{
	/* TODO */
	this->head = new Node<T>();
	this->tail = new Node<T>();

	this->head->next = this->tail;
	this->tail->prev = this->head;

	this->head->prev = NULL;
	this->tail->next = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& obj)
{
	/* TODO */
	Node<T>* current = obj.getFirstNode();
	LinkedList<T> newList;
	Node<T>* newListTraverse = newList.head;


	while (current != obj.tail && current) {
		newList.insertAtTheEnd(current->element);
		current = current->next;
		newListTraverse = newListTraverse->next;
	}

	newListTraverse->next = NULL;
	newList.tail->prev = newListTraverse;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	/* TODO */
	Node<T> *current = this->getFirstNode();
	Node<T>* nextNode;

	while (current) {
		nextNode = current->next;
		delete current;
		current = nextNode;
	}

	this->head = NULL;
	this->tail = NULL;
}

template<class T>
Node<T>* LinkedList<T>::getFirstNode() const
{
	/* TODO */
	if (head->next == tail) {
		return NULL;
	}
	else {
		return head->next;
	}
}

template<class T>
Node<T>* LinkedList<T>::getHead() const
{
	/* TODO */
	return this->head;
}

template<class T>
Node<T>* LinkedList<T>::getTail() const
{
	/* TODO */
	return this->tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes()
{
	/* TODO */
	int i = 0;
	Node <T>* current = this->getHead()->next;

	while (current) {
		current = current->next;
		i++;
	}
	return i;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
	/* TODO */
	if (this->getHead()->next == this->getTail()) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T& data)
{
	/* TODO */
	Node <T>* newNode;

	newNode->element = data;

	if (this->isEmpty()) {
		newNode->prev = NULL;
		newNode->next = NULL;

		this->head->next = newNode;
		this->tail->prev = newNode;
	}
	else {
		newNode->next = this->getFirstNode();
		this->getFirstNode()->prev = newNode;
		this->getHead()->next = newNode;
		newNode->prev = NULL;
	}
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T& data)
{
	/* TODO */
	Node <T>* newNode = new Node<T>(data, NULL, NULL);

	if (this->isEmpty()) {
		newNode->prev = NULL;
		newNode->next = NULL;

		this->head->next = newNode;
		this->tail->prev = newNode;
	}
	else {
		newNode->prev = this->tail->prev;
		this->tail->prev->next = newNode;
		newNode->next = NULL;
		this->tail->prev = newNode;
	}
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T& data, Node<T>* prev)
{
	/* TODO */
	Node<T>* newNode = new Node<T>(data, NULL, NULL);

	/*if prev == last node*/
	if (prev->next == NULL) {
		newNode->prev = this->tail->prev;
		this->tail->prev->next = newNode;
		newNode->next = NULL;
		this->tail->prev = newNode;
	}
	else {
		newNode->next = prev->next;
		newNode->prev = prev;
		prev->next = newNode;
		newNode->next->prev = newNode;
	}
}

template<class T>
void LinkedList<T>::removeNode(Node<T>* node)
{
	/* TODO */
	/*Check if first node*/
	if (head->next == node) {
		head->next = head->next->next;
	}
	/*Check if last node*/
	else if (tail->prev == node) {
		node->prev->next = NULL;
		tail->prev = node->prev;
	}
	else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	delete node;
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
	/* TODO */
	this->head->next = this->getTail();
	this->tail->prev = this->getHead();
}

template<class T>
Node<T>* LinkedList<T>::findNode(const T& data)
{
	/* TODO */
	Node<T>* tmp = this->head->next;

	while (tmp != tail && tmp != NULL) {
		if (tmp->element == data) {
			return tmp;
		}
		tmp = tmp->next;
	}

	return NULL;
}

template<class T>
void LinkedList<T>::printAllNodes()
{
	/* TODO */
	Node <T>* current = this->head->next;

	if (current != getTail()) {
		while (current) {
			std::cout << current->element << std::endl;
			current = current->next;
		}
	}
}

template<class T>
void LinkedList<T>::printReversed()
{
	/* TODO */
	Node <T> current = tail->prev;

	if (current != getHead()) {
		while (current) {
			std::cout << current->element << std::endl;
			current = current->prev;
		}
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
{
	/* TODO */
	Node <T>* traverse = rhs.getFirstNode();
	this.removeAllNodes();

	while (traverse != NULL && traverse != rhs.getTail()) {
		this->insertAtTheEnd(&traverse.element);
		traverse = traverse->next;
	}
}

#endif //LINKED_LIST_HPP
