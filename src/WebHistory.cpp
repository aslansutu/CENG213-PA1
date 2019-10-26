#include "WebHistory.hpp"

WebHistory::WebHistory()
{
    // Does nothing.
}

WebHistory::WebHistory(std::string historyText)
{
	// history = url timestamp | url timestamp | url timestamp...
    // urls are string and timestamps are non-negative integers.
    std::string delimiter = " | ";

	std::string tabInfo;
    std::string url;
    std::string timestamp;
    size_t pos = 0;

    while (true)
	{
        pos = historyText.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        tabInfo = historyText.substr(0, pos);
        historyText.erase(0, pos + delimiter.length());

        pos = tabInfo.find(" ");
        
        url = tabInfo.substr(0, pos);
        timestamp = tabInfo.substr(pos + 1, tabInfo.length() - pos);

		Node<Tab> *newPage = new Node<Tab>(Tab(url, std::atoi(timestamp.c_str())), NULL, NULL);
        insertInOrder(newPage);

        if (breakTheLoop)
		{
			break;
		}
    }
}

void WebHistory::printHistory()
{
	std::cout << "Your web history:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
	if (history.getHead()->next == history.getTail())
	{
		std::cout << "History is empty." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		Node<Tab> *node = history.getFirstNode();
		
		while (node != history.getTail())
		{
		    std::cout << "Page: " << node->element.getUrl() << std::endl;
			std::cout << "Last Visited: " << node->element.getTimestamp() << std::endl;
			std::cout << std::endl;
		    node = node->next;
		}
	}
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

WebHistory::WebHistory(std::string url, int timestamp)
{
	// TODO
	Node<Tab> *newPage = new Node<Tab>;
	this->insertInOrder(newPage);
	this->history.getHead()->prev = NULL;
	this->history.getTail()->next = NULL;
}

WebHistory::~WebHistory()
{
	// TODO
	Node<Tab> *currentPage = this->history.getHead()->next;
	Node<Tab> *nextPage;

	while (currentPage != this->history.getTail()){
		nextPage = currentPage->next;
		delete currentPage;
		currentPage = nextPage;
	}
}

void WebHistory::insertInOrder(Node<Tab> *newPage)
{
	// TODO
	Node<Tab> *currentPage = this->history.getHead()->next;
	/*if history is empty*/
	if (this->history.isEmpty()){
		this->history.insertAtTheFront(newPage->element);
	}
	/*if is first element is history*/
	else if (newPage->element.getTimestamp() >= this->history.getFirstNode()->element.getTimestamp()){
		this->history.insertAtTheFront(newPage->element);
	}
	/*if is last element in history*/
	else if (newPage->element.getTimestamp() < this->history.getTail()->prev->element.getTimestamp()){
		this->history.insertAtTheEnd(newPage->element);
	}
	/*if is in between*/ 
	else{
		while (currentPage->element.getTimestamp() >= newPage->element.getTimestamp()){
			currentPage = currentPage->next;
		}
		this->history.insertAfterGivenNode(newPage->element, currentPage->prev);
	}
}

void WebHistory::goToPage(std::string url, int timestamp)
{
	// TODO
	Node<Tab> *newPage = new Node<Tab>(Tab(url, timestamp), NULL, NULL);
	this->insertInOrder(newPage);
}

void WebHistory::clearHistory()
{
	// TODO
	this->history.removeAllNodes();
}

void WebHistory::clearHistory(int timestamp)
{
	// TODO
	Node<Tab> *currentPage = this->history.getHead()->next;

	while (currentPage != this->history.getTail()){
		if (currentPage->element.getTimestamp() <= timestamp){
			currentPage = currentPage->prev;
			this->history.removeNode(currentPage->next);
		}
		currentPage = currentPage->next;
	}
}

WebHistory WebHistory::operator+(const WebHistory &rhs) const
{
	// TODO
	WebHistory cleanSlate;

	LinkedList<Tab> hist1 = this->history;
	LinkedList<Tab> hist2 = rhs.history;

	Node<Tab> *current1 = hist1.getHead()->next;
	Node<Tab> *current2 = hist2.getHead()->next;

	while (current1 != hist1.getTail()){
		cleanSlate.insertInOrder(current1);
		current1 = current1->next;
	}

	while (current2 != hist2.getTail()){
		cleanSlate.insertInOrder(current2);
		current2 = current2->next;
	}

	return cleanSlate;
}

int WebHistory::timesVisited(std::string pageName)
{
	// BONUS
	int i = 0;
	Node<Tab> *currentPage = this->history.getHead()->next;

	while (currentPage != this->history.getTail()){
		if (currentPage->element.getWebSite() == pageName){
			i++;
		}
		currentPage = currentPage->next;
	}
	return i;
}

std::string WebHistory::mostVisited()
{
	// BONUS
	return "";
}