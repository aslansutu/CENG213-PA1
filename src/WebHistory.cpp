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

		Node<Tab>* newPage = new Node<Tab>(Tab(url, std::atoi(timestamp.c_str())), NULL, NULL);
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
		Node<Tab>* node = history.getFirstNode();

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
	Node<Tab>* newPage = new Node<Tab>(Tab(url, timestamp), NULL, NULL);
	newPage->next = NULL;
	newPage->prev = NULL;

	history.getHead()->next = newPage;
	history.getTail()->prev = newPage;
}

void WebHistory::insertInOrder(Node<Tab>* newPage)
{
	// TODO
	Node<Tab>* current = this->history.getFirstNode();

	/*If empty*/
	if (current == NULL) {
		this->history.getHead()->next = newPage;
		this->history.getTail()->prev = newPage;

		newPage->next = NULL;
		newPage->prev = NULL;
	}
	else {
		/*if to be first node*/
		if (newPage->element.getTimestamp() >= this->history.getHead()->next->element.getTimestamp()) {
			newPage->next = this->history.getHead()->next;
			newPage->next->prev = newPage;
			this->history.getHead()->next = newPage;
		}
		/*if last node*/
		else if (newPage->element.getTimestamp() < this->history.getTail()->prev->element.getTimestamp()) {
			newPage->next = this->history.getTail();
			newPage->prev = newPage->next->prev;

			this->history.getTail()->prev->next = newPage;
			this->history.getTail()->prev = newPage;
		}
		else {
			/*if in between*/
			while (current) {
				if (newPage->element.getTimestamp() >= current->element.getTimestamp()) {
					this->history.insertAfterGivenNode(newPage->element, current->prev);
					break;
				}
				current = current->next;
			}
		}
	}
}

void WebHistory::goToPage(std::string url, int timestamp)
{
	// TODO
	Node<Tab> *newPage = new Node<Tab>;
	newPage->element.setTimestamp(timestamp);
	newPage->element.setUrl(url);

	newPage->next = NULL;
	newPage->prev = NULL;
	this->insertInOrder(newPage);
}

void WebHistory::clearHistory()
{
	// TODO
	history.removeAllNodes();
}

void WebHistory::clearHistory(int timestamp)
{
	// TODO
	Node<Tab>* current = history.getFirstNode();

	while (current != NULL) {
		if (current->element.getTimestamp() <= timestamp) {
			this->history.removeNode(current);
		}

		current = current->next;
	}
}

WebHistory WebHistory::operator+(const WebHistory& rhs) const
{
	// TODO
	Node<Tab>* hist1 = this->history.getFirstNode();
	Node<Tab>* hist2 = rhs.history.getFirstNode();

	WebHistory cleanSlate;

	while (hist1) {
		cleanSlate.insertInOrder(hist1);
		hist1 = hist1->next;
	}

	while (hist2) {
		cleanSlate.insertInOrder(hist2);
		hist2 = hist2->next;
	}

	return cleanSlate;
}

int WebHistory::timesVisited(std::string pageName)
{
	// BONUS
	int i = 0;

	Node<Tab>* current = this->history.getFirstNode();

	while (current) {
		if (current->element.getWebSite() == pageName) {
			i++;
		}
		current = current->next;
	}

	return i;
}

std::string WebHistory::mostVisited()
{
	// BONUS
	/*Later*/
	return "";
}